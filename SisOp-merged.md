# 1. Sistema operativo

Il sistema operativo è un programma che si occupa di gestire gli altri programmi creando un'interfaccia tra hardware e software.

# Hardware

- processore
- memoria
- meccanismi che collegano processore e memoria (BUS)

# Software

- sistema operativo
- interfaccia binaria per le applicazioni

# Servizi Del Sistema Operativo

- creazione dei programmi
- esecuzione dei programmi
- accesso ai dispositivi IO
- accesso controllato ai file
- accesso al sistema
- rilevazione degli errori e risposta
- contabilità

## Interfaccia

- ISA instruction set architecture
- ABI Application Binary Interface
- API Application Programming Interface

# Evoluzione

Il sistema operativo nel tempo si evolve venendo aggiornato per supportare nuovi tipi di hardware, nuovi servizi e per correggere degli errori.

## Prima Generazione

I primi calcolatori utilizzavano delle valvole per la gestione delle informazioni, non avevano un sistema operativo e il controllo era tramite console. Avevano enormi problemi di schedulazione in quanto ogni cosa doveva essere gestita dal programmatore (non c'era un sistema operativo) e occorreva un lungo tempo di preparazione

## Seconda Generazione

Iniziano ad essere utilizzati i transistor e il sistema era gestito da un operatore. I lavori erano organizzati in lotti inseriti da un dispositivo di ingresso (es: schede forate) che vengono caricate da un __monitor__ che ordina il caricamento dei programmi e delega l'esecuzione a un'altro programma. Una volta terminata l'esecuzione il controllo della macchina torna al monitor.

### Gestione Della Memoria

Ci sono nuove funzioni hardware, la memoria non è più solo composta da una serie di istruzioni da eseguire in sequenza, ma ci sono nuove funzioni che generano notevoli cambiamenti all'interno del processore, come l'interruzione dell'esecuzione, il salto di un'istruzione ecc...

## Terza Generazione

L'hardware è composto da circuiti integrati fatti di silicio che connette insieme più dispositivi, rendendo possibile la multiprogrammazione.

### Time Sharing

Il dispositivo doveva gestire più lavori interattivi, con processore condiviso tra più utenti che accedono attraverso terminali e l'esecuzione del programma di ogni utente è alternata uno alla volta per un breve lasso di tempo.

### Multiprogrammazione

La multiprogrammazione ottimizza l'utilizzo del processore, a differenza del time sharing il cui obiettivo è minimizzare i tempi di risposta.

## Quarta Generazione

I computer vengono integrati su larga scala e viene costruita un'interfaccia amichevole per l'uso da parte di utenti non esperti.

## Quinta Generazione

Gli smartphone, dispositivi con autonomia limitata che devono quindi avere una gestione della batteria appurata.

# 2. Sistema di elaborazione


Il sistema di elaborazione è composto da:

- processore
- memoria centrale
- dispositivi I/O

# Processore

Il processore preleva dalla memoria centrale istruzioni e dati, esegue le istruzioni, scrive il risultato in memoria centrale e passa all'istruzione successiva.

## Indirizzi

### MAR

Memory address register è dove viene salvata la posizione in memoria dei dati

### MBR

Memory buffer register è dove viene salvata l'istruzione prima di essere caricata nell'IR

## Tipi Di Processore

### Microprocessore

composto da un singolo chip che contiene l'equivalente di numerosi transistor. Nei calcolatori moderni è in realtà un __multiprocessore__, ovvero sullo stesso chip sono presenti più __cores__ che possono agire l'uno indipendentemente dall'altro.

è dotato di __cache__, una memoria interna al processore che è molto più veloce anche della memoria centrale.

### Processore Grafico

Esegue le operazioni su un array di più dati con la tecnica SIMD (Single Instruction Multiple Data) e può essere usato anche per applicazioni non grafiche

### Processore a Segnale Digitale

Si occupa di codificare i segnali audio e video e supporta la crittografia

### SoC

Tutti i componenti sono su un chip singolo (Es: smartphone)

## Ciclo Fetch-Execute

Nei primi sistemi il processore estrae l'istruzione dalla memoria, la esegue e ripete con la successiva fino a che le istruzioni non finiscono.

## Interruzioni

Permettono agli altri modulo di interrompere il ciclo fetch-execute, per evitare che la cpu resti inattiva nell'attesa di I/O e permette di sospendere l'esecuzione del programma.



# Memoria Principale

Sono contenuti i programmi da eseguire, composti da istruzioni e dati. è compreso il sistema operativo.

# Moduli Di Input/output

I moduli di input e output forniscono dati per il processo, ma sono molto più lenti della memoria centrale


# 3. Architettura dei sistemi operativi


# Approcci E Elementi Progettuali Dei Sistemi Operativi

- Processi
- Gestione della memoria
- Protezione e sicurezza dell'informazione
- Schedulazione e gestione delle risorse
- Struttura del sistema

# Caratteristiche Dei Sistemi Operativi Moderni

- Architettura microkernel
- Multithread
- Multiprocessing simmetrico
- Sistemi operativi distribuiti
- Architettura orientata agli oggetti

# Macchine Virtuali

Possiamo immaginare che il nostro sistema operativo realizzi delle macchine virtuali, ciascuna dotata di propria memoria e sistema operativo.

# Servizi per L'utente

## Interfaccia Utente

- linea di comando (CLI)
- GUI
- batch

## Esecuzione Dei Programmi

- Caricamento
- Esecuzione
- Terminazione

## Operazioni I/O

## Realizzazione Del FileSystem

- Creazione e cancellazione
- Lettura e scrittura
- Ricerca e informazioni
- Gestione dei permessi

## Comunicazione Tra I Processi

- Memoria condivisa
- Scambio dei messaggi

## Rilevazione Degli Errori
- hardware
- I/O
- Programmi utente 


# 4. Progettazione del sistema operativo



Il sistema operativo deve mettere a disposizione dei programmi una serie di servizi necessari all'esecuzione.

# Struttura

## Sistemi monolitici

Sono sistemi non divisi in moduli e quindi era tutto un grosso programma

## Sistemi stratificati

Ogni stato implementa un oggetto astratto composto da dati e operazioni, i dettagli dell'implementazione vengono nascosti agli strati superiori che richiedono solamente dei servizi in attesa di un risultato. Questo permette di rendere molto facile la programmazione di ogni strato e la sua portabilità, ma bisogna definire quali sono gli strati e potrebbero esserci degli overhead.

### Microkernel


# Generazione di un sistema operativo

- Scrivere il codice sorgente
- Compilare il sistema operativo
- Personalizzare il sistema rispetto all'hardware, configurarlo per farlo funzionare sul sistema


# Stati di un processo
2

# 5. Processi e thread


I processi sono caratterizzati dalle __risorse allocate__ e dallo __scheduling__:

Ma le due caratteristiche possono essere trattate in maniera indipendente.

# Processo (task)

In un ambiente multi-thread, il processo è l’unità di allocazione delle risorse e un’unità di protezione.

Sono associati al processore:

- Spazio di indirizzamento virtuale (immagine del processo)
- Accesso protetto al processore, ad altri processi (IPC), files, dispositivi IO
- Uno o più thread

# Thread

Unità che viene assegnata al processore. Sono associati ai thread:

- stato: pronto, in attesa, in esecuzione
- Contesto (immagine del processore, salvo quando non è in esecuzione)
- Stack di esecuzione
- Spazio di memoria statico
- Accesso alla memoria e risorse del processo, condivise con gli altri thread del processo

## Stati

- Esecuzione
- Pronto
- Attesa

## Operazioni

- Creazione
- Sospensione (block)
- Riattivazione (unblock)
- Terminazione

# Multithreading

Si dice multithreading la capacità di un sistema operativo di permettere più tracce di esecuzione concorrenti in un singolo processo, ci sono quattro casi:

- Single threading
	- Un processo un thread
	- più processi, un thread per processo
- Multi threading
	- un processo più thread
	- più processi, ognuno con più thread

## Benefici

La creazione e l'eliminazione di un thread sono più rapide rispetto a un processo, così come lo switch tra due thread dello stesso processo rispetto a due processi diversi.

La comunicazione tra programmi diversi è più efficiente (diversi thread nello stesso processo)

In un sistema a utente singolo si permette l'esecuzione sia in foreground che in background, elaborazione asincrona con un'alta velocità di esecuzione.

I programmi sono più modulari.

```ad-info
La schedulazione è gestita principalmente a livello di thread. Ma non la sospensione (memory swap) e la terminazione.
```

## Sincronizzazione Dei Thread

I thread di un processo condividono spazio di indirizzamento e altre risorse, ogni modifica delle risorse influenza gli altri thread.

```ad-important

La modifica simultanea di un dato da parte di due thread può corrompere il dato medesimo. È necessario quindi sincronizzare l’accesso dei thread alle risorse

```

# Livelli Dei Thread

## Livello Utente

La gestione dei thread è fatta dall'applicazione stessa, quindi il kernel non sa dell’esistenza dei thread.

### Vantaggi

- Lo scambio di thread non richiede privilegi della modalità kernel
- La schedulazione può essere specifica per l’applicazione
- Portabilità

### Svantaggi

- Le chiamate di sistema sono bloccanti per l’intero processo
- Nessun vantaggio dai multiprocessori

#### Contromisure

- __Jacketing__: trasforma una chiamata di sistema bloccante in una non bloccante
- Programmare un’applicazione in processi multipli

## Livello Kernel

La gestione dei thread è fatta dal kernel e l’applicazione utilizza un’API per la gestione dei thread.

Il kernel gestisce quindi tutti i PCB dei processi e dei thread e la schedulazione del processore si basa su tutti i PCB.

### Vantaggi

- Possibilità di eseguire thread differenti su diversi processori
- Il blocco di un thread non blocca il processo
- Anche le routine del kernel posso essere gestite in multithreading

### Svantaggi

- I cambi di modalità (utente/kernel) producono overhead

## Approcci Misti

- Creazione dei thread, schedulazione e sincronizzazione nello spazio utente
- Thread modalità utente mappati su thread modalità kernel (in numero minore o uguale)
- Permette esecuzione parallela dei thread e il blocco di un thread non blocca il processo

# 6. Mutua esclusione


# Gestione Dei Processi

Multiprogrammazione: molti processi, un singolo processore

Multiprocessing: molti processi, un multiprocessore

Processi Distribuiti: molti processi, molti processori distribuiti (cluster)

La concorrenza appare in tre differenti contesti

- Applicazioni multiple
- Applicazioni strutturate
- Struttura del OS

# Principi Della Concorrenza

**Elaborazione concorrente **

- Nell’uniprocessore multiprogrammato, le esecuzioni dei processi si alternano
- nel multiprocessore, le esecuzioni dei processi si alternano e si sovrappongono
- in entrambi i casi, la velocità relativa di esecuzione dei processi non è prevedibile. Dipende da:
	- attività degli altri processi
	- gestione delle interruzioni
	- politiche di schedulazione

**Difficoltà **

- condivisione di risorse globali
- allocazione ottimale delle risorse
- debugging

## Esempio

![[Pasted image 20230321112302.png]]

![[Pasted image 20230321112321.png]]

![[Pasted image 20230321112333.png]]

# Conclusione

È necessario proteggere le variabili condivise

SI deve controllare il codice che accede alla variabile

**Race condition:** Si verifica quando più processi o threads leggono e scrivono dati in modo che il risultato finale dipende dall’ordine di esecuzione delle istruzioni dei processi

## Esempi

I processi $P1$ e $P2$ assegnano rispettivamente $1$ e $2$ alla variabile condivisa a. Il valore finale sarà quello del ‘secondo arrivato’.

I processi P1 e P2 condi.idono le variabili b e c con valori iniziali $b = 1, c = 2$. $P1$ esegue $b = b + c$, $P2$ esegue $c = b + c$. Se arriva primo $P1$, avremo $b = 3, c = 5$. Nel caso opposto, $b = 4, c = 3$.

## Problemi Determinati Dalla Concorrenza

SOno compiti del OS:

- tenere traccia dei porcessi (PCB)
- Allocare e deallocare risorse per i processi attivi (tempo elaborazione, memoria, files, dispoitivi I/O)
- Proteggere i dati e le risorse di ogni processo da interferenze involontarie di altri processi
- Il risultato di ogni processo deve essere indipendente dalla sua velocità relativa a quella dei processi concorrenti

![[Pasted image 20230321112750.png]]

# Competizione per Le Risorse

Processi concorrenti sono in conflitto per l’uso delle risorse

**Problemi**

- Mtua esclusione
- Stallo (deadlock)
- Starvation

```c
/* PROCESS 1 */ 
void P1 { 
	while (true) { 
		/* preceding code */; 
		entercritical (Ra); 
		/* critical section */; 
		exitcritical (Ra); 
		/* following code */; 
	} 
}

```

```c
/* PROCESS 2 */ 
void P2 { 
	while (true) { 
		/* preceding code */; 
		entercritical (Ra); 
		/* critical section */; 
		exitcritical (Ra); 
		/* following code */; 
	} 
}

```

# Cooperazione per Condivisione

Due o più processi che interagiscono senza conoscersi usano e modificano __dati condivisi__. Devono cooperare per la corretta gestione dei dati utilizzando un __meccanismo di controllo__ che deve assicurare l'__integrità dei dati__, data la presenza di problemi di __mutua esclusione, stallo, starvation__

```ad-example

	P1:
		a = a + 1;
		b = b + 1;
	P2:
		b = 2 * b;
		a = 2 * a;
	ordine:
		a = a + 1;
		b = 2 * b;
		b = b + 1;
		a = 2 * a;

```

# Cooperazione per Scambio Di Messaggi

I processi collaborano per un obiettivo comune, la comunicazione permette di sincronizzarsi e coordinarsi attraverso delle __primitive per invio e ricezione__ di messaggi che sono fornite dal _kernel o dal linguaggio di programmazione_.

Questo permette di non richiedere la mutua esclusione ma può determinare stallo o starvation.

# Requisiti per La Mutua Esclusione

- Un solo processo alla volta è ammesso alla sezione critica per ciascuna risorsa condivisa.
- Un processo che si ferma fuori dalla sua sezione critica non deve interferire con gli altri processi
- Si deve evitare __deadlock__ e __starvation__
- Se nessun processo è nella sezione critica, deve essere concesso a ogni processo di entrare senza ritardo
- Nessuna ipotesi sulla velocità relativa dei processi e sul numero dei processori
- Un processo resta nella sezione critica per un tempo finito

# Mutua Esclusione Con Supporto Hardware

## Disabilitazione Senza Interruzioni

Su uniprocessore, assicura che la sezione critica sia portata a termine senza interruzioni:

```c
while (true) { 
	/* disabilita interruzioni */; 
	/* sezione critica */; 
	/* abilita interruzioni */; 
	/* resto del programma */; 
}
```

- Primitive definite dal kernel
- Rallenta il sistema
- Non applicabile su multiprocessore

## Istruzioni Speciali

Un solo processore alla volta può accedere a una locazione di memoria, esistono quindi speciali istruzioni macchina che eseguono due operazioni su un dato in maniera atomica

### Compare and Swap

````c
int compare_and_swap ( int *word, int testval, int newval) { 
	int oldval; 
	oldval = *word 
	if (oldval == testval) *word = newval; 
	return oldval; 
}
````

````c

/* program mutualexclusion */ 
const int n = /* number of processes */; 
int bolt; 
void P( int i) { 
	while (true) { 
		while (compare_and_swap(bolt, 0, 1) == 1) 
			/* do nothing */; 
		/* critical section */; 
		bolt = 0; 
		/* remainder */; 
	} 
}

void main() { 
	bolt = 0; 
	parbegin (P(1), P(2), ... ,P(n)); 
}

````

````c
/* program mutualexclusion */ 
int const n = /* number of processes */; 
int bolt; 
void P( int i) {
	int keyi = 1; 
	while (true) { 
		do exchange (&keyi, &bolt) 
		while (keyi != 0); 
		/* critical section */; 
		bolt = 0; 
		/* remainder */; 
	} 
} 

void main() { 
	bolt = 0; 
	parbegin (P(1), P(2), ..., P(n)); 
}
````

### Vantaggi

- applicabile a qualsiasi numero di processi su uniprocessore o multiprocessore
- semplicità
- può supportare multiple sezioni critiche

### Svantaggi

- attesa attiva (busy-waiting)
- possibilità di stallo
- possibilità di starvation

# Algoritmo Di Dekker

## Obiettivo

Un protocollo che permetta a due processi di assicurare la mutua esclusione

- senza supporto hardware (salvo impossibilità di accesso simultaneo al medesimo indirizzo di memoria)
- senza stallo
- senza starvation

# Semaforo Generico

Una variabile con valore intero, una coda e tre operazioni

- inizializzazione a un valore non negativo
- *semWait* decrementa il valore del semaforo. Se il valore diventa negativo, il processo è sospeso e inserito nella coda
- *semSignal* incrementa il valore del semaforo. Se il valore non diventa positivo, uno dei processi della coda è riattivato

```ad-note
title: Osservazione

Il processo non ha modo di sapere in anticipo 
- se con l’esecuzione di semWait sarà sospeso 
- se c’è un processo che attende l’esecuzione di semSignal 
- quale fra i processi in attesa sarà riattivato da semSignal

```

````c

struct semaphore { 
	int count; 
	queueType queue; 
}; 

void semWait(semaphore s) { 
	s.count--; 
	if (s.count < 0) { 
		/* place this process in s.queue */; 
		/* block this process */; 
	} 
} 

void semSignal(semaphore s) { 
	s.count++; 
	if (s.count<= 0) { 
		/* remove a process P from s.queue */; 
		/* place process P on ready list */; 
	} 
}

````

# Semaforo Binario

Una variabile con valore binario (0 o 1), una coda e tre operazioni 
- inizializzazione a zero o uno 
- *semWaitB* verifica il valore del semaforo. Se il valore è 1 allora è portato a 0, nel caso contrario, il processo è sospeso e inserito nella coda, 
- *semSignalB* verifica se ci sono processi in attesa nella coda. In caso affermativo, uno dei processi della coda è riattivato, nel caso opposto, il valore del semaforo è portato a 1.

## Gestione della coda

- Deve evitare la starvation
- Generalmente FIFO (semaforo *forte*)

````c

struct binary_semaphore { 
	enum {zero, one} value; 
	queueType queue; 
}; 

void semWaitB(binary_semaphore s) { 
	
	if (s.value == one) 
		s.value == zero;
	else{ 
		/* place this process in s.queue */; 
		/* block this process */; 
	} 
} 

void semSignal(semaphore s) { 

	if (s.queue is empty()) 
		s.value = one;
	else{ 
		/* remove a process P from s.queue */; 
		/* place process P on ready list */; 
	} 
}

````
