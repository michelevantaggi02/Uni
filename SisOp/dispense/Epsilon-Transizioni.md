Le rappresentazion binarie dei numeri razionali relativi si ottengono concatenando:
1. Il simbolo + o − o la parola vuota, 
2. una sequenza finita di 0 e 1, 3 
3. il punto
4. un’altra sequenza finita di 0 e 1.

> Almeno una tra 2 e 4 non deve essere mai vuota

> Consideriamo la possibilità che l’automa possa saltare da uno stato a un altro senza leggere il nastro di input.


![[linguaggi 1.png]]

## Definizioni

```ad-abstract
title: Definizioni
Un automa a stati finiti non deterministico con 𝜀-transizioni è una quintupla $𝒜 = ⟨Q, Σ, 𝛿, q0,F)$ dove $Q, Σ, q0,F$ sono come nella dell'automa deterministico e $𝛿 : Q × (Σ ∪ {𝜀}) → ℘(Q)$ è la funzione di transizione

```

Una parola $w ∈ Σ *$ è accettata da $A$ se esistono $n ≥ 0, a_1,\cdots , a_n ∈ Σ ∪ {𝜀} e q_1,\cdots, q_n ∈ Q$ tali che $w = a_1,a_2, \cdots, a_n , qi ∈ 𝛿(q_{i−1}, ai), 1 ≤ i ≤ n , q_n ∈ F$.
L'insieme delle parole accettate da $A$ si dice linguaggio accettato (o riconosciuto) da $A$ e si denota con $L(A)$

## Grafo dell'automa
A ogni automa non deterministico con 𝜀-transizioni 𝒜 = ⟨Q, Σ, 𝛿, q0,F⟩ associamo un grafo diretto con frecce etichettate:
- i vertici sono gli stati; 
- le frecce sono le triple (q, a, p) con q ∈ Q, a ∈ Σ ∪ {𝜀}, p ∈ 𝛿(q, a); 
- lo stato iniziale è denotato da una freccia entrante; 
- gli stati finali sono identificati dal bordo doppio.

Ci si convince facilmente che
- Una parola w può essere etichetta di molti cammini uscenti dallo stato iniziale, o anche nessuno;
- la parola w è accettata se e solo se c’è un cammino dallo stato iniziale a uno stato finale con etichetta w;
- Questo non esclude però che vi possano essere altri cammini con etichetta w che partono dallo stato iniziale e terminano in uno stato non finale.

**Esempio**
![[Linguaggio 2.png]]

## Determinizzazione

```ad-tip
title: Theorem

Sia $A$ un automa a stati finiti non deterministico con $\epsilon$-transizioni. Esiste effettivamente un automa a stati finiti deterministico 𝒜$A$ tale che: $$L(A) = L(A')$$
```

**Dimostrazione**
Gli stati dell’automa deterministico registreranno l’insieme degli stati raggiungibili dalle computazioni dell’automa non deterministico sul medesimo input; Accetto se fra questi ce n’è uno finale

## $\epsilon$-chiusura

Informalmente, la la 𝜀-chiusura di uno stato è l’insieme degli stati che da questo si possono raggiungere utilizzando solo 𝜀-transizioni.
```ad-abstract
title: Definizione

Sia $A = ⟨Q, Σ, 𝛿, q0,F⟩$ un automa a stati finiti non deterministico con 𝜀-transizioni. La 𝜀-chiusura di uno stato $q ∈ Q$ è il più piccolo sottoinsieme $C𝜀(q)$ di $Q$ tale che:
- $q ∈ C𝜀(q), 
- $\forall p ∈ C𝜀(q), 𝛿(p, 𝜀) ⊆ C𝜀(q)$

```

La 𝜀-chiusura di un insieme di stati $S ⊆ Q$ è l’unione delle 𝜀-chiusure dei singoli stati di $S: C𝜀(S) = ⋃︀ q∈S C𝜀(q)$.

**Esempio**

![[Linguaggi 3.png]]

## Calcolo della $\epsilon$-chiusura

**Input:** Un automa non deterministico con 𝜀-transizioni $A = ⟨Q, Σ, 𝛿, q0,F⟩$ e uno stato $q ∈ Q$
Output: La 𝜀-chiusura di $q$;

	R = (q)
	p = primo elemento di R
	while p != NIL
		appendi a R tutti gli element di 𝛿(p, 𝜀) ∖ R
		p = successivo(p)
	return R

![[Linguaggi 4.png]]

### La costruzione

Sia $A = ⟨Q, Σ, 𝛿, q0,F⟩ $ l’automa non deterministico con 𝜀-transizioni. Definisco l’automa deterministico $A = ⟨Q′ , Σ, 𝛿′ , s0,F ′ ⟩$ come segue:
- l’insieme degli stati è l’insieme $Q′ = ℘(Q)$ costituito dai sottoinsiemi di $Q$
- lo stato iniziale è $s_0 = C𝜀(q_0)$
- gli stati finali sono tutti i sottoinsiemi di $Q$ che contengono almeno un elemento di $F$, cioè $F ′ = {s ∈ ℘(Q) | s ∩ F \not = ∅}$
- la funzione di transizione $𝛿 ′ : Q′ × Σ → Q′$ è definita da
 $$𝛿 ′ (s, a) = C𝜀 (︃⋃︁ p∈s 𝛿(p, a) )︃ , s ∈ ℘(Q), a ∈ Σ.$$
 **Dimostrazione**
Per ogni $w ∈ Σ *$ risulta: $𝛿̂︀′ (s_0, w) = {q \in Q$ nel grafo di $A$ c’è un cammino da $q_0$ a $q$ con etichetta $w$}

Pertanto sono equivalenti: 
- w è accettata da A;
- 𝛿̂︀′ (s0, w) contiene uno stato di F; 
- 𝛿̂︀′ (s0, w) ∈ F ′ ; 
- w è accettata da 𝒜′

Quindi $L(A) = L(A')$
