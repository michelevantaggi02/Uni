#include <bits/time.h>
#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

// FLAGS
char controlla_stallo = 0, soluzione_stallo = 0, controlla_starvation = 0;

int filosofi;
pid_t pid;
sem_t **semafori;
sem_t *in_attesa;

/**
 * Alla ricezione del segnale SIGINT si chiudono soltanto i child
 * A chiudere i semafori ci penserà il parent
 */
void HandlerChiusura(int codice) {
  printf("CHIAMATO HANDLER SIGINT %d\n", getpid());

  if (!pid) {
    printf("Child che termina %d\n", getpid());

    exit(0);
  } else {
    return;
  }
}

/**
 * Processo child
 */
void child(int i) {
  sleep(1);
  printf("child %d con parent %d\n", getpid(), getppid());
  fflush(stdout);
  int prima, seconda;

  // come scritto sulla traccia
  // l'ultimo filosofo prende la prima la forchetta a sinistra così da evitare
  // lo stallo
  if (soluzione_stallo && i == (filosofi - 1)) {

    prima = (i + 1) % filosofi;
    seconda = i;

  } else {
    prima = i;
    seconda = (i + 1) % filosofi;
  }

  while (1) {

    printf("Il filosofo %d cerca di prendere la forchetta %d\n", i, prima);

    //utilizza un timedwait al posto di un wait normale per controllare la starvation
    if (controlla_starvation) {
      struct timespec ts;
      clock_gettime(CLOCK_REALTIME, &ts);
      ts.tv_sec += 8;

      int ret = sem_timedwait(semafori[prima], &ts);

      if (ret == -1) {
        printf("IL FILOSOFO %d E' MORTO DI FAME\n", i);
        kill(getppid(), SIGINT);
        return;
      }
    } else {
      sem_wait(semafori[prima]);
    }

    printf("Il filosofo %d ha preso la forchetta %d\n", i, prima);

    printf("Il filosofo %d cerca di prendere la forchetta %d\n", i, seconda);

    //uso un semaforo per tenere il conto di quanti filosofi hanno 1 sola forchetta
    if (controlla_stallo) {
      sem_post(in_attesa);
      int valore;
      sem_getvalue(in_attesa, &valore);

      if (valore == filosofi) {
        printf("STALLO RILEVATO\n");
        killpg(0, SIGINT);
        return;
      }
    }

    if (controlla_starvation) {
      struct timespec ts;
      clock_gettime(CLOCK_REALTIME, &ts);
      ts.tv_sec += 8;
      int ret = sem_timedwait(semafori[seconda], &ts);
      if (ret == -1) {
        printf("IL FILOSOFO %d E' MORTO DI FAME\n", i);
        kill(getppid(), SIGINT);
        return;
      }
    } else {
      sem_wait(semafori[seconda]);
    }

    //abbasso il semaforo per segnalare che ha lasciato le forchette
    if (controlla_stallo) {
      sem_wait(in_attesa);
    }

    printf("Il filosofo %d ha mangiato\n", i);

    sem_post(semafori[prima]);

    int valore_destra;

    sem_getvalue(semafori[prima], &valore_destra);

    printf("Il filosofo %d ha lasciato la forchetta %d, valore = %d\n", i, i,
           valore_destra);

    sem_post(semafori[seconda]);

    int valore_sinistra;

    sem_getvalue(semafori[seconda], &valore_sinistra);
    printf("Il filosofo %d ha lasciato la forchetta %d, valore = %d\n", i,
           seconda, valore_sinistra);
  }
}

/**
* Processo parent
*/
void parent() {
  int wstatus;

  for (int j = 0; j < filosofi; j++) {

    wait(&wstatus); 

    if (WIFEXITED(wstatus))
      printf("Il child è terminato normalmente. Exit status del child = %d\n",
             WEXITSTATUS(wstatus));
    else if (WIFSIGNALED(wstatus))
      printf("Il child è stato terminato da un signal %s\n",
             strsignal(WTERMSIG(wstatus)));
    else
      printf("Il child NON è terminato normalmente!!!\n");

    printf("Numero child che devono terminare: %d\n", filosofi - j - 1);
  }
  printf("TUTTI I CHILD DI %d SONO TERMINATI\n", getpid());

  // chiudo i semafori
  char *nome_semaforo;
  for (int j = 0; j < filosofi; j++) {
    asprintf(&nome_semaforo, "/forchetta_%d", j);
    sem_close(semafori[j]);
    sem_unlink(nome_semaforo);
    printf("ho chiuso %s\n", nome_semaforo);
  }
  sem_close(in_attesa);
  sem_unlink("/attesa");

  free(semafori);
}

int main(int argc, char **args) {

  //Handler per il segnale SIGINT
  struct sigaction sig;
  memset(&sig, '\0', sizeof(struct sigaction));
  sig.sa_handler = HandlerChiusura;
  sig.sa_flags = SA_RESTART;
  sigaction(SIGINT, &sig, NULL);

  if (argc >= 2) {
    filosofi = atoi(args[1]);

    //controllo la presenza di flag
    for (int i = 2; i < argc; i++) {
      if (!strcmp(args[i], "-s")) {
        controlla_stallo = 1;
        printf("RILEVAZIONE STALLO ATTIVATA\n");
      } else if (!strcmp(args[i], "-sol")) {
        soluzione_stallo = 1;
        printf("SOLUZIONE ANTI-STALLO ATTIVATA\n");
      } else if (!strcmp(args[i], "-star")) {
        controlla_starvation = 1;
        printf("RILEVAZIONE STARVATION ATTIVATA\n");
      }
    }

  } else {
    printf("Usage: %s n-filosofi [FLAGS]\n\n", args[0]);
    printf("n-filosofi\tintero maggiore di 1\n\n");
    printf("FLAGS:\n");
    printf("\t-s\tControlla stallo\n");
    printf("\t-sol\tAbilita soluzione stallo\n");
    printf("\t-star\tColtrolla starvation\n");
    return 1;
  }

  if (filosofi < 2) {

    printf("%d filosofi sono minori di 2\n", filosofi);

    return 1;
  }

  printf("%d\n", filosofi);

  semafori = malloc(sizeof(sem_t) * filosofi);
  in_attesa = sem_open("/attesa", O_CREAT, S_IRWXU, 0);

  int i;

  for (i = 0; i < filosofi; i++) {
    char *nome_semaforo;
    asprintf(&nome_semaforo, "/forchetta_%d", i);
    semafori[i] = sem_open(nome_semaforo, O_CREAT, S_IRWXU, 1);
  }

  for (i = 0; i < filosofi; i++) {
    pid = fork();

    if (pid == 0) {
      break;
    }
  }

  switch (pid) {
  case -1:
    printf("Errore fork\n");
    return 1;
    break;
  case 0:
    child(i);
    return 0;
    break;
  default:
    parent();
    break;
  }
  return 0;
}