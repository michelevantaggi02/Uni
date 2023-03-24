zz1![[1.png]]
![[2.png]]
![[3.png]]

## Diagrammi di classe
I diagrammi di classe mostrano le diverse classi che costituiscono un sistema e come si relazionano una all'altra.
Sono diagrammi statici:
- mostrano le classi, insieme ai loro metodi e attributi oltre alle relazioni statiche tra loro
- non mostrano le chiamate ai metodi tra di loro

```ad-abstract
title: Definizione Classe
Una classe è il descrittore di un insieme di oggetti o (istanze della classe) che condividono gli stessi attributi, operazioni, metodi, relazioni e comportamento

```

![[4.png]]

## Notazione UML per classi

Una classe viene rappresentata da un rettangolo contenente il suo nome in una sottosezione rettangolare.
![[5.png]]
Il nome è l'unica sottosezione obbligatoria
Facoltativamente si possono mostrare gli attributi (campi) e le operazioni (metodi) della classe in due altre sottosezioni del rettangolo.
![[6.png]]

## Attributi
Gli attributi sono mostrati con almeno il loro nome. Si possono includere anche il loro tipo, il valore iniziale e altre proprietà. SI possono includere anche il loro tipo, il valore iniziale e altre proprietà. Ornamento di visibilità degli attributi:
+ sta per pubblici (public)
+  # sta per protetti (protected)
+ - sta per privati (private)
+ ~ sta per pacchetto (package)

## Notazione di una classe
![[7.png]]

## Operazioni (metodi o funzioni)
In UML le operazioni (metodi) sono mostrate con almeno il loro nome. 
Si possono includere anche i loro parametri e i tipi restituiti. Ornamenti di visibilità per le operazioni:
+ sta per pubblici (public)
+  # sta per protetti (protected)
+ - sta per privati (private)
+ ~ sta per pacchetto (package)

### Notazione di una classe
![[8.png]]

### Proprietà
- Corrispondenza nel linguaggio di programmazione
	- Attributi
		- membri di classe 
		- proprietà aggiuntive
- Associazioni
	- anche se etichettata con verbo, meglio renderla con un nome
	- evitare le associazioni bidirezionali

### Definizione di operazione

![[9.png]]

Le azioni che la classe "sa eseguire":
- Descrivono Aspetti comportamentali 
- Offrono un Servizio che può essere richiesto ad ogni istanza della classe 
- Direzione: in, out, inout (default in) 
- Visibilità: + pubblica, - privata, # protetta 
- Query 
- Modificatori 
- Operazione ≠ metodo

### Esempio
![[10.png]]

## Relazioni tra classi
Le diverse classi possono relazionarsi una con l’altra in diversi modi:
- Associazione 
- Aggregazione 
- Composizione 
- Generalizzazione (ereditarietà) 
- Dipendenza 
- Realizzazione

permettono di descrivere relazioni logiche tra le classi nel dominio applicativo.

### Associazione 
Un collegamento tra due oggetti è una connessione semantica che consente loro di scambiarsi messaggi
Un’associazione tra due classi indica che si può avere un collegamento tra una coppia di oggetti appartenenti alle due classi.
L’aggregazione e la composizione possono considerarsi delle forme di associazioni specia

Le associazioni possono esser indicate con:
- Nome dell’associazione: un verbo che specifica l’azione che l’oggetto origine esegue sull’oggetto destinazione.
- Nome dei ruoli: un sostantivo che descrive il ruolo che gli oggetti possono ricoprire.
- Navigabilità: specifica se la comunicazione tra gli oggetti può essere uni- o bidirezionale.
- Molteplicità: specifica per ciascun lato dell’associazione, quanti oggetti su questo lato possono relazionarsi a un oggetto sull’altro lato.

### Notazione UML per assoiazioni
Un'associazione è rappresentata con una linea che connette le due classi che partecipano alla relazione.
![[11.png]]

Il nome dell’associazione, i nomi dei ruoli e la molteplicità (detta anche cardinalità) possono essere inseriti nelle vicinanze della linea che descrive l’associazione e dal lato delle classi cui si riferiscono. In una descrizione semplificata possono tutti essere omessi:
![[12.png]]

### Molteplicità di un'associazione

![[13.png]]

### UML: Navigabilità di un'associazione
Il nome di una associazione, se possibile non dovrebbe esprimere una direzione, oppure esprime la direzione/navigazione prevalente. Es. il nome di relazione impiego tra le classi lavoratore e azienda è non direzionale, i nomi da_lavoro_a e lavora_a esprimono la direzione.

![[14.png]]

