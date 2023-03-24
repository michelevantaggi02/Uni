
## Operazioni sui linguaggi
linguaggi rappresentano un insieme di parole la quale si possono effettuare operazioni insiemistiche. Una concatenazione di parole

- unione, intersezione, complemento
- concatenazione: $L_1, L_2 = {uv | u ∈ L_1, v ∈ L_2}$ , 
- potenza: $L^n = L L · · · L,$ n volte (possiamo concatenare un linguaggio con se stesso = quadrato di quel linguaggio) ($L^1 = L ed L^0$ = linguaggio che contiene la parola vuota epsilon)
- Chiusura di Kleene (Si denota con una stella)
$$L * = \bigcup_{n≥0} L^n = \{u_1,u_2 \cdots u_n | n ≥ 0, u_1, . . . , u_n ∈ L\}$$
```ad-summary
title: Definizione
La chiusura di Kleene prende l'unione di tutte le n potenze del linguaggio.
l'insieme di tutte le parole che ottengo concatenendo due o piu parole di L.

```


```ad-success
title: Nota Bene

Unione, concatenazione e chiusura di Kleene sono dette operazioni regolari.
```

### Esempi

Se $L1 = {ab, cb}$ e $L2 = {aa, c}$, $\Rightarrow$ $L1L2 = {abaa, abc, cbaa, cbc}$

Se $L = {a, ab} \Rightarrow L_0 = \{\epsilon\}, L^1 = L, L^2 = \{aa, aab, aba, abab\}$

## Espressioni Regolari

Sia $\hat \Sigma$  l'alfabeto ottenuto aggiungendo a $\Sigma$ le lettere $∅, +, *, (, )$ 
Si dicono espressioni regolari sull’alfabeto $\Sigma$ le parole sull’alfabeto $\hat \Sigma$ che si ottengono applicando un numero finito di volte le regole seguenti:
- Ogni lettera $a ∈ Σ$ è un’espressione regolare, $∅$ è un’espressione regolare
- Se $E$ e $F$ sono espressioni regolari, allora $(E + F), (EF)$, $E *$ e $F*$ sono nuove espressioni regolari

A ogni espressione regolare è associato un linguaggio, detto linguaggio denotato dall’espressione regolare e definito dalle regole seguenti:
- per ogni $a ∈ Σ$, l’espressione regolare $a$ denota il linguaggio $\{a\}$; l’espressione regolare $∅$ denota il linguaggio vuoto. 
- Detti $L_E$ e $L_F$ i linguaggi denotati dalle espressioni regolari $E$ ed $F$, i linguaggi denotati dalle espressioni regolari $(E + F), (EF), E *$ sono, rispettivamente, $L_E ∪ L_F , L_E L_F , L_E *$

## Linguaggi Regolari
I linguaggi denotati da espressioni regolari si dicono linguaggi regolari.

**Osservazione** 
La classe dei linguaggi regolari è la più piccola famiglia di linguaggi che:
- contiene i linguaggi finiti, 
- è chiusa per le operazioni regolari. 

**Osservazione** 
Possiamo omettere qualche parentesi, rispettando la priorità: 
- chiusura di Kleene
- concatenazione
- somma.

Ordine tra le operazioni nelle espressioni regolari.

### Esempi
$bab + ab*$ equivale a $(((ba)b) + (ab* )).$

1. $(a+b)*$ Tutte le parole (concatenazione di infinite copie $a,b$ ) su $\{a,b\}$
2. $∅^*$ = Preno tutte le parole concatenando linguaggio vuoto.
3. $((a+b)(a+b)(a+b))^*$ Ottengo tutte le combinazioni di tre lettere (parole) appartenenti a $\{a,b\}$. (parola con lunghezza multipla di 3 con concatenazione infinite di triple lettere).
6. $(a+ab)*$
7. (b* a b* a b*)* = tante b (anche zero) una a tante b (anche zero) una a  tante b (anche zero). L'asterisco fuori sta ad indicare una concatenazione della stringa contenuta nella parentesi.
8. (a+b+c)* abac (a+b+c)* = Tutte le parole che contengono abac

## Teorema di Kleene

```ad-abstract
title: Th
Un linguaggio è regolare se e soltanto se è riconosciuto da un automa a stati finiti.

```
Esite una procedura effettiva che:
- Data un’espressione regolare, produce un automa a stati finiti che accetta il linguaggio denotato da tale espressione (sintesi), 
- Dato un automa a stati finiti, produce un’espressione regolare che denota il linguaggio accettato da tale automa (analisi)

## Dall'espressione regolare all'automa

Utilizzeremo esclusivamente automi non deterministici con $\epsilon-transizioni$ con un unico stato finale (non restrittivo).

![[Pasted image 20230321164938.png]]
## Base
![[Pasted image 20230321165000.png]]
## Unione
![[Pasted image 20230321165026.png]]