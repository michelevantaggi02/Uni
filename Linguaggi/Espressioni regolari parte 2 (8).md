## Dall'automa all'espressione regolare
Sia $A$ un automa a stati finiti. Per semplicità supporremo che:
- $A$ ha un unico stato finale
- Nel grafo di A non ci sono frecce che entrano nello stato iniziale, nè frecce che escono dallo stato finale.

Le ipotesi precedenti sono restrittive

![[foto 1.png]]

## Cammino nel grafo dell'automa

Per ogni $i,j,k$ con $0 \le k < i,j \le n$ consideriamo l'insieme $L_{ijk}$ contenente le seguenti parole:
- Le etichette dei cammini nel grafo di A che
	- iniziano in $q_i$
	- terminano in $q_j$
	- attraversano solo stati di indice $\le k$ 

![[foto 2.png]]

## Analisi
$$L(A) = L_{n-1 \cdot n \cdot n-2}$$
**Osservazione**
Se riesco a trovare espressioni regolari per tutti gli $L_ijk$ , avrò anche un’espressione regolare di $L(A)$.

**Strategia**
Procedere per induzione su $k$

```ad-abstract
title: Lemma

Per $0 ≤ k < i, j ≤ n$, si può determinare effettivamente un’espressione regolare $E_{ijk}$ che denota l’insieme $L_{ijk}$
```

## Base
Il linguaggio $L_{ij0}$ è denotato dall'espressione regolare:
$$E_{ij0} = \begin{cases}
somma-delle-etichette-delle-frecce-da (q_i) a (q_j)\\
0
\end{cases}$$
![[foto 3.png]]

## Passo Induttivo
Supponiamo $k ≥ 1.$ I cammini nel grafo di $A$ con origine in $q_i$ , termine in $q_j$ e che attraversano esclusivamente stati di indice $≤ k$ si possono ripartire in due categorie:
- cammini da $q_i$ a $q_j$ che attraversano solo stati di indice $≤ k − 1$
- i cammini costituiti dalla concatenazione di
	- un segmento da $q_i$ a $q_k$
	- zero o piu' cammini con origine e termine in $q_k$
	- un segmento finale con origine da $q_k$ a $q_j$
Tutti che attraversano solo stati di indice $\le k-1$

![[foto 4.png]]
![[foto 5.png]]
Le espressioni regolari $E_{ijk}$ che denotano i linguaggi $L_{ijk}$ devono soddisfare le relazioni ricorsive.
$$E_{ijk} = E_{ijk}−1 + (E_{ikk}−1)(E_{kkk}−1) * (E_{kjk}−1), 1 ≤ k < i, j ≤ n.$$
Ma allora si possono calcolare tutte! Compresa $E_{n-1 \cdot n \cdot n-10$} che denota il linguaggio accennato dall'automa

## L'algoritmo di analisi

>Input: Un automa $A$ della forma inficata in precedenza

>Output UN-espressione regolare per $L(A)$

![[foto 6.png]]

**Esempio**

![[foto 7.png]]

## Regola Pratica

**Metodo di eliminazione degli stati**

![[foto 8.png]]

## Pattern Matching

![[foto 9.png]]

## Operazioni Booleane II
**Osservazione**
Date due espressioni regolari, posso effettivamente trovare espressioni regolari per l’unione, l’intersezione e i complementi dei linguaggi da esse denotati

## Equivalenza di espressioni regolari

$$a* + (a*ba*)* = (a+b)*$$
**Problema**
Date due espressioni regolari, decidere se sono equivalenti.

**Osservazioni**
Due insiemi $X$ e $Y$ sono uguali se e solo se: $(X - Y) \cup (Y - X) = 0$

**Soluzione**
Date le espressioni E e F
- calcolare automi deterministici che accettano i linguaggi LE e LF denotati da E e F, rispettivamente; 
- calcolare un automa deterministico che accetta $(LE − LF ) ∪ (LF − LE )$
-  verificare se tutti gli stati finali sono inaccessibili.