### Valori di Molteplicità
I valori di molteplicità possono essere specificati come:
- n esattamente un intero n non negativo, min/max/uguale
- * un solo asterisco, indica zero  più
- $a \cdots b$ un intervallo $[a,b]$ di interi no negativi («da minimo a fino a massimo b», b può essere * “molti”)
- $a \cdots b, n, m, p \cdots, q$ un insieme di intervalli e/o numeri; il valore più a destra può essere *

![[15.png]]

### Tipi di molteplicità tra coppie di classi

![[16.png]]

## Trasformazione da diagramma di classe a codice

![[17.png]]

Un post può avere dei commenti (classe post associata alla classe commento)
Una classe può essere associata a se stessa. Nell'esempio sigifica che un commento può essere ommentato tramite altri commenti. (relazione ricorsiva)

## Attributi e Associazioni

In una relazione molti-a-molti tra due classi, non sempre è possibile assegnare un attributo ad una delle due classi.

Si consideri il seguente esempio:

![[18.png]]

- ogni oggetto persona può essere dipendente di molti oggetti azienda
- ogni oggetto azienda può impiegare molti oggetti persona

Si assuma che ogni Persona percepisce uno stipendio da ogni Azienda in cui lavora.
Dove collochiamo l’attributo stipendio: nella classe chPersona o nella classe Azienda?

**ipotesi 1** = attributo stipendio in persona. Non riesco a modellare tutte le situazioni in cui una
Persona lavora per diverse Aziende percependo uno stipendio diverso da ciascuna di esse.

![[19.png]]

**Ipotesi 2 =** attributo stipendio in azienda. Non riesco a modellare tutte le situazioni in cui un-azienda impiega molte persone con stipendi potenzialmente diversi.

![[20.png]]

Le ipotesi 1 e 2 non consentono di ottenere un modello semanticamente corretto perché lo stipendio è una proprietà (attributo) dell’associazione stessa.
• Per ogni associazione “impiega” tra un oggetto Persona eun oggetto Azienda, c’è uno specifico stipendio per uno specifico rapporto di lavoro.
• L’UML consente di modellare questa situazione con una classe associazione.

## Classe di Associazione

```ad-success
title: Definizione
Una classe associazione è un’associazione che è anche una classe. Oltre a connettere due classi, definisce un insieme di caratteristiche proprie dell’associazione.

```
Una classe associazione è rappresentata:
- dalla linea dell’associazione (compresi tutti i nomi di ruolo e molteplicità),
- dal rettangolo della classe e
- dalla linea tratteggiata verticale che li collega.

**Notazione UML di una classe di associazione**
![[21.png]]

## Classi di Associazione

Si può usare una classe associazione quando vi sia al massimo un unico collegamento tra ogni coppia di oggetti in ogni istante. 

>una Persona ha al più una sola Posizione con una stessa Azienda

In caso negativo, cioè se sono possibili molti collegamenti reciproci in un qualunque istante si “reifica” (rende reale) la relazione trasformandola in una classe esplicita.

>una Persona ha (simultaneamente) più di una Posizione con una stessa Azienda.

![[22.png]]


## Aggregazione

```ad-abstract
title: Definizione
Le aggregazioni sono un tipo speciale di associazione nel quale le due classi partecipanti non hanno un rango uguale, ma hanno una relazione di tipo tutto-parte. Un'aggregazione descrive come la classe che ha il ruolo del tutto è composta di (ha) altre classi, che hanno il ruolo di parti

```

### UML: Aggregazioni

Le aggregazioni sono rappresentate da un'associazione che mostra un rombo sul lato dell'aggregato.

![[23.png]]

**Esempio (Computer-Desktop)**

![[24.png]]

## Composizione

- La composizione è una forma piu' forte d aggregazione
- COme l'aggregazione, s tratta di una relazione di tutto-parte
- La differenza è che in una composizione la parte non può esistere al di fuori del tutto:
	- Le parti esistono solo all'interno del tutto
	- Se il tutto è distrutto anche le parti muoiono
- GRaficamente indicata da rombo solido/pieno a lato $<<classe tutto>>$ diretta verso $<<classe parte>>$

### Notazione UML per composizioni
Le composizioni sono rappresentate da un'associazione che mostra un rombo solido sul lato del composito.

![[25.png]]

## Semantica della composizione

Ogni parte appartiene ad un unico composito, dunque:
	• possono esistere gerarchie di composizione,
	• non possono esistere reti di composizione (albero)
l composito è l’unico responsabile del ciclo di vita delle parti.
Quando si distrugge un composito, questo deve a suo volta:
- distruggere tutte le sue parti, oppure cederne la responsabilità a un altro oggetto

## Aggregazione e composizione

pagina 46