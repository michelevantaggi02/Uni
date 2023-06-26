# 1. Definizione di Algoritmo

----

Un algoritmo è una procedura passo a passo per eseguire delle mansioni una finita quantità di volte

# Algoritmo Deterministico

Un algoritmo che dato lo stesso input esegue sempre gli stessi passi.

Questa materia si occupa di scegliere per ogni problema l’algoritmo più efficiente in tempo o spazio.

La maggior parte di questi algoritmi trasforma un input in un output, e il suo tempo di esecuzione aumenta in modo direttamente proporzionale con la dimensione dell’input.

Il tempo di esecuzione medio è spesso molto difficile da determinare, e quindi ci concentriamo sul peggior tempo di esecuzione che è più facile da analizzare e cruciale per la maggior parte delle applicazioni.

## Esempi

Ho 2 array:

A: array [1: n] of integers

A is permutation of B?

Input

$$A = 5, 7, 3, 1$$

$$B = 3, 1, 7, 5$$

Risposta: si

Input

$$A = 5, 7, 3, 1$$

$$B = 2, 7, 3, 1$$

Risposta: no

Questo fa schifo:

	bool permute(int* A, int* B){
		int count = 0;
		for( int i = 0; i<n; i++){
			int j = 0;
			while(j<n && A[i] == B[j] )
				j++;
			if(B[j] == A[i]) count++;
		}
		return count == n;
	}

Questo è meglio:

	int permut(int* A, int* B){
		int count = 0;
		for( int i = 0; i<n; i++){
			bool trovato = false;
			for(int j = 0; j<n && !trovato; j++){
				if(B[j] == A[i]){
					trovato = true;
					count++;
				}
			}
		if(!trovato)
			return false;
		}
	return count == n;
	}

La terza opzione implica l’utilizzo di un algoritmo di sorting per ordinare i vettori e controllare che nelle posizioni ci sia lo stesso elemento, la complessità dell’algoritmo dipende quindi dalla complessità degli algoritmi di sorting utilizzati.

## Algoritmo Randomizzato

È un algoritmo che, dato uno stesso input, l’output sarà sempre diverso

# Scalabilità

Poter risolvere istanze dello stesso problema di dimensioni estremamente variabili gli scienziati devono trovare delle soluzioni che siano scalabili.

## Esempio

Molte compagnie nei colloqui di lavoro valutano la capacità di problem solving chiedendo domande circa algoritmi e strutture di dati da utilizzare anche in atti pratici.

# Struttura Di Dati

Una struttura di dati è un modo sistematico di organizzare ed accedere ai dati

# 2. Analisi e studio


----

# Studi Sperimentali

Per studiare il comportamento di un [[1. Definizione di Algoritmo|algoritmo]] bisogna:

- Scrivere un programma che implementi un algoritmo
- Eseguire il programma molteplici volte con input di dimensioni e composizioni diverse
- Fare il grafico di esecuzione

```ad-attention
title: Limitazioni

- Implementare l’algoritmo potrebbe essere complicato
- I risultati potrebbero non comprendere il tempo di esecuzione su altri input non sperimentati
- Per comparare due algoritmi bisogna utilizzare lo stesso ambiente software e hardware
```

## Analisi Teorica

