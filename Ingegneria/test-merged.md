## 11. Test e Verifica

# Verifica

Non si cercano gli errori di compilazione, ma l'assenza di difetti:

- Si controlla se i risultati sono diversi dalle aspettative
- Si controllano errori di esecuzione, eccezioni, fallimenti

Software senza difetti sono impossibili da avere, serve una continua e attenta verifica su ogni aspetto (specialmente i documenti, design, dati di test, ecc), **anche le verifiche devono essere verificate** e queste verifiche devono essere fatte durante tutto il processo di sviluppo, non solo alla fine.

```ad-example
title: Bridge Design

Un test assicura infinite situazioni corrette, i programmi non hanno un comportamento continuo e quindi verificare la funzione in un punto solo non ci dice niente circa gli altri punti.

$$a = ... / (x+20)$$
Per ogni valore di $x$ va bene, tranne che per $x = -20$


```

Per molte qualità le informazioni non sono valori binari (si o no) ma sono soggettive e determinate implicitamente

# Approcci

## Testing

Consiste nello sperimentare il comportamento del prodotto e fare degli esempi con l'obiettivo di trovare degli errori.

I __test__ dovrebbero _identificare la presenza_ di errori, che devono essere _localizzati_ ed _eliminati_ attraverso il __debugging__. Ogni test deve essere ripetuto per vedere se l'errore è stato effettivamente eliminato.

```ad-info
title: Test case e Test set

- test case: un elemento di D
- test set: un sottoinsieme finito di D (un insieme di test case)
- test set ideale: se P non è corretto allora esiste un elemento in T tale che P è incorretto per quel set
Il test $t$ ha successo se $P(t)$ è corretto, il set di test $T$ ha successo se $P$ è corretto in ogni $t \in T$


```

### Criteri Di Test

- Un criterio C definisce i test set.
- Un test set soddisfa C se è un elemento di C

#### Proprietà

- __consistenza__: per ogni coppia (T1, T2) di test soddisfatti da C, T1 ha successo se T2 ha successo, quindi ognuno da la stessa informazione
- __completezza__: se P non è corretto, c'è un test set di C che non ha successo

C è completo e consistente se identifica un test set ideale e permette alla correttezza di essere provata

- C1 è più affidabile di C2 se per ogni programma, per ogni test soddisfatto da C1 c'è un sottoinsieme T2 di T1 che soddisfa C2

```ad-important

Non esiste un algoritmo che genera un test-set che possa provare la correttezza di un programma, non c'è un criterio di costruzione che sia costintente e completo.

```

### Criteri Empirici

Per alcuni programmi andrebbero eseguiti veramente troppi test, per questo si cerca di dividere $D$ in tanti sottodomini $D_i$ dove ogni elemento dovrebbe avere comportamento simile.

Successivamente si seleziona un test per ogni sottodominio, se $D_j \cap D_k \neq 0$ si prende uno degli elementi dell'intersezione per poter ridurre i test.

### Moduli Di Test

Ci sono due approcci:

- __black box__ o [[12. Test Funzionali|test funzionali]]: partizionano i criteri in base a delle specifiche senza conoscere i dettagli interni.
- __white box__ o __test strutturali__: partizionano i criteri in base al codice interno del modulo, conoscendone la struttura.


## Analisi

Studio analitico delle proprietà, è una tecnica statica e formale.

# Definizioni

- P (programma)
- D (dominio di input)
- R (dominio di output)

$$P:D\to R$$

Un programma è una funzione che mappa D in R.

## Correttezza

$$OR \subseteq D \times R$$

- P(d) è corretto se la coppia $<d, P(d)> \in  OR$
- P è corretto se $\forall d \in OR$ tutti i $P(d)$ sono corretti
- FAILURE: può essere indefinito oppure potrebbe essere un risultato errato
- ERROR: qualsiasi cosa che causi un fallimento
- FAULT: stato intermedio sbagliato in cui entra un programma

```ad-important

Queste definizioni non sono standardizzate
```


## 12. Test Funzionali


Si basano sul comportamento __ingresso-uscita__ che il software presenta nel suo ambiente operativo, le tecniche di progettazione si basano sul __ricavare un certo numero di test case__ e permettono _anche_ di verificare il _mancato soddisfacimento di requisiti non funzionali_. Sono __complementari__ ai test strutturali

# Casi Di Test

I casi di test devono essere definiti _prendendo in considerazione_ le condizioni che corrispondono a classi di input/output __non valide__ e __valide__. Ciascun caso di test deve essere _rappresentativo di una classe_ in modo da __minimizzare il numero totale di test__ da effettuare

Le __tecniche di test principali__ per definire i casi di prova sono:

- La tecnica della copertura delle classi di equivalenza
- La tecnica di __analisi dei valori estremi__
- La tecnica di __copertura delle funzionalità__

# Copertura Delle Classi Di Equivalenza

```ad-summary
title: Classe di equivalenza

Un sottoinsieme dei dati in input tale che il test di ogni elemento abbia lo stesso risultato dal punto di vista del comportamento ingresso-uscita

```

La tecnica prevede 2 passi:

1. __Identificazione__ delle classi
2. __Definizione di casi di test__ che coprano le classi

A partire dalle __specifiche funzionali__ possono essere identificate diverse classi (valide o non valide)

## Criteri Utili per L'identificazione Delle Classi

