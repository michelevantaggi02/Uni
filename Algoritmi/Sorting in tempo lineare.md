# Counting sort

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

Il  counting sort è un algoritmo stabile, ovvero preserva l'ordine in cui gli elementi sono dati in input.

# Counting sort semplificato

	for

# Radix sort