- Usa una descrizione ad alto livello dell’algoritmo al posto della sua implementazione
- Mostra il tempo di esecuzione come una [[#Tipi di funzioni|funzione]] di input la dimensione n
- Prende in considerazione tutti gli input
- Permette di valutare la velocità di  un algoritmo indipendentemente dall’ambiente

### Pseudocodice

- Descrizione ad alto livello di un algoritmo
- Più strutturato del linguaggio comune
- Meno dettagliato di un programma
- Notazione preferita per descrivere un algoritmo
- Nasconde i problemi di design di un programma

### Tipi Di Funzioni

1. Costante -> l
2. Logaritmica -> log n
3. Lineare -> n
4. N Log n -> n log n
5. Quadratica -> $n^2$
6. Cubica -> $n^3$
7. Esponenziale -> $2^n$

```ad-info
title: Info

In una funzione log(log(n)) la pendenza (derivata) corrisponde al rateo di crescita.
```

### Operazioni Primitive

- Calcoli base eseguiti da un algoritmo
- Identificabili in pseoudocodice
- Indipendenti dai linguaggi di programmazione
- La definizione esatta non è importante
- Si assume l’impiego di un tempo costante nel modello RAM

### Rateo Di Crescita Del Tempo Di Esecuzione

- Cambiando software e hardware
- Cambia T(n) di un fattore costante
- Non altera il rateo di crescita di T(n)
- Il rateo di crescita lineare del tempo di esecuzione T(n) è una proprietà intrinseca dell’algoritmo arrayMax (ricerca del valore massimo di un vettore)

### $\Omega(n)$

- Rappresenta il caso migliore in riferimento a uno specifico algoritmo.
- Rappresenta la complessità intrinseca del problema. (indipendente dall’algoritmo pensato)

Un algoritmo è ottimo quando il caso migliore è uguale al caso peggiore

### Analisi Di Un Algoritmo Ricorsivo

La funzione T(n) deriva da una **relazione di ricorrenza** che caratterizza il tempo di esecuzione sui valori più piccoli di n

	Algorithm recursiveMax(A, n):
		input: array A of n >= 1 integers
		output: maximum element in A
		if n = 1 then
			return A[0]
		return max{recursiveMax(A, n-1), A[n-1]}

$$T(n)=\begin{cases} 3, \quad\quad\quad\quad\quad\quad n=1 \\ T(n-1) + 7, \quad altrimenti \end{cases}$$

### Fattori Costanti

Il rateo di crescita è minimamente affetto da fattori costanti o da termini di ordine minore

### Notazione Big-Oh

Date due funzioni f(n) e g(n), diciamo che f(n) è O(g(n)) se ci sono delle costanti c positive e $n_0$ tali che

$$f(n) \leq cg(n)\, for \, n \geq n_0 $$

- Se f(n) è un polinomio di grado D, allora f(n) è O(nD)
- Usa la classe di funzioni più piccola possibile
- Usa la forma più semplice di espressione della classe

#### Compagni Di Big-Oh

##### Big Omega

F(n) è $\Omega(g(n))$ se esiste una costante c > 0 e una costante intera $n_0 \geq 1$ tali che

$$f(n)\geq cg(n)\, \forall n \geq n_0$$

##### Big Theta

F(n) è $\Theta(g(n))$ se ci sono costanti c’ > 0 e c’’ > 0 e una costante intera $n_0 \geq 1$ tali che

$$c'g(n) \leq f(n) \leq c''g(n), \, \forall\,n\geq n_0$$

##### $\omega$

È l’inverso di O, quindi f(n) è $\omega(g(n))$ per ogni costante c > 0 se esiste una costante $n_0 > 0$ tale che

$$0 \leq cg(n) < f(n), \, \forall\, n\geq n_0$$

### Esempio Di Analisi Di Un Algoritmo

Dato un array di n interi, trovare il sottoarray A[j:k] la cui somma degli elementi sia la più alta.

Questo è una possibile domanda fatta durante i colloqui di lavoro per testare le capacità di pensiero dei candidati, (__maximum subarray problem__).

#### Prima Versione Lenta

	MaxSubSlow(A):
	input: array A di n elementi indicizzati da 1 a n
	output: la massima somma degli elementi di un sottoarray di A
		m=0
		for j=1:n:
			for k=j:n:
				s=0
				for i=j:k:
					s+=A[i]
				if s > m:
					m = s

- il ciclo esterno J viene iterato n volte, il ciclo k viene iterato **al più** n volte e il ciclo i viene iterato **al più** n volte
- Quindi il tempo di esecuzione è di $O(n^3)$

#### Seconda Versione Migliorata

Una via più efficiente è quella di calcolare queste somme è quella di considerare dei prefissi

$$S_t=a_1+a_2+...+a_t=\sum_{i=1}^t{a_i}$$

Assumendo $S_0=0$ possiamo calcolare ogni somma $S_{j,k}=S_k-S_{j-1}$ in un tempo costante

	MaxSubFaster(A):
		S[0]=0
		for i=1:n:
			S[i]=S[i-1] + A[i]
		m=0
		for j=1:n:
			for k=j:n:
				s = S[k] - S[j-1]
				if s > m
					m = s
		return m

Il tempo di esecuzione di MaxSubFaster è di $O(n^2)$

#### Terza Versione Migliore

Invece di calcolare la somma prefisso, calcoliamo la massima somma suffisso $M_t$, che sarebbe il massimo tra 0 e il massimo $s_{j,t}$ per j =1,..,t

$$M_t=max\{0,max\{s_{j,t}\}\}$$

Se $M_t>0$ allora è la somma di un massimo sottoarray che finisce a t, se $M_t=0$ allora possiamo tranquillamente ignorarlo.

Se sappiamo tutti i valori di $M_t$ per t=1,...,n allora la soluzione del problema sarebbe solo il massimo di ogni $M_t$.

Per $t \geq 2$ se abbiamo un sottoarray massimo che finisce a t, e ha una somma positiva, allora è solo A[t:t] o è composto dal massimo sottoarray che finisce a t-1 più A[t]. Così definendo $M_0=0$ e

$$M_t=max\{0,M_{t-1} + A[t]\}$$

Se questo non fosse il caso allora avremmo un sottoarray con la somma più grande sostituendo il sottoarray scelto che finisce a t-1 con il più grande, che contraddirebbe il fatto che abbiamo il sottoarray più grande che finisce a t.

Inoltre se prendiamo il valore del sottoarray massimo che finisce a t-1 e aggiungiamo A[t] rendendolo negativo, allora $M_t=0$ dato che non c'è un sottoarray che finisce a t con una somma positiva.

	MaxSubFastest(A):
		M[0]=0
		for t=1:n
			M[t]= max(0, M[t-1] + A[t])
		m=0
		for t=1:n
			m=max(m, M[t])
		return m

L'algoritmo MaxSubFastest consiste di due loop che vengono iterati esattamente n volte e impiegano O(1) ad ogni iterazione, quindi il tempo totale di esecuzione è O(n)

## Insertion Sort

	insertionSort(A,n):
		for i=2:n:
			key=A[i]
			j=i-1
			while j>0 and A[j]>key
				A[j+1]=A[j]
				j=j-1
			A[j+1]=key

L’insertion sort ha un tempo di esecuzione $O(n^2)$

- Il for esterno viene eseguito n-1 volte
- Il for interno viene eseguito al massimo i-1 volte
- Il numero esatto di iterazione del while dipende dai valori su cui itera, che variano tra 0 e i-1
- Dato che i al massimo arriva ad n, il numero totale di iterazioni del ciclo interno è (n-1)(n-1), minore di $n^2$
- Ogni iterazione del loop interno impiega un tempo costante, con un totale di al più $cn^2$ per qualche costante c, oppure O(n^2)

Il tempo peggiore di esecuzione è quindi $\Omega(n^2)$

- Si osserva che un valore che viene spostato di k posizioni, la riga 6 (a[j+1] = a[j]) deve essere eseguita k volte
- Assumendo che n sia multiplo di 3, possiamo  dividere l’array in 3 gruppi di n/3 posizioni
- Dato che almeno n/3 valori devono essere spostati di n/3 posizioni, la riga 6 viene eseguita almeno (n/3)(n/3) volte che sarebbe $\Omega(n^2)$

Dato che abbiamo mostrato che l’insertion sort ha tempo di esecuzione $O(n^2) \, e \,\Omega(n^2)$, possiamo concludere che il peggior tempo di esecuzione è di $\Theta(n^2)$

## Logaritmi

$$\log_d(n)=\frac{\log_a(n)}{\log_a(d)}=c$$

$$a=b^{log_b(a)}$$

$$\log_c(ab)=\log_c(a)+\log_c(b)$$

$$\log_b(a^n)=n\log_b(a)$$

$$\log_b(\frac 1a)= - \log_b(a)$$

$$\log_b(a)=\frac 1{\log_a(b)}$$

$$a^{\log_b(c)}=c^{\log_b(a)}$$


# 3. Modello RAM (Random Access Machine)


----

Si il nome confonde.

La RAM è composta da

- CPU
- Un potenziale banco di celle di memoria sconnesse, ognuna dei quali può contenere un numero arbitrario di numeri o caratteri
- Celle di memoria numerate il cui accesso impiega delle unità di tempo

# 4. Ammortizzazione


----

# [Ammortizzazione](https://unistudium.unipg.it/unistudium/pluginfile.php/768543/mod_resource/content/1/Week1.pdf)

Il **tempo di esecuzione ammortizzato** di un’operazione all’interno di una serie di operazioni è il tempo di esecuzione nel caso pessimo diviso per il numero di operazioni.

## Esempio Estensione Di Un Array

Ho un array di dimensione C, e voglio farlo arrivare a dimensione $N=kc, k \in Z$

Ogni volta che voglio ingrandire l’array ho due opzioni:

- ingrandisco di altre C dimensioni, copio la dimensione dell’array (1C, 2C,..ecc) e esegui C operazioni O(1) (**strategia incrementale**).
- raddoppio la dimensione dell'array, copio i suoi elementi (1C, 2C, 4C, 8C, ...) e eseguo le operazioni di aggiunta. (**strategia del raddoppio**)

Compariamo le due strategie analizzando il tempo totale T(n) impiegato per eseguire n operazioni di aggiunta.

Chiamiamo **_tempo ammortizzato_** di operazioni di aggiunta il tempo medio impiegato da un'operazione di aggiunta oltre le serie di operazioni.

Assumendo di iniziare con una lista vuota rappresentata da un array di dimensione 1.

### Strategia Incrementale

Dopo n operazioni di aggiunta, rimpiazziamo l'array k= n/c volte, dove c è una costante.

Il tempo totale T(n) di una serie di n operazioni di aggiunta è proporzionale a

$$n+c+2c+3c+4c+...+kc=$$

$$n+c(1+2+3+4+...+k)=$$

$$n+\frac{ck(k+1)}2$$

Dato che c è una costante, T(n) è $O(n+k^2)$, ovvero $O(n^2)$, e il tempo di esecuzione ammortizzato è

$$\frac {O(n^2)}n=O(n)$$

### Strategia Del Raddoppio

Rimpiazziamo l'array $k=\log_2(n)$ volte, il tempo totale T(n) di una serie di n operazioni è proporzionale a

$$n+1+2+4+8+...+2^k=$$

$$n+2^{k+1}-1=3n-1$$

T(n) è O(n).

Il tempo di esecuzione ammortizzato è O(1)


# 5. Divide et impera


----

1. Divide the problem
2. Conquer the subproblems by solving them recursively
3. Combine the solutions

# Merge Sort

1. Dividi in 2 sottoarray
2. Conquista: ordina ricorsivamente i 2 sottoarray
3. Combina: fondi i 2 array ordinandoli
$$T(n)=2T(\frac n2)+\Theta(n)$$


# Master Theorem

$$T(n) = aT(\frac nb) + f(n)$$

## Caso 1

$$f(n) = O(n^{\log_b(a) - \varepsilon}),\quad \varepsilon>0 \implies T(n)=\Theta(n^{\log_b(a)}) $$

## Caso 2

$$f(n)=\Theta(n^{\log_b(a)} \log^{k}(n)), \quad k \geq 0 \implies T(n)=\Theta(n^{\log_b(a)} \log^{k+1}(n))$$

## Caso 3

$$f(n)=\Omega(n^{\log_b(a) + \varepsilon}), \quad \varepsilon > 0 \implies T(N)=\Theta(f(n))$$

# Moltiplicazione Di Strassen

![[7. Vettori#Prodotto Tra Matrici Di Strassen]]

Gli algoritmi di moltiplicazione tra matrici impiegano di solito $\Theta (n^3)$, considerando che è il numero di moltiplicazioni scalari impiegate per le moltiplicazioni. Strassen ha pubblicato un algoritmo ricorsivo che impiega $\Theta (n^{\log 7}) = O(n^{2.81})$ che è asintoticamente meglio di $\Theta(n^3)$, per ottenere questo risultato si riducono di 1 il numero di moltiplicazioni (che impiegano numerose operazioni tra di loro), aumentando il numero di addizioni e sottrazioni.

## Analisi

$$ T(n) = 7 T(n/2) + \Theta(n^2)$$

## VLSI Layout

Voglio creare un albero binario completo con n foglie in una griglia utilizzando il minor spazio possibile

![VLSI](VLSI.png)

$$H(n)=H(n/2) + \Theta(1)= \Theta(\log n)$$

$$ W(n) = 2W(n/2) + \Theta(1)= \Theta(n)$$

$$Area=\Theta(n \log n)$$

## H-tree

![H-tree](H-tree.png)


# 6. Quicksort


----

```ad-info

Un algoritmo si definisce in place se utilizza una quantità di memoria $\Theta(1)$.
```

Il quicksort su basa sul processo a tre passi del [[5. Divide et impera]]:

- Dividere la partizione A[p:r] in due sottoarray A[p:q-1] e A[q+1:r] tali che ogni elemento di $A[p:q-1] \leq A[q]$ e $A[q+1:r]\geq A[q]$
- Conquer: ordinare i due sottoarray ricorsivamente
- Combine: nessun lavoro necessario dato che viene ordinato in place
Il passo di divisione deve essere preceduto da una procedura di **PARTITION** che trova l'indice q che separa i due sottoarray.

	quicksort(A,p,r):
		//partizionare i sottoarray intorno al perno A[q
		q = PARTITION(A,p,r) //posizione del perno nell'insieme ordinato
		
		quicksort(A,p,q-1)
		quicksort(A,q+1,r)


# Partizionamento

	PARTITION(A,p,r):
		x = A[r] //pivot
		i = p-1 //indice più grande nella parte inferiore
		for j=p:r-1: //processo ogni elemento che non sia il pivot
			if A[j] <= x //l'elemento va nella parte inferiore?
				i++ //indice dello spazio per la parte inferiore
				scambia A[i],A[j] //ci inserisco l'elemento
		scambia A[i+1],A[r] //il perno viene spostato nella parte bassa
	return i + 1 //nuovo indice del perno

```ad-important
PARTITION prende sempre l'ultimo elemento A[r] del subarray come pivot

```

```ad-note
PARTITION ha una complessità $\Theta(n)$ dove n è la dimensione del sottoarray

```

# Performance

Il tempo di esecuzione del quicksort dipende dal [[#Partizionamento]] del sottoarray

- se i sottoarray sono bilanciati allora il quicksort è veloce tanto quanto il [[5. Divide et impera#Merge Sort|mergesort]]
- Se sono sbilanciati allora il quicksort può andare piano quanto l' [[2. Analisi e studio#Insertion Sort|insertion sort]]

## Caso Peggiore

Avviene quando:

- i sottoarray sono completamente sbilanciati,
- ci sono 0 elementi in un sottoarray e n-1 nell'altro
Si ottiene quindi la ricorrenza:
$$T(n)=T(n-1)+T(0)+\Theta(n)=T(n-1)+\Theta(n) = \Theta(n^2)$$

## Caso Base

- Avviene quando i sottoarray sono completamente bilanciati ogni volta
- Ogni sottoarray ha $\leq \frac n2$ elementi
- In un upper bound si ha la ricorrenza $T(n)=2T(n/2) + \Theta (n) = \Theta( n \log n)$

## Partizionamento Bilanciato

- Il tempo di esecuzione medio nel quicksort è molto più vicino al caso migliore rispetto al caso peggiore

# 7. Heapsort


----

- Caso peggiore $O(n\log n)$
- In place
- Combina il meglio di [[6. Quicksort|quicksort]] e [[5. Divide et impera#Merge Sort|merge sort]]

# Heap

Un heap (not garbage-collected storage) è un albero binario quasi completo.

- Altezza del nodo: # di spigoli sul percorso semplice più lungo dal primo nodo alla foglia
- Altezza dell'heap: altezza della radice $\Theta(\log n

## Esempio

Heap di dimensione 10

![[Esempio-Heap.png]]

Un heap può essere salvato come un array A:

- La radice è A[1]
- il padre di un elemento è A[i/2]
- Il figlio sinistro è A[2i]
- Il figlio destro è A[2i+1]
- A.size oppure A.heap-size indica la dimensione dell'heap in A

```ad-info
collapse: open
title: pseudocodice

	PARENT(i)
		return i/2

	LEFT(i)
		return 2i

	RIGHT(i)
		return 2i + 1
```

## Tipi Di Heap Ordinati

- Max-heap (elemento più grande alla radice), in tutti i nodi esclusa la radice $A[PARENT(i)] \geq A[i]$
- Min-heap (elemento più piccolo alla radice), in tutti i nodi esclusa la radice $A[PARENT(i)] \leq A[i]$

## Max Heapify

MAX-HEAPIFY è importante per manipolare gli heap massimi. Viene usato per mantenere la proprietà max heap.

- Prima di MAX-HEAPIFY, A[i] potrebbe essere più piccolo dei suoi figli
- Assumendo che i sottoalberi destri e sinistri sono heap massimi (non ci sono violazioni della proprietà maxheap tra i sottoalberi. L'unica violazione tra i sottoalberi con radice i potrebbe essere tra i e i suoi figli)
- Dopo MAX-HEAPIFY, il sottoalbero è un max-heap

```ad-info
title: Pseudocodice
collapse: open


	MAX-HEAPIFY(A,i)
		l = LEFT(i)
		r = RIGHT(i)
		if l<= A.size and A[l] > A[i]
			largest = l
		else
			largest = i
		if r<=A.size and A[r] > A[largest]
			largest = r
		if largest != i
			scambia A[i] con A[largest]
			MAX-HEAPIFY(A,largest)

```

Questa procedura impiega $\Theta (\log n)$

### Come Funziona

- Compara A[i] con A[LEFT(i)] e A[RIGHT(i)];
- se necessario, scambia A[i] con il figlio più grande;
- Continua questo processo fino alla fine dell'heap, facendo diventare i sottoalbero un max-heap;
- Quando arriviamo a una foglia, allora il sottoalbero con radice la foglia è per forza un max-heap.

## Costruire Un Heap

Questo algoritmo, dato un array non ordinato di lunghezza n, produce un max-heap di n elementi in A

	BUILD-MAX-HEAP(A,n)
		A.size=n
		for i = [n/2] : -1 : 1
			MAX-HEAPIFY(A,i)

L'algoritmo chiamato con i parametri BUILD-MAX-HEAP(A,10) è composto dai seguenti passaggi:

- A.heap-size diventa 10
- i inizia a 5
- Viene applicato MAX-HEAPIFY agli alberi con radice i nodi : A[5], A[4], A[3], A[2], A[1]

## Analisi

Vengono eseguite O(n) chiamate a MAX-HEAPIFY, ognuna delle quali impiega $O(\log n) \implies O(n\log n)$

Il tempo di esecuzione richiesto da MAX-HEAPIFY è lineare a seconda dell'altezza del nodo, e la maggior parte dei nodi hanno un'altezza bassa. Avendo un numero di nodi$\leq \frac n{2^{h+1}}$ , con l'altezza totale dell'heap di $\log n$ .

Il tempo di esecuzione richiesto da MAX-HEAPIFY con altezza h è quindi O(h), quindi il costo totale di BUILD-MAX-HEAP è di

$$\sum_{h=0}^{\log n}{[\frac n{2^{h+1}}]O(h)} = O(n \sum_{h=0}^{\log n}{\frac h{2^h}})$$

Vedendo l'ultima somma come

$$\sum_{k=0}^\infty{kx^k}, \quad x=\frac 12$$

Abbiamo

$$\sum_{h=0}^{\log n} \frac h{2^h} < \sum_{h=0}^{\infty} \frac h{2^h} =\frac {\frac 12}{(1- \frac 12)^2}=2$$

Quindi, il tempo di esecuzione di BUILD-MAX-HEAP è di $O(n)$

# Heapsort

Dato in input un array, l'algoritmo di heapsort si comporta come segue:

- crea un max-heap dall'array
- Partend dalla radice, l'algorimo piazza l'elemento più grande nella posizione corretta dell'array scambiandolo con l'elemento all'ultima posizione
- Sapendo che l'ultimo nodo è nella posizione corretta, diminuisce l'heap-size e richiama MAX-HEAPIFY sulla nuova radice (che possibilmente è in una posizione errata)
- Ripete l'ultimo passo finché l'heap-size non diventa di dimensione 1, rendendo l'unico nodo rimasto nella posizione corretta

```ad-info
title: Pseudocodice
collapse: open

	HEAPSORT(A, n)
		BUILD-MAX-HEAP(A,n)
		for i = n: -1: 1
			scambia A[1] con A[i]
			A.size -= 1
			MAX-HEAPIFY(A,1)

```

## Analisi

- BUILD-MAX-HEAP : $O(n)$
- Ciclo for : n-1 volte
- scambio di elementi : $O(1)$
- MAX-HEAPIFY: $O(\log n)$

Tempo totale: $O(n \log n)$

Anche se l'heapsort è un grande algoritmo, un quicksort ben implementato lo batte nella pratica

# 8. Sorting in tempo lineare


----

# Counting Sort

Non ci sono comparazioni tra gli elementi

- Input: $A[1,...,n]$ con $A[j] \in \{1,2,...,k\}$
- Output: $A[1,...,n]$ ordinato
- Spazio ausiliario: $C[1,...,k]$

L'algoritmo ha un tempo di esecuzione di $O(n)$, ma utilizza uno spazio ausiliario che potrebbe anche arrivare ad avere dimensione $n \log n$

## Codice

	for i=1 : k
		C[i] = 0
	for j = 1 : n
		C[A[j]] += 1
	for i = 2 : k
		C[i] += C[i-1]
	for j = n : -1 : 1
		B[C[A[j]]] = A[j]
			C[A[j]] -= 1

## Analisi

- Primo ciclo (inizializzazione a 0): $\Theta (k)$
- Secondo ciclo (conta delle ripetizioni) : $\Theta(n)$
- Terzo ciclo: $\Theta (k)$
- Ultimo ciclo : $\Theta (n)$

La somma totale di tutti i costi è $\Theta(n+k)$.

Se $k=O(n)$ allora il counting sort impiega $\Theta(n)$

Il counting sort è un algoritmo stabile, ovvero preserva l'ordine in cui gli elementi sono dati in input.

# Counting Sort Semplificato

	for

# Radix Sort

Il radix sort si utilizza con i numeri interi di $d<n$ cifre, partendo dalla cifra di ordine minore si ordina, con un algoritmo stabile (ad esempio il [[#Counting sort]]) i numeri mettendo in ordine le cifre

![[Radixsort.png|center mid]]

	radix-sort(A, d):
		for i = 1:d
			ordina A alla cifra in posizione i 

# 9. Statistiche d'ordine


----

 Selezionare l' $i$esimo elemento più piccolo di $n$ elementi (L'elemento con __rango__ $i$ )

```ad-tip

- $i=1$ minimo
- $i=n$ massimo

```

Algoritmo "ingenuo" : ordinare e scegliere l'elemento di indice $i$, impiegherebbe un tempo di esecuzione peggiore di $\Theta(n \log n)$ usando [[5. Divide et impera#Merge Sort|merge sort]] o [[7. Heapsort|heapsort]].

Questo però non ci da la complessità intrinseca del problema.

``````ad-example

Se vogliamo trovare l'elemento piccolo (o massimo) basta scorrere la lista e trovarli con gli algoritmi già studiati, impiegherebbe un tempo lineare.

Se vogliamo trovare il il secondo elemento più piccolo, basta trovare il più piccolo e rimuoverlo, cercando di nuovo l'elemento più piccolo sarà il secondo (e viceversa con il secondo elemento più grande). In questo caso il tempo di esecuzione è sempre lineare, in quanto impiegherebbe $2n$.

```ad-check

Utilizzando questo sistema la complessità dell'algoritmo è $in$ 

```



``````

Questa complessità è lineare finché $i$ è una costante.

Quando $i=f(n)$

```ad-example
title: Mediana

- $n$ dispari $f(n) = \frac {n+1}2$
- $n$ pari $f(n) = \lfloor \frac {n+1}2 \rfloor \lceil \frac {n+1}2 \rceil$

La complessità diventa $f(n)n$, il caso peggiore avviene con la mediana.

```

# Divide and Conquer Random

	Rand-Select(A, p, q, i): => iesimo elemento più piccolo di A[p...q]
		if p > q: 
			return A[p]
		r = Rand-Partition(A,p,q)
		k = r - p - 1 => k = rank(A[r])
		if i == k: 
			return A[r]
		if i < k:
			return Rand-Select(A, p, r-1, i)
		else:
			return Rand-Select(A, r+1, q, i-k)


```ad-example

Riguardare 27-02-2023

```

# Ricerca Del Rango

```ad-question
title: Qual è il rango di $A[r] \in A$?
collapse: open

|index | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|
| A | 8 | 7 | 1 | 9 | 2 | 5 | 3 | 6 |

$rank(A[3]) = 1$

```


``````ad-question
title: Qual è l'elemento di rango $i$?
collapse: open

Trovo l'elemento più piccolo dell'array e ripeto con $i-1$ fino a che $i$ non diventa 1.
```ad-example
collapse: open

$$4\;2\;7\;3\;4\;5\;10\;11\quad i=3$$
$$2|4\;7\;3\;4\;5\;10\;11\quad j=1$$
$$2\;3|\;7\;4\;4\;5\;10\;11\quad j=2$$
$$2\;3\;4|\;7\;4\;5\;10\;11\quad j=3$$
in questo caso l'elemento di rango 3 è 4

```

``````

# Partizionamento

Osserviamo che dato x, trovare il rank(x) è facile. Basta trovare quanti elementi sono < x, basta quindi usare [[6. Quicksort#Partizionamento|partition]]

	partition(A, i, f, r):
		t = i
		perno = A[r]; scambia(A[i], A[r])
		for j = i+1 to f:
			if A[j] < perno:
				t = t+1
			scambia(A[t], A[j])
		scambia(A[t+1], A[i])
		return t+1


```ad-example
collapse: open

| i | 1|2|3|4|5|6|7|8|
|---|---|---|---|---|---|---|---|---|
|A|5|1|9|2|4|5|6|5|
|A1|5|1|9|2|4|8|6|3|
|A2|t|$\$  |||||
|A3|5|1|2|9|4|8|6|3|
|A4|5|1|2|4|3|8|6|9|
$t=5$


	partition(A, 1, 8, 6) = rank(A[6])



```

# Idea

per cercare l'elemento di rango $i$ prima testo il rango di un qualunque elemento $x$

	cerca(A, s, e, i):
		k = rank(x) in (A, S, e)
		if i == k:
			return i
		if  i < k:
			//cerco a sinistra tra i valori < x
		else:
			//cerco a destra tra i valori > x

```ad-tip
title: Tecnicalities

Quando cerco a sinistra, cerco l'elemento di rango i.

Quando cerco a destra, cerco l'elemento di rango i-k, perché se cerco  a destra "escludo" elementi e quindi il rango decresce.

```

## Worst Case

$$T(n) = max(t(left), t(right)) + \Theta(n)$$

Bisogna trovare un valore di $left$ e $right$ tale che $T(n) \in \Theta(n)\implies left+right=n-1$

$$left=\frac n2,\quad right=\frac n2-1$$

Ma va bene qualsiasi frazione di $n$

```ad-example
title: Esempio $k=\frac n7$

$$T(n)=max(T(\frac n7), T(\frac 67n)) + n$$

```

# Ottimizzare Il Partizionamento

Abbiamo un algoritmo che costa $n$ sia nel caso medio che nel caso ottimo.

```ad-question
title: Esiste un algoritmo che nel caso pessimo impiega $n$?

La scelta del perno non deve essere del tutto casuale. Devo garantire che il perno abbia "abbastanza" elementi sia a sinistra che a destra (una frazione di $n$)
```

posso formare $\lceil \frac n5 \rceil$ gruppi da 5 e li ordino.

![[Pasted image 20230302163347.png| center]]

Ottengo che la mediana di ogni gruppetto ha rango $k\geq 3$, di seguito cerco la mediana tra tutte le mediane (nell'esempio l'elemento di rango 4) .

![[Pasted image 20230302163504.png|center]]

Trovata la mediana creo un sottogruppo con l'angolo in basso a destra / in alto a sinistra e trovo ricorsivamente la mediana di quel sottogruppo.

Tutti gli elementi maggiori o uguali della mediana vanno a finire sotto, tutti quelli minori o uguali vanno a finire sopra.

Per la proprietà transitiva, tutti gli elementi del sottogruppo sono minori o uguali alla mediana (o maggiori o uguali).

	selection(A, s, e, i):
		if s == e:
			return e
		//formo gruppi da 5
		//ordino ogni gruppo
		//cerco la MM
		k = partition(A, s, e, MM)
		z = rank(MM) = k - s + 1
		if z == i:
			return MM
		else:
			if z > i:
				return cerca(A, s, k, i)
			else:
				return cerca(A, k, e, i - z)

Alla destra di MM ci stanno al più $n - (\frac 3 {10} n)$ elementi, e alla sua destra ci stanno al più $n-(\frac 3{10}n-6)$ elementi

```ad-important

Ricordare che la ricorsione avviene al più su $\frac 7{10}n+6$ elementi

```

$$T(n) = \substack{T(\frac n5)\\\text{cerco MM}} + \substack{T(\frac 7{10} n + 6) \\ \text{cerco a Sx o Dx}} + \substack{\Theta(n)\\\text{partition}} $$

$$T(n) \in \Theta(n)$$

```ad-seealso
title: Gruppi da 7

Tempo ordinamento: $\frac n7 = \Theta(1)+n$
$$T(n) = T(\frac n7) + T(\frac {10}{14}n+8) + \Theta(n)$$

![[Pasted image 20230302164118.png|center]]

Occorrono tante operazioni


```

```ad-error
title: Con i gruppi da 3 non funziona


```

# Quicksort

Mostriamo come rendere [[6. Quicksort]] ottimo

	quicksort(A,i,f):
		if i < f:
			//aiuto a scegliere il pivot attraverso la selection
			x = selection(A, i, f, (i+f)/2 )
			q = partition(A,i,x)
			quicksort(A,i,q)
			quicksort(A,q+1,f)

## Strange Quicksort

	strange_quicksort(A, i , f):
	if i < f:
		x = selection(A, i, f, 1)
		q = partition(A, i, f, x)
		strange_quicksort(A, i, q-1)
		strange_quicksort(A, q+1, f)

```ad-example
title: Trovare l'elemtno con rango 10 in $A \cup B$


```


# a1. Grafi


----

I grafi sono formati da due insiemi:

- Insieme dei vertici ($V$)
- Insieme degli archi ($E$)

$$G=(V,E)$$

# Insieme Dei Vertici

$$V=\{1,2,3,4\}$$

# Insieme Degli Archi

$$E=\{(1,2),(1,3),(2,3),(2,4),(3,4)\}$$

è formato da coppie di vertici, se le coppie sono __ordinate__ il grafo è __orientato__, se __non sono ordinate__ il grafo è __non orientato__.

# Tipi Di Grafi

## Grafo Bipartito

è un grafo che ha come vertici due insiemi separati, i cui archi collegano solo i vertici di un insieme ai vertici dell'altro, non ci sono collegamenti tra vertici dello stesso sottoinsieme.

![[Grafo bipartito.svg|center]]

```ad-example

$$R=\{1,2,3\}$$
$$L=\{4,5,6\}$$
$$V=\{L\cup R\}$$
$$E=\{(1,4), (4,3), (2,5)\}$$
```

## Mesh

I grafi a maglia possono essere impostati come dei grafi bipartiti

![[Grafo Mesh.svg|center small]]

## Aisle Graph (Modello frutteto)

![[Grafo frutteto.svg|center small]]

$$e=[(i,j),(i+1,j)]$$

## Reti

![[Grafo rete.svg|center small]]

# Dimensione Dei Grafi

$$|V|=n$$

$$|E|=m \begin{cases}
|E| \leq \frac {n(n-1)}2 & \text{grafo non orientato}\\
|E| \leq n(n-1) & \text{grafo orientato}
\end{cases}$$
Un grafo connesso (con tutti i vertici connessi tra loro) non orientato di dimensione $|V|=n$ ha un numero di archi $|E|=\frac {n(n-1)}2$ 

# Grafo Connesso

Un grafo non orientato si definisce connesso se:

$$\forall z,u \in V, z \neq u$$
$$\exists u \sim z$$
```ad-important
title: Path ($\sim$)

Sequenza di vertici tale che ogni coppia di vertici consecutivi è legato da un arco

```


### Alberi

Un grafo connesso che ha il minor numero di archi possibile ($|E|  = |V| - 1$) si chiama albero, se si rimuove un arco questo grafo non è più connesso.

![[Pasted image 20230301101608.png| center]]

Se G ha $n-1$ vertici, ma è disconnesso allora non è un grafo.

# Memorizzare Un Grafo

$$G=(V,E)$$
![[Grafo1.svg|center mid]]

## Matrice Delle Adiacenze

| |1|2|3|4|
|---|---|---|---|---|
|1| 0 | 1 | 1 | 0|
|2| 1|0|1|0|
|3| 1| 1 | 0| 1
|4| 0| 0 | 1 | 0

## Lista Delle Adiacenze

|i | $\to$ |lista| | |
|---|---|---|---|
| 1 | $\to$ | 2 | 3 |
| 2 | $\to$ | 1 | 3 |
| 3 | $\to$| 1 | 4 |
|4| $\to$|3| | 

## Vettore Delle Adiacenze

Sono 2  vettori:
- $V$ che contiene la posizione in E in cui è presente il primo arco uscente.
- $E$ in cui sono scritti quali archi sono collegati

| | V| E |
|---|---| --- |
|1|1| 2 |
|2|3| 3 |
|3|4| 3 |
|4|-| 4 |

# Complessità Di Un Grafo

A seconda se il grafo sia sparso oppure denso la complessità del suo arco varia da $\Theta(n)$ a $\Theta(n^2)$.

L'[[#Esplorare Un Grafo|esplorazione]] di un grafo impiega $\Omega(V+E)$ (complessità intrinseca), ma a seconda della sua struttura dati può costare:
- Lista delle adiacenze, vettore delle adiacenze $O(V+E)$
- Matrice delle adiacenze $O(v^2)$

# Esplorare Un Grafo

Dato un grafo connesso, esplorare G vuol dire estrarre un albero che esplora tutti i vertici di G

## Visita in Profondità (DFS-visit)

Depth First Search visit.

La DFS-visit è preceduta dalla procedura di inizializzazione

	initialize(G=(V,E))
		for v in V:
			color(v) = white
			P(v) = nil

L'obiettivo è quello di estrarre un __albero di copertura__ radicato nel primo vertice passato alla procedura  dfs-visit.

un vertice è:
- white: non visitato
- gray: visitato
- black: visitati tutti gli archi

Ogni volta che tocco un vertice mai esplorato vado a esplorare tutti i vertici a esso connessi.

	dfs-visit(G=(V.E), u):
		color(u) = grey
		for v in Adj(u):
			if color(v) == white:
				(u,v) in T
				P(v) = u
				dfs-visit(G, v)
			else if v != P(u):
				(u,v) in B
			else
				(u, v) in T
		color(u) = black

```ad-info

- Un grafo connesso è un __albero__ se _non esistono_ archi in $B$.
- Un grafo connesso ha un __ciclo__ se _esistono_ archi in $B$


```

## Grafo Orientato

Esplorazione di $G,\; v \in V$, visibilità di $v$ in $G$

	dfs-visit(G, v, time):
		color(v) = gray
		time++;
		d(v) = time
		for u in adj(v):
			if color(u) == white:
				(v, u) in T
				P(u) = v
				dfs-visit(G, u, time)
			if color(u) == gray:
				(v, u) in Backward
			if color(u) == black and d(v) < d(u): 
				(v, u) in Forward
			else:
				(v, u) in Cross
		color(v) == black
		time++
		f(v) = time

```ad-info

- Un grafo connesso _senza cicli_ (senza archi Backward) si dice __Direct Acyclic Graph (DAG)__
- Un grafo orientato aciclico ha almeno un __sink__, cioè un vertice senza archi uscenti.
```

### Sort Topologico O Linearizzazione

è un ordinamento dei vertici: $\forall e= (u,v)$ $u$ precede $v$ nell'ordinamento dei vertici 

	sort-topologico(G, DAG)
		1. DFS(G)
		2. inserisci in testa ad una lista L ogni nodo che diventa nero
		3. return L

	repeat
		sia s un sink in G

```ad-missing
title: Chiedere a qualcuno slide 12 [[topologicalsort-sinkuniversale-cfc.pdf]]


```

``````ad-question


Cercare un sink in G rappresentato dalla matrice delle adiacenze

```ad-check
title: Soluzione semplice (non cerca sink universale)

	t = 1
	trovato = false
	while t < |v| and !trovato:
		if !sink-test(G, t):
			t++
		else:
			trovato = true
	return t

	sink-test(G, t):
		j = 1
		while j <= n and G[t, j] == 0: 
			j++
		return !(G[t, j] == 1)

La complessità nel worst case è $O(v^2)$ 
```


``````

### Sink Universale

	trova-sink-universale(G):
		i = 1
		j = 1
		while (j <= n) && (i <= n):
			if G[i, j] == 1:
				i++
			else:
				j++
		if i > n:
			return false
		else:
			return test-sink(G, j)

L'algoritmo appena proposto non funziona per trovare un sink singolo, ma __solo per il sink universale__


# Componenti Fortemente Connesse

Per ogni coppia $(u, v) \in V$ di vertici esiste un cammino $u \to v$ che li lega

![[fortemente_connesso.svg|center]]
$$(2,4) \to2,3,4$$
$$(4,2)\to4,5,1,2$$

## Conta CFC

	dfs(G = (V, E)):
		for v in V:
			color(v) = white
			P(v) = nil
		num_cc = 0
		for i = 1:|v|
			if color(i) == white:
				num_cc++
				dfs-visit(G, i)

num_cc indica le componenti connesse

## Associare a Ogni Vertice La Componente Connessa

Basta chiamare dfs-visit passando il valore di num_cc

	dfs-visit(G, i, num_cc)



```ad-example

![[esempio.svg|center]]

| | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| color| g | g | g | g | g | g|
|P| nil | 1 | 2 | 3 | 4 | 5 |
|

```ad-missing
title: Riguardare 15-03-2023


```

## Grafo Delle Componenti Fortemente Connesse (C.F.C.)

i vertici sono componenti fortemente connesse e gli archi sono gli archi del grafo originario che vanno da una CFC a un'altra.

$$G^{scc} = \{V;E\}$$
![[componenti.svg|center  mid]]
```ad-info

Una componente fortemente connessa corrisponde a un albero i cui vertici sono i vertici della componente fortemente connessa

```

```ad-important

Per disegnare questo grafo mi interessano solo gli archi che vanno da vertici appartenenti a componenti fortemente connesse

```

``````ad-example
title: supponiamo per assurdo che il grafo non sia un DAG

![[non_dag.svg|center]]

```ad-failure

Esistendo l'arco B, l'intero grafo diventa una componente fortemente connessa, non rendendolo più un $G^{scc}$

```

``````
 

# Grafo Trasposto

Grafo con tutti gli archi invertiti

```ad-example
 ![[trasposto.svg|center]]


ho trovato un albero radicato in 1

```

|       | 1   | 2   | 3   | 4   | 5   | 6   |
| ----- | --- | --- | --- | --- | --- | --- |
| color | g   | g   | g   | g   | g   | g   |
| P     | nil | 3   | 1   | nil | nil | nil |
| d     | 1   | 3   | 2   | 7   | 9   | 11  |
| h     | 6   | 4   | 5   | 8   | 10  | 12  |

```ad-info

Se calcolo il traspoto di un $G^{scc}$ ottengo un __reverse sort topologico__

```


# Quadrato Di Un Grafo

Vogliamo calcolare il grafo $G^2$ che ha gli stessi vertici di $G$ ma ha come vertici $E^2$

$$G^2=(V, E^2)$$

$$e \in E \iff e = e_1 e_0, e_1 \in E, e_0 \in E$$
$$(i, j) \in E^2 \implies (i, w) \in E \wedge (w, j) \in E$$
![[immagini/Algoritmi/Untitled Diagram.svg|center big]]

Il calcolo di $G^2$ richiama il calcolo del prodotto di due matrici:
$$P = A \cdot B$$

$$P_{ij}= \sum_{k=1}^n{a_{ik} \odot b_{kj}} $$

	square( G ):
		for r = 1:n
			for c = 1:n
				G2[r, c] = 0
				for k = 1:n
					if G[r, k] and G[k, c]:
						G2[r, c] = G2[r, c] or 1

```ad-important
title: Calcolo di $G^*$ 

$$G^* = G \cup G^2$$

	g-star( G ):
		G2 = square(G)
		for r = 1:n
			for c = 1:n
				GS[r, c] = G[r, c] or G2[r, c]


	star(G, GS):
		for r = 1:n
			for c = 1:n
				GS[r, c] = G[r, c]
				for k = 1:n
					if G[r, k] and G[k, c]:
						GS = GS[r, c] or 1

```

# Breadth First Search

	BFS(G, s * source):
		for v in V:
			color(v) = white
			P(v) = nil
		color(s) = gray
		EnQueue(Q, s)
		while (Q not empty):
			u = DeQueue(Q)
			for v in adj(u):
				if color(v) = white:
					(u, v) in T
					P(v) = u
					color(v) = gray
					EnQueue(Q, v)
			color(u) = black

```ad-seealso
collapse: open
title: Calcolo della distanza

	BFS(G, s * source):
		for v in V:
			color(v) = white
			P(v) = nil
			d(v) = infinite
		color(s) = gray
		d(s) = 0
		EnQueue(Q, s)
		while (Q not empty):
			u = DeQueue(Q)
			for v in adj(u):
				if color(v) = white:
					(u, v) in T
					P(v) = u
					color(v) = gray
					d(v) = d(u) + 1
					EnQueue(Q, v)
			color(u) = black

```



```ad-note

- d(v) dipende solo dalla sorgente
- d è __crescente__
- BFS(G, s) visita ogni vertice raggiungibile da s
- dist(s, s) = 0 = d(s)
- dist(s, v) = distanza da s a v = d(v)
```

## Diametro
Dato un grafo G trovare il diametro di Gs

![[Untitled Diagram 1.svg|center]]

	for u,v in VxV:
		if d(u, v) > max:
			max = d(u, v)
	return max


## Archi Nella BFS

Gli archi sono denominati rispetto alla loro posizione dei loro estremi in T:

- __back__ verso antenato
- __forward__ verso discendente
- __cross__ altrimenti

Nel grafo non orientato esistono solo gli archi cross

## Euler Tour

	visit(G, L, v):
		C = 0
		u in v
		while dist(u) > 0:
			let w in adj(u)
			delete (u, w)
			dist(u)--
			add u to C
			if dist(u) > 0:
				add u to L
			u = w
		return C

	euler-tour(G):
		T = 0
		L = any vertex in G
		while L != 0:
			remove v from L
			C = visit(G, L, v)
			if location in T = nil:
				T in C
			else:
				introduce C before  locator of v in T

# a2. Grafi pesati


----

 $$G = (V, E)$$

$$w: E \to R$$

$$(u, V, w(u,v))$$

Tra tutti gli alberi di esplorazione cerchiamo l'albero di cammini minimi radicato in $V_0$ ossia$$\forall v, P=V_o \sim > v : w(P) \text{ minimo}$$

Per i grafi pesati lo __shortest path__ corrisponde al cammino di costo minimo rispetto al peso degli archi.

```ad-question
title: Perché abbiamo un albero di cammini minimi?

Supponiamo per iniziare che tutti i cammini siano distinti (non abbiamo contraddizione perché è  ancora un albero).

Se 2 cammini condividono un nodo, supponendo per assurdo che i 2 cammini siano distinti fino al nodo condiviso, possiamo riscriverli.

Essendo i due cammini ottimi i costi dei due percorsi devono essere uguali (altrimenti si invalida l'ottimalità di uno dei due).

Essendo uguali possiamo eliminare uno dei due cammini così da ottenere l'albero dei cammini minimi

```

```ad-hint
title: Osservazione

I cammini minimi sono semplici (non hanno cicli), se esistono cicli di costo negativo __non esiste__ soluzione al cammino di costo minimo

```

# Cammini Minimi Da Sorgente Singola

- $Q$: coda di priorità rispetto le etichette $d(v), \forall v \in V$
- $d(u) = \delta(s, u)$ quando $u$ è estratto da $Q$

## Relax

Nuova Operazione per Ri-etichettare

	relax(u, v, w(u,v)):
		if d(v) > d(u) + w(u,v):
			d(v) = d(u) + w(u,v)
			P(v) = u

## Dijkstra

Il procedimento ricorda la [[a1. Grafi#Visita in Profondità (DFS-visit)|DFS]]

	dijkstra(G, w*E->R+, s):
		for v in V:
			color(v) = white
			d(v) = + infinito
			P(v) = nil
		d(s) = 0
		sol = 0
		Q = makeQueue(d(v), V)
		while Q is not empty:
			u = extract_min(Q)
			for v in Adj(u) and v not in sol:
				relax(u, v, w(u,v))
			sol = sol + {u}

## Decrease-key

	decrease-key(H, i, key):
		H[i] = key
		while (i > 1) and (H[i] < H[i/2]):
			scambia(H[i], H[i/2])

## Heap Relax

	heap-relax(u, v, w(u, v)):
		if d(v) > d(u) + w(u, v):
			d(v) = d(u) + w(u, v)
			H(v) = u
			decrease-key(H, pos(v), d(v))

mantiene le etichette all'interno di un min-heap

- pos(v) corrisponde al nodo (i)
- d(v) corrisponde alla chiave

Senza mantenere una corrispondenza univoca tra i vertici del grafo e le loro posizioni in H

## Dijkstra Con Heap

	dijkstra(G, w*E->R+, s):
		for v in V:
			color(v) = white
			d(v) = + infinito
			P(v) = nil
		d(s) = 0
		sol = {}
		H = makeMinHeap(d(v) for v in V)
		while H in not empty:
			u = extract_min(H)
			for v in Adj(u) and v not in sol:
				heap-relax(u, v, w(u,v))
			sol = sol + {u}


```ad-important

è necessario stabilire una corrispondenza univoca tra i vertici del grafo e i nodi dell'heap

```

Per l'algoritmo di Dijkstra per il calcolo dei cammini minimi da sorgente singola è conveniente usare lo heap binario se il grafo è rappresentato con la lista delle adiacenze e $|E| \in O(\frac {V^2}{\log {|V|}})$

``````ad-check
title: Correttezza


$$\forall v \in V: d(v)  = \delta (s, v), v \in sol$$

$d(s) = \delta (s,s) = 0$ passo base

$\exists \bar v$ primo nodo per cui $d(\bar u)  \neq \delta (s, \bar v))$ che è minimo della coda $d(w) \leq d(\bar v)$ perché estratto $v$ ho un cammino minimo quando estraggo $\bar u$ e il suo costo è maggiore di $d(\bar v)$

Dijkstra può tollerare archi di costo negativo **uscenti** dalla sorgente

![[Archi_neg.svg|center]]

```ad-note
title: Osservazione

$$s \sim u \to r$$
Se $(u,v) \in \delta (s, v)$
![[percorso_da_sorgente.svg|center]]

```

$\exists$ sicuramente un cammino minimo di un arco uscente da s, se $(s, v)$ $$d(s) = \delta (s,s)$$

``````

## Bellman-Ford

Se esistono archi con costo negativo c'è il rischio di avere dei cicli di costo negativo

	BellmanFord(G, w: E -> R): boolean
		TRUE se esiste un ciclo negativo
		FALSE se non esiste

```ad-note
title: Osservazione

Se la lunghezza del cammino minimo $\geq n$ allora esiste un ciclo di costo negativo

```

	BellmanFord(G = (V, E); w:V -> E):
		crea una lista L di tutti gli archi
		for i = 1:(|V| - 1)
			rilassa tutti gli archi in  L nell'ordine prestabilito
		for e = (u,v) in L:
			if d(v) > d(u) + w(u, v):
				return TRUE
		return FALSE

```ad-check
title: Correttezza

Se conosco che cammino ottimo da $s \to u$ è costituito dagli archi
$$(s, v) = e_1, e_2,...,e_r = (z, u)$$
e rilasso nell'ordine $$e_1,e_2,...,e_r$$ trovo il costo $d(u) = \delta(s, u)$

Non conosco l'ordine, per cui per ogni posizione $i$ provo tutti gli archi e sicuramente passerò per l'arco che è l'iesimo del cammino ottimo

```

I cammini minimi sono semplici, hanno $\leq n -1$ archi.

Se trovo da rilassare un arco in posizione $n$ allora esiste un cammino con un ciclo di costo negativo.

### Complessità in Tempo

- creo la lista $|E|$
- rilasso tutti gli archi $|V| -1$ volte $$O(VE)$$
- rilasso ancora gli archi$$O(E)$$
Complessità: $O(VE)$, non dipende dalla rappresentazione.

Bellman-Ford è quindi **più costoso** di dijkstra, ma risolve il problema degli archi negativi

# Cammini Minimi per Coppia Di Vertici

## Soluzione 1

Basta chiamare Dijkstra o Bellman-Ford per ogni vertice

## Soluzione 2

Algoritmi ad-hoc:

- Floyd-Warshall
- Metodo analogo alla moltiplicazione di matrici

## Floyd Warshall

$$\forall i,j\quad d(i,j) = \delta(i, j)$$

Lavora in $n = |V|$ iterate, ad ogni iterata rende visibile un nodo nuovo

$$d^{(0)}(i, j) = \begin{cases} 
w(i,j) &  (i, j) \in E\\
+\infty & (i, j) \notin E\\
0&i=j
\end{cases}$$

$$\Pi^{(0)}(i,j) = \begin{cases} 
i & (i,j) \notin E\\
nil & else
\end{cases}$$

$$\Pi^{(1)}(i,j) = \begin{cases}
\Pi^{(0)}(i,j)&d^{(1)}(i,j)= d^{(0)}(i,j)\\
\Pi^{(0)}(1, j)& d^{(1)}(i,j) = d^{(0)}(i,1) + d^{(0)}(1,j)
\end{cases}$$
$$d^{(2)}(i,j) = i \sim \{1, 2\} \sim j$$
$$d^{(k)}(i,j) = \min\{d^{(k-1)}(i, j), d^{(k-1)}(i, k) + d^{(k-1)}(k, j)\}$$


```ad-example
collapse:open

![[EsempioFloyd.svg|center]]

| d0  |  1  |  2  |  3  |  4  |
|:---:|:---:|:---:|:---:|:---:|
|  1  |  0  |  3  |  +  |  1  |
|  2  |  3  |  0  |  2  |  1  |
|  3  |  +  |  2  |  0  |  1  |
|  4  |  1  |  1  |  1  | 0    |

| d1  |  1  |  2  |  3  |  4  |
|:---:|:---:|:---:|:---:|:---:|
|  1  |  0  |  3  |  +  |  1  |
|  2  |  3  |  0  |  2  |  1  |
|  3  |  +  |  2  |  0  |  1  |
|  4  |  1  |  1  |  1  |  0  | 

| d2  |  1  |  2  |  3  |  4  |
|:---:|:---:|:---:|:---:|:---:|
|  1  |  0  |  3  |  5  |  1  |
|  2  |  3  |  0  |  2  |  1  |
|  3  |  5  |  2  |  0  |  1  |
|  4  |  1  |  1  |  1  |  0  | 

| d3  |  1  |  2  |  3  |  4  |
|:---:|:---:|:---:|:---:|:---:|
|  1  |  0  |  3  |  5  |  1  |
|  2  |  3  |  0  |  2  |  1  |
|  3  |  5  |  2  |  0  |  1  |
|  4  |  1  |  1  |  1  |  0  |

| d4  |  1  |  2  |  3  |  4  |
|:---:|:---:|:---:|:---:|:---:|
|  1  |  0  |  2  |  2  |  1  |
|  2  |  2  |  0  |  2  |  1  |
|  3  |  2  |  2  |  0  |  1  |
|  4  |  1  |  1  |  1  |  0  |

$$d^2(1,3) = \min\{d^1(1,3) = +, \quad d^1(1,2) + d^1(2,3) = 5\} = 5$$
$$d^4(1,2) = \min\{d^3(1,2) = 3, \quad d^3(1,4) + d^3(4,3) = 2\} = 2$$
$$d^4(1,3) = \min\{d^3(1,3) = 5, \quad d^3(1,4) + d^3(4,3) = 2\} = 2$$

```

### Complessità in Tempo

$$O(\substack{V\\\text{iterate}} \cdot \substack{V^2\\d^{()}(i,j)} \cdot \substack{c\\\text {riempimento celle}}) = O(V^3) $$
## Analogo Alla Moltiplicazione Di Matrici (Metodo Tropicale)

$d^{(l)} (i, j)$ = costo del cammino minimo di lunghezza $\leq l$

Il cammino minimo di lunghezza $l$ si trova estendendo il cammino di lunghezza $l-1$ con un nuovo arco

$$d^{(0)}(i, j) = \begin{cases}
0 & i=j\\
+\infty &i \neq j
\end{cases}$$
$$d^{(1)} = \begin{cases}
0  & i=j\\
w(i, j) & (i, j) \in E\\
+ \infty & (i, j) \notin E
\end{cases}$$
$$d^{(l)}(i,j) = \substack{\min \\ 1 \leq z \leq n} \{d^{(l-1)} (i, z) + w(z, j)\}$$

```ad-question
title: Come ricostruire la soluzione?

Bisogna mantenere traccia dei predecessori

$$\Pi^{(l)}(i, j) = \text{valore di z che restituisce d(i,j)} = argmin (d^{(l)}(i,j))$$

```

### Complessità Base
$$O(V^3) \cdot O(V) \implies O(V^4)$$
### Fastest
$$d^l = d^{\frac l2} \cdot d^{\frac l2} \implies O(V^3\log V)$$

```ad-important
title: Algoritmo più veloce

Per calcolare i **cammini minimi tra tutte le coppie**, l'algoritmo più veloce rimane appicare [[#Dijkstra Con Heap]] V volte.

$$V (V \log V + E)$$

```

# Algoritmo Di Johnson

[[#Bellman-Ford]] trova i cicli di costo negativo raggiungibili dalla sorgente, quelli non raggiungibili non vengono rilevati

## SuperSource

Aggiungo un nodo $s$ chiamato supersource che è connesso a tutti gli altri vertici con *archi di costo 0*.

In sostanza è [[#Bellman-Ford]] con aggiunti
$$E' = \{(s,v) : \forall v \in V\} $$
$$G' = \{V \cup s, E \cup E'\}$$

Se non esistono cicli di costo negativo
$$ \hat w(i,j)= d(i) + w(i, j) - d(j) $$
$$ \hat w(i,j) > 0 $$
non altera il costo dei cicli, ma altera della stessa quantità ogni cammino $s \sim t$ 


## Passaggi

- Costruisco G'
- Bellman-Ford(G')
- if not exist cicli negativi
	- ricalcolo i pesi $\hat w (i,j)$ 
	- $\forall v \in V$
		- Calcolo Dijkstra(G,v) $\implies \forall (i,j)\quad \hat d(i,j)$ 
		- Ricalcolo $d(i, j) = \hat d(i, j) - d(i) + d(j)$

### Costo Passo 1
Costruisco G'
$$G' = (V' + E')$$
$$|V'| = |V| + 1 = \Theta(V)$$
$$|E'| = |E| + |V| \leq q|E| = \Theta (E)$$
### Costo Passo 2

Bellman-Ford (G')

$$|V'|\cdot|E'|=\Theta(V)\cdot\Theta(E)$$

### Costo Passo 3

if not exist cicli negativi ricalcolo i pesi e eseguo dijkstra

$$\Theta(E) |V| ( V' \log V' + E')$$

### Costo Passo 4

ricalcolo $d(i,j)$ 

$$\Theta(V^2)$$


# a3. Alberi


----

# Minimum Spanning Tree

Tra tutti gli alberi di copertura, quello il cui costo è minimo.

In un grafo con tutti archi di costo diverso, l'MST è unico, ma può essere radicato in tanti modi quanti sono i vertici

```ad-note
title: Regola Blue

Considerato un taglio S: $V = V_1 \cup V_2, V_1 \cap V_2 = \emptyset$ 

$$S = \{e = (l,r) : l \in V_1, r \in V_2\}$$

Si applica se S non ha archi blue, colora di blue l'arco di costo minimo in S

```

```ad-failure
title: Regola Rossa

Considera un ciclo $C$.

Si applica se $C$ non ha archi rossi, colora di rosso l'arco di peso massimo in $C$

```

## Metodo per Trovare MST

Soddisfa il seguente invariante dopo ogni scelta: $\exists$ MST che contiene tutti gli archi blue e nessun arco rosso

	while exists e in E not colored:
		applica la regola blue o rossa
	return MST = {e : color(e) = blue}

## Algoritmo Di Kruskal

- ordino gli archi in senso crescente rispetto $w(e)$ in L:
- Foresta di alberi costituiti da un solo vertice

Visita tutti gli archi in L e per ogni arco procede come segue:

$\forall e = (v_1, v_2)$

- se $v_1$ e $v_2$ __non__ appartengono allo stesso albero della foresta -> coloro $e$ di blue
$$MST = MST \cup e=(v_1,v_2)$$
- se $v_1$ e $v_2$ appartengono allo stesso albero -> coloro $e$ di rosso e lo escludo dal MST

```ad-seealso

	test(v1, v2): //appartengono allo stesso albero
		dfs-visit(v1):
			verifico se v2 è raggiungibile da v1
		mantengo un insieme per ogni albero della foresta
		union(Sa, Sb) fonde i due insiemi Sa e Sb
		find(vi) ritorna l'insieme in cui si trova vi

```


	kruskal(G = (V, E); w):
		L = archi ordinati
		MST = empty
		Crea |V| insiemi, un insieme per ciascun vertice
		for e = (vi, vj) nell'ordine L:
			if find(vi) == find(vj):
				e = (vi, vj) rosso
			else
				union(find(vi), find(vj))
				MST = MST + {vi, vj}

### Complessità

Ordinamento : $O(|E| \log |E|) \simeq O(|E| \log |V|)$

Union: $(|V| - 1)$

Find: $(2|E|)$

La complessità ultima dipende dalla struttura dati che rappresenta gli insiemi

## Algoritmo Di Prim

```ad-important

RELAX di Prim è  diverso da quello di [[a2. Grafi pesati#Relax|Dijkstra]]

	relax(u, v, w(u, v)):
		if d(v) > w(u, v):
			d(v) = w(u, v)
			P(v) = u

```

Per tutto il resto l'algoritmo di Prim è lo stesso dell' [[a2. Grafi pesati#Dijkstra|algoritmo  di Dijkstra]]

	prim(G = (V, E), w: E -> R):
	INITIALIZE
	Q = {d(v) : for v in V}
	sol = empty
	while Q not empty:
		u = extract-min(Q)
		sol = sol + u
		for v in Adj(u) and v not in sol:
			relax (u, v, w(u, v))


```ad-question
title: Come posso trasformare i pesi negativi in pesi non negativi e mantenere le posizioni

I pesi degli archi possono trasformarsi sempre in pesi non negativi usando la regola
$$\hat w(e)  = w(e) + |min(w(e)) : w(e) < 0|$$

Dopo la trasformazione MST è lo stesso, il peso del problema originale è lo stesso del problema modificato

```

# Alberi Binari Di Ricerca

Rappresentiamo un albero binario come una linked list i cui nodi sono gli oggetti della lista, ogni oggetto ha una chiave univoca e dei puntatori che indicano gli oggetti vicini.

```ad-example

Dato un albero T, la sua radice ($T.root$) ha padre $x.p = NIL$.

I figli a sinistra e a destra sono rappresentati dagli attributi $left$ e $right$, se non hanno figli l'attributo è $NIL$.

![[binarytree.png|center]]

```

Per gli alberi con $n$ figli, si possono usare collegamenti ai nodi a destra e sinistra, utilizzando la stessa quantità di spazio.

![[binarytree2.png|center]]

Ogni nodo è connesso al suo parent $p$, ma invece di avere $n$ puntatori per ogni nodo figlio ha solo 2 nodi (_left-child_ e _right-sibling_).

In un albero binario di ricerca le chiavi sono sempre memorizzate in modo da soddisfare una proprietà:

```ad-important

Dato $x$ nodo in un albero binario di ricerca:

- se $y$ è un nodo nel sottoalbero a __sinistra__ di $x$ allora $y.key \leq x.key$
- se $y$ è un nodo nel sottoalbero a __destra__ di $x$ allora $y.key \geq x.key$

```

![[binarytree3.png|center]]

## Inorder Tree Walk

Grazie a questa proprietà possiamo stampare tutte le chiavi in modo ordinato semplicemente tramite algoritmo ricorsivo

	INORDER-TREE-WALK(x):
		if x not NIL:
			INORDER-TREE-WALK(x.left)
			print x.key
			INORDER-TREE-WALK(x.right)

esistono anche algoritmi chiamati __preorder-tree-walk__ che stampa la radice __prima__ dei valori dei suoi sottoalberi, e __postorder-tree-walk__ che stampa la radice __dopo__ i valori dei suoi sottoalberi

## Ricerca

	Tree-search(x, k):
		if x == NIL or k == x.key:
			return x
		elseif k < x.key:
			return Tree-search(x.left, k)
		else:
			return Tree-search(x.right, k)

	Iterative-tree-search(x k):
		while x not NIL and k not x.key:
			if k < x.key:
				x = x.left
			else:
				x = x.right
		return x

## Minimo E Massimo

	Tree-minimum(x):
		while x.left not NIL:
			x = x.left
		return x

	Tree-maximum(x):
		while x.right not NIL:
			x = x.right
		return x

## Successore E Predecessore

	Tree-successor(x):
		if x.right not NIL:
			return Tree-minimum(x.right)
		else:
			y = x.p
			while y not NIL and x == y.right:
				x = y
				y = y.p
			return y

Tree-predecessor è simmetrico a Tree-successor.

## Inserimento E Eliminazione

Queste operazioni cambiano la rappresentazione dell'albero.

	Tree-insert(T, z):
		x = T.root
		y = NIL
		while x not NIL:
			y = x
			if z.key < x.key:
				x = x.left
			else:
				x = x.right
		z.p = y
		if y == NIL:
			T.root = z
		elseif z.key < y.key:
			y.left = z
		else:
			y.right = z


	Transplant(T, u, v):
		if u.p == NIL:
			T.root = v
		elseif u == u.p.left;
			u.p.left = v
		else:
			u.p.right = v
		if v not NIL:
			v.p = u.p

	Tree-delete(T, z):
		if z.left == NIL:
			transplant(T, z, z.right)
		elseif z.right == NIL:
			Transplant(T, z, z.keft)
		else:
			y = Tree-minimum(z.right)
			if y not z.right:
				Transplant(T, y, y.right)
				y.right = z.right
				y.right.p = y
			Transplant(T, z, y)
			y.left = z.left
			y.left.p = y

^6d280d

# Alberi Rosso-Neri

La ricerca di un albero binario è efficiente se la dimensione è piccola, altrimenti non è più veloce delle linked list. Gli alberi rosso-neri sono uno dei tanti schemi "bilanciati" per garantire un'eseccuzione in tempo $O(\log n)$ nel caso peggiore.

```ad-info

Un albero rosso-nero è un albero binario di ricerca con un bit extra per memorizzare il suo __colore__, l'albero è approssimativamente bilanciato e la sua altezza con $n$ nodi è al più $2\log(n+1)$ che è $O(\log n)$

```

Questi alberi rispettano le seguenti proprietà:

- Ogni nodo è _rosso_ o _nero_
- La root è nera
- Ogni foglia (NIL) è nera
- Se un nodo è rosso, allora entrambi i suoi figli sono neri
- Per ogni nodo, tutti i percorsi semplici dal nodo alle foglie discendenti contengono lo stesso numero di nodi neri

Per rappresentare NIL si usa un nodo a parte (T.NIL) di colore nero.

```ad-important

Dato che l'altezza dell'albero è $O(\log n)$ allora anche le operazioni sugli alberi binari impiegano al più $O(\log n)$.


Dato che queste operazioni modificano la struttura dell'albero, potrebbero invalidare le 5 proprietà

```

## Rotazioni

Per ristabilire le proprietà che vengono modificate, i colori e i puntatori devono cambiare. Per cambiare i puntatori si utilizza la __rotazione__ che può essere a sinistra o a destra.

![[rotation.png|center]]

## Inserimento

Per inserire un nodo in un albero rosso-nero mantenendo le proprietà bisogna modificare [[#^6d280d|Tree-insert]]

	RB-insert(T, z):
		x = T.root
		y = T.NIL
		while x not T.NIL:
			y = x
			if z.key < x.key:
				x = x.left
			else:
				x = x.right
		z.p = y
		if y == T.NIL:
			T.root = z
		elseif z.key < y.key:
			y.left = z
		else:
			 y.right = z
		z.left = T.NIL
		z.right = T.NIL
		z.color = RED
		RB-INSERT-FIXUP(T, z)

Ci sono 4 differenze tra i 2 algoritmi:

1. Tutte le istanze di NIL sono rimpiazzate da T.NIL
2. Per mantenere la struttura corretta $z.left$ e $z.right$ diventano T.NIL
3. z viene colorato di rosso
4. Dato che colorando di rosso z si potrebbe generare una violazione delle proprietà, viene chiamato RB-INSERT-FIXUP per ripristinare le proprietà rosso-nere

## RB-INSERT-FIXUP

Descrivendo la stuttura di un albero rosso-nero bisogna riferirsi spesso al fratello di un nodo genitore (nodo zio).

```ad-question
title: Quali violazioni delle proprietà possono verificarsi al chiamare di RB-INSERT-FIXUP?

le proprietà che possono essere violate sono 2:

2. La radice deve essere di colore nero
4. Un nodo rosso non può avere un figlio rosso

```

### Caso 1

Sia $z.p$ che $y$ sono rossi, di conseguenza il loro padre ($z.p.p$) è nero, il suo colore si può trasferire un livello più in basso risolvendo il problema che $z$ e $z.p$ sono entrambi rossi.

![[rn-caso1.png|center]]

### Caso 2

Lo zio di $z$ ($y$) è nero e $z$ è un figlio destro, si ruota a _sinistra_ (su z) trasformando la situazione in [[#caso 3]]

### Caso 3

Lo zio di $z$ ($y$) è nero e $z$ è un figlio sinistro, si cambiano i colori e si ruota a _destra_ (su z.p.p), preservando la proprietà 5

![[rn-caso23.png|center]]

```ad-example

![[esempio_rn.png|center]]
```


# a4. Tabelle Hash


----

Molte applicazioni richiedono un insieme dinamico che supporta le _operazioni dizionario_ `INSERT, SEARCH, DELETE`.

Una struttura affidabile per implementare i dizionari sono le __tabelle hash__, che anche se nel caso pessimo performano come le linked list, nella pratica sono molto veloci, impiegando un tempo medio di $O(1)$.

# Tabelle Ad Accesso Diretto

è una tecnica semplice che funziona quando l'insieme totale delle chiavi possibili ($U = \{0,1,...,m-1\}$) è piccolo. Per rappresentare l'insieme dinamico si usa un'array (_tabella ad accesso diretto_) denotata da $T[0:m-1]$, ogni posizione corrisponde ad una possibile chiave di $U$

![[direct-access.png|center]]

## Operazioni

Le operazioni disponibili impiegano tutte $O(1)$:

	DIRECT-ACCESS-SEARCH(T, k):
		return T[k]

	DIRECT-ACCESS-INSERT(T, x):
		T[x.key] = x

	DIRECT-ACCESS-DELETE(T, x):
		T[x.key] = NIL

# Tabelle Hash

Il problema delle [[#Tabelle Ad Accesso Diretto]] è che dipendono dalla dimensione di $U$, che se supera la dimensione massima della memoria diventa impossibile da rappresentare. Un secondo problema è che l'insieme di chiavi effettivamente usate potrebbe essere molto più piccolo di $U$, e quindi la maggior parte dello spazio utilizzato sarebbe inutile.

Una __tabella hash__ richiede molto meno spazio di una tabella ad accesso diretto, con un'utilizzo di memoria di $\Theta (|K|)$ mantenendo il tempo di ricerca di $O(1)$.

```ad-important

La "fregatura" consiste nel tempo di ricerca che rappresenta il caso __medio__, e non il __peggiore__

```

## Funzione Di Hash

Nell'accesso diretto l'elemento con chiave k viene memorizzato nello slot k, mentre nelle tabelle hash si usa una __funzione di hash__ ($h$) per calcolare il numero di slot di $k$, così che l'elemento vada nello slot $h(k)$.

In questo modo si riduce la dimensione dell'array, che invece di avere dimensione $|U|$ avrà dimensione $m$.

```ad-example

Un esempio semplice, ma non molto buono, è la funzione: $$h(k) = k \mod m$$
C'è però un problema: due chiavi potrebbero puntare allo stesso slot, chiameremo questa situazione __collisione__

```

## Collisioni

La soluzione ideale sarebbe di evitare le collisioni, scegliendo magari una funzione di hash adatta.

Un'altra idea è quella di far sembrare $h$ "casuale", ma ricordandosi che la funzione deve essere __deterministica__, ovvero che dato lo stesso $k$ la funzione deve avere sempre lo stesso risultato.

Dato che $|U|  > m$ ci saranno sempre almeno due chiavi che avranno lo stesso valore hash, rendendo impossibile evitare le collisioni.

```ad-check

Una funzione ideale $h$, avrebbe, per ogni possibile $k$, un output che sia un elemento che sia scelto in modo casuale e indipendente nel range $\{0,1,...,m-1\}$, una volta scelto il valore ogni chiamata  $h(k)$ ritorna sempre quel valore

```

### Concatenamento

Consiste nell'usare delle linked list per ogni slot dell'array, ogni volta che la funzione di hashing genera lo stesso risultato, l'elemento viene aggiunto alla linked list di quella chiave.

![[Pasted image 20230615165741.png|center]]

Quando le collisioni vengono risolte attraverso il concatenamento, le operazioni di dizionario sono semplici da implementare, e hanno un tempo di esecuzione di $O(1)$:

- L'inserimento presuppone che l'elemento da inserire non sia nella lista, se lo è bisogna cercare a scapito di un costo aggiuntivo
- La ricerca nel tempo peggiore è proporzionale alla lunghezza della lista
- L'eliminazione impiega $O(1)$ se prende come input l'elemento $x$ e non la sua chiave, rendendo non necessaria la ricerca.

```ad-question
title: Quanto impiega l'hashing con concatenamento?

Il tempo di esecuzione __peggiore__ è nell'ordine di $\Theta(n)$, e richiede che tutti gli $n$ elementi vadano sullo stesso slot creando una lista lunga $n$.

Il tempo di esecuzione __medio__ dipende da quanto bene la funzione $h$ distribuisce le chiavi tra gli slot, arrivando ad una possibilità che due chiavi collidano di $1/m$ 

```

```ad-teorema
Dato il fattore di caricamento $\alpha = n/m$

In una tabella hash le cui collisioni sono risolte tramite concatenamento, la ricerca in media impiega $\Theta(1 + \alpha)$, assumendo una funzione di hashing uniforme e indipendente

```

### Indirizzamento Aperto

Descriviamo l'indirizzamento aperto come un metodo per risolvere le collisioni che __non utilizza spazio__ al di fuori della tabella hash.

- Tutti gli elementi occupano la tabella stessa
- Ogni valore della tabella contiene un elemento dell'insieme dinamico oppure NIL
- Nessuna lista o altri elementi sono memorizzati fuori la tabella
- La tabella può essere riempita così che non possono essere inseriti altri elementi
- Una conseguenza è che il fattore di caricamento $\alpha$ non può mai superare 1

Le collisioni sono gestite in questo modo: quando un elemento deve essere inserito, viene posizionato nella sua "prima-scelta" (first-choice) se possibile. Se non possibile (la posizione è occupata), il nuovo elemento viene inserito nella sua "second-choice", e così via fino a che non si trova uno spazio vuoto dove poter piazzare il nuovo elemento.

#### Ricerca

Per __cercare__ un elemento bisogna esaminare il suo slot preferito per diminuire le preferenze fino a che non trovi l'elemento desiderato, oppure uno slot vuoto.

La procedura __HASH-SEARCH__ richiede in input una tabella e una chiave, ritornando la posizione $q$ della chiave, oppure NIL se la chiave non è presente.

#### Inserimento

Per __inserire__ un elemento bisogna esaminare successivamente (__probe__) la tabella fino a che non troviamo uno slot vuoto in cui inserire la chiave.

Invece di utilizzare un ordine finito $0,1,...,m-1$ (che impiega $\Theta (n)$), la sequenza di posizioni esaminate dipende dalla chiave inserita, che in aggiunta ad un probe number che indica quale slot controllare, rendendo la funzione:$$h: U \times \{0,1,...,m-1\} \to 0,1,...,m-1$$

```ad-important

L'indirizzamento aperto richiede che per ogni chiave $k$, la sequenza di probe $< h(k, 0), h(k, 1),..., h(k, m-1) >$ sia una permutazione di $\{0,1,...,m-1\}$, così che ogni posizione possa essere considerata come slot per una nuova chiave

```

	HASH-INSERT(T, k):
		i = 0
		do:
			q = h(k, i)
			if T[q] == NIL:
				T[q] = k
				return q
			else:
				i++
		while i != m
		
		error "hash table overflow"

La procedura di inserimento assume che tutti gli elementi della tabella hash siano chiavi senza informazioni satellite, e da per scontato che l'elemento da inserire non sia già presente nella tabella.

#### Eliminazione

Eliminare un elemento dalla tabella può essere complicato, perché se si imposta semplicemente come vuoto allora la ricerca potrebbe fermarsi prima di trovare un qualche elemento che è stato inserito quando lo slot era ancora occupato.

Per risolvere questo problema si segna lo slot come DELETED invece che NIL, così che HASH-INSERT lo possa trattare come slot vuoto in cui poter inserire un nuovo elemento, mentre HASH-SEARCH lo tratta come slot da saltare per controllare le posizioni successive.

#### Doppio Hashing

Assumendo un hashing indipendente e uniforme, la sequenza di ogni chiave può essere una delle $m!$ permutazioni di $\{0,1,...,m-1\}$, ma implementare un hashing del genere è molto difficile, infatti nella pratica vengono usate delle approssimazioni, come il doppio hashing.

Il doppio hashing offre uno dei migliori metodi per l'indirizzamento aperto, dato che le permutazioni prodotte hanno molte delle caratteristiche delle permutazioni scelte casualmente.

Il doppio hashing usa una funzione hash nella forma: $$h(k, i) = (h_1(k) + i \cdot h_2(k)) \mod m$$

Dove $h_1$ e $h_2$ sono funzioni hash ausiliari.

```ad-example
Dati una tabella di $m = 13$, $h_1(k) = k \mod 13$ e $h_2(k) = 1 +  (k \mod 11)$

![[Pasted image 20230616123119.png|center]]

```

#### Linear Probing

Linear probing è un caso speciale di doppio hashing, è il modo più semplice per risolvere le collisioni in indirizzamento aperto.

Se lo slot $T[h_1(k)]$ è pieno, allora si controlla $T[h_1(k) + 1]$ e così via fino ad arrivare alla fine, si ricomincia poi da $T[0]$ e si controlla fino a $T[h_1(k) -1]$, che se è pieno implica che la tabella è piena.

è un caso speciale di doppio hashing in quanto si può scrivere che $h_2(k) = 1$, rendendo la funzione finale $$h(k) = (h_1(k)+i) \mod m$$
	