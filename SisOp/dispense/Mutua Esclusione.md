
# Gestione dei processi

Multiprogrammazione: molti processi, un singolo processore
Multiprocessing: molti processi, un multiprocessore
Processi Distribuiti: molti processi, molti processori distribuiti (cluster)

La concorrenza appare in tre differenti contesti
- Applicazioni multiple
- Applicazioni strutturate
- Struttura del OS

# Principi della concorrenza

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
I processi $P1$ e $P2$ assegnano rispettivamente $1$ e $2 $alla variabile condivisa a. Il valore finale sarà quello del ‘secondo arrivato’.
I processi P1 e P2 condi.idono le variabili b e c con valori iniziali $b = 1, c = 2$. $P1$ esegue $b = b + c$, $P2$ esegue $c = b + c$. Se arriva primo $P1$, avremo $b = 3, c = 5$. Nel caso opposto, $b = 4, c = 3$.

## Problemi determinati dalla concorrenza

SOno compiti del OS:
- tenere traccia dei porcessi (PCB)
- Allocare e deallocare risorse per i processi attivi (tempo elaborazione, memoria, files, dispoitivi I/O)
- Proteggere i dati e le risorse di ogni processo da interferenze involontarie di altri processi
- Il risultato di ogni processo deve essere indipendente dalla sua velocità relativa a quella dei processi concorrenti

![[Pasted image 20230321112750.png]]

# Competizione per le risorse
Processi concorrenti sono in conflitto per l’uso delle risorse

**Problemi** 
- Mtua esclusione
- Stallo (deadlock)
- Starvation