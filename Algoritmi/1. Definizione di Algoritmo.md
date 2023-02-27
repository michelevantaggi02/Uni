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