- [[#Intervallo di valori di input]]
- [[#Numero di valori di input]]
- [[#Insiemi di valori di input]]

### Intervallo Di Valori Di Input

Se una condizione di ingresso specifica un __intervallo di valori ammissibili__ per un determinato parametro di input si identificano:

- Una __classe di equivalenza valida__ per i valori compresi nell'intervallo
- Due __classi di equivalenza non valide__ per i valori inferiori e superiori all'intervallo

### Numero Di Valori Di Input

Se una condizione di ingresso specifica un __numero/quantità di valori ammissibili__ per un determinato parametro di input si identificano:

- Una __classe di equivalenza valida__ per un numero/quantità compreso fra il minimo ed il massimo specificati
- Due __classi di equivalenza non valide__ per un numero di valori inferiori e superiori

### Insiemi Di Valori in Input

Se una condizione di ingresso specifica un __insieme di valori ammissibili__ per un determinato parametro di input si identificano:

- una __classe di equivalenza valida__ per ogni gruppo di elementi dell’insieme che si pensa siano trattati in modo analogo
- una __classe di equivalenza non valida__ per un elemento non appartenente all’insieme

## Progettare Casi Di Test

A partire dalle classi identificate occorre progettare un numero di casi di test sufficiente a __coprire tutte le classi di equivalenza valide__, facendo in modo che ciascun caso di test copra il maggior numero possibile di classi valide. Bisogna inoltre creare tanti casi di test __quante sono le classi di equivalenza__ non valide in modo tale che ciascun caso di test copra una ed una sola classe non valida

# Analisi Dei Valori Estremi

Le condizioni sui valori estremi sono quelle condizioni che si trovano direttamente su un valore estremo di una classe di equivalenza di ingresso o di uscita, __immediatamente al di sopra__ di esso oppure __immediatamente al di sotto__

- I casi di test che esplorano condizioni su valori estremi del dominio di input sono _molto produttivi_
- Una __generazione casuale__ dei casi di test, in generale, __non individuerebbe__ la maggior parte di questi difetti

```ad-info
title: Differenze con le classi di equivalenza

- Sono scelti come rappresentativi della classe di equivalenza uno o più valori in un intorno di ciascun estremo
- I casi di test sono progettati considerando anche l’output (classi di equivalenza di uscita)

```

## Individuazione Delle Classi

I criteri per l’identificazione delle classi per estremi sono analoghi ai precedenti.

Per ciascun intervallo di valori ammissibili in ingresso ed in uscita occorre progettare:

- casi di test validi sugli estremi dell’intervallo
- casi di test non validi per i valori immediatamente al di sotto del minimo e al di sopra del massimo

Per ciascun numero di valori ammissibili in ingresso ed in uscita progettare

- casi di test validi per il numero minimo e per il massimo
- casi di test non validi per i numeri immediatamente al di sotto del minimo e al di sopra del massimo

# Tecnica Di Copertura Delle Funzionalità

Richiede di:

- Analizzare le specifiche al fine di determinare le funzionalità elementari del prodotto indipendenti fra loro
- Progettare casi di test che coprano tutte le funzionalità

Per verificare la completa copertura si definisce una __matrice di test__

# BlackBox

Tecniche per la progettazione dei casi di test funzionali input/output

- Copertura delle classi di equivalenza
- Analisi dei valori estremi
- Copertura delle funzionalità

Fasi dell’attività di test

- Progettazione e pianificazione dei casi di test
- Esecuzione del software per ciascun caso di test e registrazione del comportamento del prodotto
- Confronto tra il comportamento atteso e quello reale

## 13. Test Strutturali


Idea generale dei test strutturali:

- __Criterio di inadeguatezza__: se parti della struttura _non sono testate_ il test è _inadeguato_
- __Criterio di copertura del control flow__:
	- Statement coverage
	- Edge coverage
	- Condition coverage
	- Path coverage
	- Data flow coverage

# Statement Coverage

Il criterio di __copertura dei comandi__ comprende la selezione di un test set tale che ogni comando o __statement__ di $P$ _sia eseguito da un qualche test case_. Se ogni $D_i$ è l'insieme di dati che esegue il comando $i$ allora bisogna tentare di __minimizzare__ l'insieme dei $D_i$ in modo da __avere una partizione__.

# Edge Coverage

Il criterio di __copertura degli archi___ comprende la selezione di un test set tale che ogni arco o __branch__ del control flow _sia attraversato almeno una volta_ da un qualche test case, bisogna ovviamente minimizzare la dimensione del test set.

# Condition Coverage

Il criterio __delle condizioni composte__ comprende la selezione di un test set tale che _tutti i possibili valori costituenti le condizioni composte siano testate_ almeno una volta.

```ad-attention

Considera tutti i  possibili modi di rendere vera o falsa una condizione composta, __solo se__ la condizione non è composta corrisponde all' [[#Edge Coverage]].

```

```ad-attention

Se la condizione ha $n$ componenti booleani si possono avere sino a $2^n$ possibili assegnazioni ai componenti

```

# Path Coverage

Il criterio di __copertura dei cammini__ comprende la selezione di un test set che _attraversa tutti i cammini dal nodo iniziale al nodo finale_ del diagramma di flusso.

```ad-attention

$n$ punti di decisione in sequenza possono dar luogo (non necessariamente) a $2^n$ possibili cammini distinti

```

```ad-attention

un ciclo iterativo while o chiamate ricorsive possono dar luogo a infiniti cammini distinti, si pongono dei limiti di copertura dei possibili path.
Ad esempio nel caso di cicli while i tipici path testati sono almeno tre: 0 cicli, 1 ciclo iterativo, 2 (o più) cicli iterativi.

```

# Data Flow Coverage

Il criterio di __data flow coverage__ comprende la selezione di un test set che _copre il più possibile i cammini def-use delle variabili_

- Def: espressione in cui la variabile viene assegnata
- Use: espressione in cui la variabile viene usata