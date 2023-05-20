# 1. Qualità del software

Sebbene il software sia intangibile possiamo attribuirgli delle qualità:

- Qualità __interne__ riguardanti gli __sviluppatori__ del sistema
- Qualità __esterne__ apprezzate dagli __utenti__ del sistema

```ad-example
collapse: open

- Gli utenti vogliono che il software sia _affidabile_
- Gli sviluppatori vogliono che il software sia _verificabile_

Entrambe le qualità dipendono l'una dall'altra in quanto per ottenere affidabilità il software deve poter essere verificato.
```

Il prodotto dell'ingegneria del software è il sistema consegnato al committente (software, __manuali__,...). Tale prodotto viene realizzato mediante un __processo__ mediante il quale vengono creati diversi prodotti _intermedi_ che devono però rispettare gli stessi requisiti del prodotto finale.

# Qualità Esterne

## Correttezza

Un programma è __corretto__ se si comporta secondo le __specifiche funzionali__ date:

- Le specifiche devono essere _non ambigue_
- Più le specifiche sono rigorose, più è possibile verificare la correttezza del software.

## Affidabilità

Un software è __affidabile__ quanto è alta la probabilità che funzioni come atteso entro un certo intervallo di tempo. I software [[#Correttezza|corretti]] sono anche _affidabili_

## Robustezza

Un programma è __robusto__ se si comporta in modo accettabile anche in circostanze non previste nella specifica dei requisiti.

```ad-example
collapse: open

Input non corretto o fallimenti hardware

```

Un programma [[#Correttezza|corretto]] può non essere robusto.

```ad-important
title: Legge di Postel

Sii conservatore in ciò che fai, sii liberale in ciò che riguardare 01-03-2023

```

## Prestazioni

Le __prestazioni__ di un software dipendono dall'efficienza con cui il software utilizza le risorse interne del computer (memoria, potenza di calcolo, rete). Le prestazioni possono essere valutate mediante misure, analisi e simulazioni.

Le prestazioni influenzano l'usabilità e la scalabilità di un software

## Usabilità

Un software è __usabile__ quando gli utenti lo reputano semplice da utilizzare (_user friendly_). L'interfaccia grafica influisce molto sull'esperienza che l'utente percepisce nell'usare il software.

# Qualità Interne

## Verificabilità

Un software è __verificabile__ quando è facile verificarne la correttezza e le prestazioni.

## Manutenibilità

La __manutenibilità__ di un software indica la facilità con cui tale software può evolvere, al fine di rimuovere errori, implementare nuove funzionalità, migliorare funzionalità esistenti, ecc..

### Software Legacy

è un software che è presente in un'organizzazione da più tempo e molto spesso utilizza della tecnologia non più usata che è quindi difficile modificare. In questi casi bisogna ricorrere al reverse engineering o reengineering per ricostruire i vari passaggi del suo funzionamento.

### Riparabilità

La facilità con cui si eliminano i difetti del software

### Evolvibilità

Facilità con cui si possono apportare cambiamenti

## Riusabilità

Alcuni elementi del software possono essere riutilizzati per dare vita ad altri prodotti differenti. Ci sono dei produttori di software che sono specializzati alla produzione di queste librerie aggiuntive che devono essere altamente riutilizzabili.

## Portabilità

Un software è __portabile__ se può essere eseguito in ambienti diversi (sia hardware che software)

## Comprensibilità

Più il software è complesso più è probabile che sia difficilmente comprensibile

```ad-info
title: Legge di Eagleson

qualsiasi codice sorgente che hai scritto e che non è più stato guardato da sei o più mesi potrebbe benissimo essere stato scritto da qualcunaltro.

```

Un software comprensibile internamente è facile da verificare e mantenere, mentre un software prevedibile esternamente è facile da comprendere per l'utente

## Interoperabilità

Un programma è __interoperabile__ con un altro se può cooperare e coesistere con questo.

```ad-example

Un elaboratore di testo come word può aggiungere immagini o diagrammi di altre applicazioni o anche aprire documenti di openoffice

```

# Qualità Di Processo

## Produttività

è la qualità del processo di produzione di che ne indica l'efficienza con cui viene scritto e le sue prestazioni in conseguenza.

```ad-example

Il linguaggio C è molto performante ma allo stesso tempo poco produttivo.

```

## Tempestività

è la capacità di rendere disponibile un prodotto al momento giusto, è necessaria un'attenta _pianificazione_ del processo per poter sviluppare in un tempo sufficiente il software

## Visibilità

Un processo di sviluppo del software è __visibile__, o trasparente, se tutti i suoi passaggi sono documentati in modo chiaro. Un processo visibile consente ai vari attori di avere chiaro lo stato del progetto, potendo così soppesare le loro scelte, lavorando tutti nella stessa direzione.

# Aree Applicative

Il software deve automatizzare una specifica applicazione ed è caratterizzato sulla base della sua area applicativa (ovvero l'area di lavoro su cui deve lavorare)

## Sistemi Informativi

Devono gestire le informazioni di un'organizzazione, non eseguono calcoli estremamente complessi ma si occupano della gestione, la modifica, l'aggiunta e l'eliminazione di una grande quantità di informazioni.

Molti di questi sistemi informativi hanno un'interfaccia web, e il loro principale lavoro è quello di gestire i dati, quindi alla loro base hanno sempre un __database__.

Questi sistemi possono essere caratterizzati in base al modo con cui elaborano questi dati:

- __Integrità dei dati__: capacità di garantire la non corruzione dei dati
- __sicurezza___: capacità di fornire un opportuno livello di protezione rispetto all'accesso ai dati
- __disponibilità dei dati__: capacità di limitare le condizioni in cui i dati non sono accessibili
- __prestazioni delle transazioni__: capacità di eseguire più transazioni simultaneamente

## Sistemi in tempo reale

Devono essere in grado di rispondere a determinati eventi entro un tempo limitato, per fare questo si basano su uno _scheduler_ che si occupa di ordinare le azioni del sistema anche in base alla priorità o al tempo di esecuzione. 

Il tempo di risposta di questi sistemi deve quindi essere una qualità caratterizzante, devono essere inoltre affidabili e devono evitare rischi inaccettabili.

## Sistemi distribuiti

I sistemi distribuiti sono composti da più macchine indipendenti o semi-indipendenti che sono collegate attraverso una rete. Devono essere quindi sviluppati per poter essere eseguiti contemporaneamente su più computer e gli strumenti di sviluppo devono supportare queste necessità.

## Sistemi embedded

Nei sistemi embedded il software di solito è solo __uno dei tanti componenti__ che si occupa di interfacciarsi soltanto ai componenti del sistema che controlla

# 10. Diagrammi di attività

Descrivono la logica procedurale e i processi di business, aiutando a esprimere gli aspetti dinamici dei casi d'uso.

# Attività

Un'attività è un'insieme di più azioni.

- Si parte da un nodo iniziale (Da dove inizia l'esecuzione)
- Il fork permette l'elaborazione parallela (non c'è un ordine tra le attività di processi diversi)
- Il join sincronizza i processi paralleli
- Le decisioni (branch) permettono di intraprendere solo uno dei percorsi possibili
- Nodo finale
- Nodo di fine flusso

## Token

I token vengono __prodotti__ e __consumati__:

- Il nodo iniziale genera token
- Il nodo finale consuma token
- Il fork produce un token per processo
- Il join consuma i token in ingresso e ne genera uno unico

# Sotto-Attività

 ![[Pasted image 20230509153129.png|center]]

# Pin E Trasformazioni

Servono a passare parametri tra azioni diverse.

I pin corrispondono ai box dei parametri nel business risorse prodotte e consumate

![[Pasted image 20230509153334.png|center]]

# Partizioni

Forniscono una _responsabilità_ all'esecuzione delle azioni![[Pasted image 20230509153504.png|center]]

# Segnali

Eventi provenienti da un processo esterno

![[Pasted image 20230509153542.png|center]]

## Eventi Temporali

Un evento con un arco entrante è un timeout

Un evento senza archi entranti è un evento ripetuto

# Regioni Di Espansione

Descrivono la ripetizione della attività su una collezione ![[Pasted image 20230509155412.png|center]]

# Terminazione

Non termina l'intera attività, ma consuma un token

![[Pasted image 20230509163311.png|center]]

# 2. Modelli produttivi

Un __processo software__ è un insieme di attività che porta alla creazione di un prodotto software

Esistono diversi tipi di software ma non esiste un modello che vada bene per tutti, il modello dipende dal tipo di software e dalle richieste e capacità.

# Code and Fix

Modello iniziale utilizzato quando al lavoro c'era uno sviluppatore singolo, molto improvvisato e consiste semplicemente nel programmare e sistemare il codice mal funzionante.

Oggi è necessaria una __pianificazione__ per cui questo sistema è obsoleto, anche se esistono processi di produzione __agili__ la cui pianificazione avviene continuamente al fine di modificare il processo in caso di cambiamenti.


# Attività principali della produzione software

- __specifica__: vengono definiti i requisiti che deve rispettare il programma e le funzionalità che deve avere rispettando i vincoli operativi
- __sviluppo__: viene sviluppato il software che realizza le specifiche
- __convalida__: il software viene testato per garantire che rispetti le richieste
- __evoluzione__: il software viene aggiornato in caso cambino le richieste del cliente.

## Studio di fattibilità

è un'attività preliminare che viene eseguita per verificare se è fattibile lo sviluppo del progetto, serve anche a trovare soluzioni alternative, a discutere eventuali compromessi e serve a decidere se sviluppare da 0, comprare una base di partenza o abbandonare direttamente il progetto.

## Ingegneria dei requisiti

Bisogna comprendere gli __obiettivi__ e __documentare i requisiti__ che deve soddisfare, bisogna inoltre __specificare le qualità__ che il software deve rispettare.

## Sviluppo

Il progetto viene prima __progettato__ a diversi livelli di dettaglio, 
![[Pasted image 20230308114722.png|center]]

La produzione del codice e i vari test devono seguire degli standard sulla loro struttura, sui commenti, sui nomi ecc.

# Modello a cascata

# Modello a spirale

# Sviluppo agile



# 3. Qualità



# 4. UML

```ad-tldr
title: Definizione

Famiglia di notazioni grafiche, basate su un singolo metamodello, che aiutano a descrivere e progettare sistemi software

```

```ad-info
title: Meta-modello
Insieme di regole, vincoli e teorie utilizzate per la modellazione di una classe di problemi

```

```ad-info
title: UML notation guide


Regole attraverso le quali gli elementi di un linguaggio sono assemblati in espressioni come elementi di modellazione, Relazioni e diagrammi.

```


```ad-info
title: UML semantics


Regole attraverso le quali alle espressioni sintattiche viene attribuito un significato
```

# Caratteristiche Principali

- incorpora la miglior esperienza sviluppata a livello industriale
- è uno strumento flessibile, che si adatta alla maggior parte dei sistemi produttivi
- si adatta ai bisogni di sviluppo dei moderni software
- È indipendente dai linguaggi di sviluppo e programmazione
- Supporta concetti di sviluppo ad alto livello
- Supporta l’intero ciclo di vita del software
- E’ supportato da numerosi tool di progettazione

```ad-question
title: Perché un modeling language?

Perché il linguaggio naturale è troppo astratto e dispersivo, mentre i linguaggi di programmazione sono troppo concreti.


Questo è una via di mezzo

```

# UML

UML (Unified Modeling Language) è un linguaggio di modellazione unificato che si avvale di diagrammi per specificare, visualizzare e documentare modelli di sistemi software.

```ad-attention

UML __non__ è un metodo di sviluppo poiché __non definisce__ una metodologia di progetto ma serve per __descrivere e visualizzare un progetto__.

```

UML viene prevalentemente impiegato nella progettazione di software ad oggetti (OOP) e prevede due tipi (complementari) di rappresentazione di un sistema.

## Statica

descrive la struttura di un sistema, le parti che lo compongono e relative relazioni;

## Dinamica

descrive il comportamento del sistema; come lo stato del sistema si modifica durante il funzionamento.

# Utilizzo Principale

UML viene utilizzato principalmente come sketch di un progetto, per documentare e descrivere le porzioni di un sistema, aiutando alla progettazione dell'architettura del prodotto.

## Forward Engineering

Il diagramma definisce il sistema (tutto o in parte) prima della stesura del codice

## Reverse Engineering

Il diagramma viene costruito a partire dal codice, magari per costruire una documentazione a posteriori.

## Sketch

![[Sketch.png|center]]

## Progetto

![[Progetto.png|center]]

Utilizzare UML come progetto richiede un approccio più ingegneristico che permette la formazione di diversi elementi:

### Documento Di Definizione Di Prodotto (DP)

Descrive formalmente il sistema per modelli con un elevato grado di dettagli non lasciando nessuna decisione o interpretazione da parte del programmatore.

### Definizione Delle Interfacce Tra Sottosistemi

Approccio più comune rispetto alla descrizione di tutto il sistema in cui i programmatori “progettano” e sviluppano le componenti dei sistemi in autonomamente

### Generazione Di Struttura Software per La Progettazione Di Dettaglio

CASE (Computer-Aided Software Engineeging)

## Linguaggio Di Programmazione?

Genera automaticamente il codice a partire dai diagrammi, è un approccio ottimale ma non fattibile, quindi genera soltanto la struttura di base


# 5. Casi D'uso

# Casi D'uso

Gli use case sono tecniche per individuare i requisiti di un progetto __descrivendo interazioni__ tra il sistema e gli utenti/elementi esterni.

```ad-example

È richiesto lo sviluppo di un’applicazione che permetta la gestione di un semplice blog. In particolare devono essere disponibili almeno tutte le funzionalità base di un blog: 
- inserire un nuovo post
- commentarlo. 

Queste due operazioni devono essere disponibili _unicamente agli utenti registrati_ all’interno del sistema. La registrazione avviene scegliendo una _username_ e una _password_. La username deve essere _univoca_ all’interno del sistema

```

Un __caso d'uso__ è un insieme di _scenari_ che hanno in comune uno scopo finale (_obiettivo_) per un utente, descrivendo così come sono percepite dagli utenti le funzionalità del sistema.

## Scenari

Sequenze di passi che descrivono le interazioni degli attori (utenti e sistema). Possono anche rappresentare una __possibilità__ (scenari __alternativi__).

```ad-summary
title: Scopo

Tutti gli scenari (sia principali che alternativi) condividono uno __scopo__

```

## Attori

Il ruolo dell'utente nell'interazione con il sistema e svolgono il caso d'uso per raggiungere l'obiettivo.

Un buon mezzo di individuazione dei casi d'uso consiste nell'individuare la lista degli attori e comprendere i loro obiettivi e come interagiscono con il sistema

## Forma

Gli use case sono puro testo, e il valore aggiunto sta proprio nel suo contenuto:

- Nome/indentificatore
- Scenario principale
- Scenari alternativi
- Pre-condizioni
- Effetti/Garanzia (post-condizioni)
- Trigger
- Attori principali
- Attori secondari

# Individuazione Dei Casi D'uso

Bisogna prima definire il contesto:

- Identificare attori e responsabilità
- Identificare gli obiettivi che deve raggiungere ciascun attore
- Creare una prima approssimazione degli use case
- Valutare e raffinare gli attori e i case
- Trovare inclusioni, estensioni e generalizzazioni

Bisogna anche capire a che livello di dettagli spingersi nella realizzazione

- Kite level: Livello più astratto che definisce le macrofunzionalità
- Sea level: Livello intermedio che definisce le funzionalità nascoste non troppo dettagliati
- Fish level: Livello di dettaglio che individua direttamente i requisiti di sistema

# 6. Diagrammi Dei Casi D'uso

# Diagrammi Dei Casi D'uso

Sono una rappresentazione grafica dei casi d'uso, mettono in evidenza attori e servizi del sistema.

Sono rappresentati da un grafo, i cui nodi sono gli attori e gli use case, gli archi invece sono la comunicazione tra questi e i legami/relazioni tra use case diversi.

Il diagramma individua i confini del sistema nello scenario

## Inclusione <\<include>>

un caso d'uso incluso esprime una funzionalità comune fra più use case.

Se un caso A include B, vuol dire che ogni volta che si va nel caso A viene eseguito incondizionatamente anche il caso B:

- A non conosce i dettagli di B, ma solo i suoi risultati
- B non sa di essere incluso in A
- La responsabilità nell'esecuzione appartiene ad A

Questo serve ad evitare la ripetizione di azioni e aumenta la possibilità di riutilizzo.

## Estensione <\<extend>>

Se un caso B estende un caso A, vuol dire che il caso B aumenta le funzionalità già appartenenti ad A

- L'esecuzione di B interrompe A
- La responsabilità appartiene a B (chi estende)

```ad-important
Non è la stessa cosa dell'ereditarietà nella programmazione a oggetti, quella è la [[#Generalizzazione/Specializzazione (ereditarietà)]]
```

### Condizione

La condizione determina quando questa estensione deve essere utilizzata, deve essere specificata tramite descrizione e/o commento associate allo use case.

### Esistenza

Esiste indipendentemente dagli use case estesi, può estendere più use case base.

Il perimetro del caso d'uso esteso corrisponde di solito alla modifica dello scenario principale o a una post condizione

```ad-example

Gestione di eccezioni ed errori

```

## Differenze

Sia l'inclusione che l'estensione fattorizzano comportamenti comuni a più use case e aumentano il comportamento dei casi base, con la differenza che con l'estensione l'attore non può eseguire tutto sempre in quanto deve rispettare delle condizioni, che non sono presenti invece con l'inclusione.

Nell'inclusione una stessa funzionalità si ripete in più casi, mentre l'estensione serve a descrivere variazioni di una funzionalità standard.

## Generalizzazione

Serve ad aggiungere o modificare caratteristiche base, si possono generalizzare sia gli attori che gli use case:

- Tra attori la generalizzazione avviene se uno condivide almeno le funzionalità dell'altro
- Tra use case i casi figli possono aggiungere e modificare le funzionalità del genitore, tutte le funzionalità non ridefinite mantengono lo stesso funzionamento del genitore

# 7. Diagramma Delle Classi

# Diagramma Delle Classi

I diagrammi di classe mostrano le diverse _classi_ che _costituiscono un_ _sistema_ e come si _relazionano_ una all'altra.

Sono diagrammi statici:
- mostrano le classi, insieme ai loro metodi e attributi oltre alle relazioni statiche tra loro
- non mostrano le chiamate ai metodi tra di loro

## Classi

Una classe è il _descrittore_ di un insieme di oggetti o (istanze della classe) che condividono gli stessi attributi, operazioni, metodi, relazioni e comportamento.

Viene rappresentata da un rettangolo contenente il suo nome in una sottosezione rettangolare.

![[Classi.png|center]]

Il nome è l’unica sottosezione obbligatoria. Facoltativamente, si possono mostrare gli __attributi__ (campi) e le __operazioni__ (metodi) della classe in due altre sottosezioni del rettangolo.

## Attributi

Gli attributi sono mostrati con almeno il loro __nome__, ma si possono includere anche il loro __tipo__, il _valore iniziale_ e altre proprietà.

### Visibilità

- __+__ sta per pubblici (_public_)
- __#__ sta per protetti (_protected_)
- __-__ sta per privati (_private_)
- __~__ sta per pacchetto (_package_)

## Operazioni

Le __operazioni__ (_metodi_) sono mostrate con almeno il loro nome, ma si possono includere anche i loro __parametri__ e i __tipi restituiti__.

Anche loro hanno diverse [[#Visibilità]]

![[Operazioni.png|center]]

Le _azioni_ che la classe sa eseguire descrivono i suoi __aspetti comportamentali__ e offrono un __servizio__ che può essere richiesto ad ogni istanza della classe.

- Direzione: in, out, inout (default in)
- Visibilità: + pubblica, - privata, # protetta
- Query
- Modificatori
- Operazione ≠ metodo (Se in presenza di _polimorfismo_)

## Relazioni

Diverse classi si possono relazionare tra loro in modi diversi:

- [[#Associazione]]
- [[#Aggregazione]]
- [[#Composizione]]
- [[#Generalizzazione/Specializzazione (ereditarietà)|Generalizzazione (ereditarietà)]]
- [[#Dipendenza]]
- [[#Interfacce e realizzazioni|Realizzazione]]

Permettono di descrivere _relazioni logiche_ tra le classi nel dominio applicativo

### Associazione

Un’associazione tra due classi indica che si può avere un collegamento tra una coppia di oggetti appartenenti alle due classi.

Le associazioni si indicano con:

- __nome dell'associazione__: un verbo che specifica l’azione che l’oggetto origine esegue sull'oggetto destinazione.
- __Nome dei ruoli__: un sostantivo che descrive il ruolo che gli oggetti possono ricoprire.
- __Navigabilità__: specifica se la comunicazione tra gli oggetti può essere uni o bidirezionale.
- __Molteplicità__: specifica per ciascun lato dell’associazione, quanti oggetti possono relazionarsi a un oggetto sull'altro lato.

Un'associazione è rappresentata da una __linea__ che connette le due classi. Nome, ruoli e molteplicità (__cardinalità__) possono essere inseriti sulla linea nelle vicinanze della classe a cui si riferiscono (oppure possono anche essere omessi).

![[Associazioni.png|center big]]

#### Molteplicità

![[Molteplicità.png|center]]

![[Molt2.png|center]]

#### Classi Di Associazioni

Nelle relazioni molti a molti non sempre è possibile assegnare un attributo ad una delle due classi.

```ad-example
collapse: open

- Ogni oggetto Persona può essere dipendente di molti oggetti Azienda. 
- Ogni oggetto Azienda può impiegare molti oggetti Persona
- Si assuma che ogni Persona percepisce uno stipendio da ogni Azienda in cui lavora. 

Dove collochiamo l’attributo stipendio: nella classe Persona o nella classe Azienda?

Per ogni associazione “impiega” tra un oggetto Persona e un oggetto Azienda, c’è uno specifico stipendio per uno specifico rapporto di lavoro. L’UML consente di modellare questa situazione con una classe associazione.


```

Una __classe associazione__ è un’associazione che è anche una classe. Oltre a connettere due classi, definisce un insieme di caratteristiche proprie dell’associazione.

Una classe associazione è rappresentata:

- dalla linea dell’associazione (compresi tutti i nomi di ruolo e molteplicità),
- dal rettangolo della classe
- dalla linea tratteggiata verticale che li collega.

![[classi_associazioni.png|center]]

#### Navigabilità Di Un'associazione

Il nome di una associazione, se possibile non dovrebbe esprimere una direzione, oppure esprime la direzione/navigazione prevalente

```ad-example
collapse: open

![[navigabilita.png|center]]

```

### Aggregazione

Le __aggregazioni__ sono un tipo speciale di associazione nel quale le due classi partecipanti non hanno un rango uguale, ma hanno una relazione di tipo __tutto-parte__.

Un'aggregazione descrive come la classe che ha il ruolo del tutto è composta di altre classi, che hanno il ruolo di parti.

Le aggregazioni sono rappresentate da un’associazione che mostra un rombo sul lato dell’aggregato

![[aggregazione.png|center big]]

### Composizione

La composizione è una forma più forte di aggregazione, con la differenza che in una composizione la _parte_ non può esistere _al di fuori del tutto_:

- le parti esistono solo all'interno del tutto
- se il tutto è distrutto anche le parti muoiono

Graficamente indicata da rombo solido/pieno a lato «classe tutto» diretta verso «classe parte»

![[composizione.png|center big]]

Ogni parte appartiene ad un unico composito, dunque possono esistere gerarchie di composizione, ma non possono esistere reti di composizione (albero).

### Generalizzazione/Specializzazione (ereditarietà)

l’ereditarietà serve a derivare una nuova classe (_sottoclasse_) da una classe esistente (_superclasse_) in modo tale che la sottoclasse:

- __acquisisce__ (eredita) tutti gli attributi e le operazioni (metodi) della superclasse,
- può __aggiungere__ altri attributi e operazioni proprie,
- può __ridefinire__ alcune operazioni della superclasse.

In UML si usa il termine __generalizzazione__ per indicare che una classe __è una superclasse__ di un’altra classe.

La generalizzazione (specializzazione) è rappresentata da una linea che connette le due classi con una freccia (triangolo vuoto) dalla classe derivata (sottoclasse) alla classe base (superclasse).

In UML è possibile rappresentare __l’ereditarietà multipla__

![[ereditarieta.png|center big]]

### Classi Astratte

Una classe che __non può essere instanziata__, non ha implementazione.

### Dipendenza

Una dipendenza è una relazione tra due o più elementi del modello, dove un cambiamento ad uno di essi (__fornitore__) _può influenzare_ o fornire delle informazioni necessarie all'altro (__cliente__).

```ad-tldr
title: Definizione

Si ha dipendenza tra due elementi di un diagramma se la modifica alla definizione del primo (server) può cambiare la definizione del secondo (client)

```

Le dipendenze vanno minimizzate (Loose coupling), perché troppe dipendenze creano confunsione nel diagramma

#### Dipendenze D'uso

Il cliente usa alcuni servizi della classe fornitore (come parametro, valore restituito o nella sua implementazione) per implementare il proprio comportamento (invoca metodi).

Le dipendenze sono indicate con frecce tratteggiate dal cliente verso il fornitore

![[dipend.png|center big]]

#### Tipi Di Dipendenze

![[tipi_dip.png|center]]

### Interfacce E Realizzazioni

Un’__interfaccia__ è un insieme di funzionalità pubbliche identificate da un nome (quindi soltanto metodi, no attributi).

Una __realizzazione__ è una relazione tra una classe e un’interfaccia; indica che la classe implementa le operazioni dell’interfaccia.

Un'interfaccia è una __classe priva di implementazione__, una classe _realizza_ un'interfaccia se ne _implementa_ le operazioni

![[interfacce.png|center big]]

La relazione di realizzazione è visualizzata da una linea tratteggiata con una freccia (triangolo vuoto) che punta dalle realizzazioni all’interfaccia

## Caratteristiche Varie

### Operazioni E Attributi Statici

Sono applicabili alla classe non instanziata, quindi non all'oggetto.

Sottolineati sul diagramma

### Parole Chiave

Estendono la semantica dell'UML, sono formate da costrutto simile + parola chiave

### Responsabilità

Funzionalità offerte (commenti)

### Proprietà Derivate

Possono essere calcolate a partire da altri valori, si indicano con "/" prima del nome

### Proprietà Readonly E Frozen

Come dice il nome, le readonly non offrono servizi di scrittura e le frozen non possono variare il loro ciclo di vita

### Enumerazioni

Insiemi di valori che non hanno altre proprietà oltre il valore simbolico

### Classi Parametriche

Segnaposti (es: genetics in java)

### Classi Attive

Eseguono e controllano il proprio _thread_

# Diagramma Degli Oggetti

Rappresenta le __istanze__ comprese di associazioni e valori delle proprietà, è utile per esempi illustrativi e oggetti particolati (Singleton).

- è una fotografia degli oggetti che compongono un sistema, nessuna parte è obbligatoria.
- Utile quando i collegamenti tra le classi sono complicati
- Viene usato nei diagrammi di sequenza
- gli oggetti vengono specificati con nome_oggetto_instanza : nomeClasse
- Rappresenta singole associazioni tra gli oggetti


# 8. Diagrammi di sequenza

Descrivono la __collaborazione__ di un gruppo di _oggetti_ ( non classi!!!) che devono __implementare__ collettivamente un _comportamento_ solitamente relativo a uno _scenario di un caso d’uso_

# Partecipanti

Entità che detengono il flusso del caso d'uso, possono essere oggetti o altri concetti più ampi

## Barra Di Attivazione

Indica in quale momento un partecipante è attivo. Il tempo scorre dall'alto al basso.

# Messaggi

__Dati e operazioni__ scambiati tra i partecipanti, sono chiamate a metodi degli oggetti da parte di altri oggetti

## Tipologie Di Messaggi, Segnali, Chiamate Di Metodi

![[tipi_messaggi.png|center]]

## Passaggi Di Dati

Non esiste una tecnica di modellazione standard, ma ci sono 2 rappresentazioni utilizzate in pratica:

- Metodo classico ![[dati_classici.png|center]]
- Girini dei dati (data tadpoles) ![[data_tadpoles.png|center]]

### Messaggi Sincroni

Il chiamante rimane in attesa della risposta ![[messaggi_sincroni.png|center]]

### Messaggi Asincroni

Il chiamante non rimane in attesa della risposta ![[messaggi_asincroni.png|center]]

### Messaggi Di Ritorno

Sono da utilizzare solo se necessario, per chiarezza

![[messaggi_ritorno.png|center]]

### Tempo Di Trasmissione

Solitamente è trascurabile, se non lo è si può annotare la durata o etichettare i messaggi aggiungendo una nota.

![[tempo_trasmissione.png|center]]

# Cicli E Condizioni

Le condizioni sono solitamente limitate a uno scenario con __condizioni guardia__ o un __ramo else__.

I cicli solitamente sono limitati da iterazioni indicate con * e/o condizioni guardia.

## Frame Di Interazione

![[frame_interazione.png|center]]

# Modellazione

I diagrammi di sequenza sono ottimi per modellare le collaborazioni tra oggetti, ma non sono adeguati per modellare cicli e condizioni (meglio i diagrammi di attività)

# Relazione Con Diagrammi Di Classe

Nel diagramma di SEQUENZA compaiono oggetti con nome (es. X: NomeClasse) o oggetti anonimi (es. :NomeClasse) tutti appartenenti a classi, mentre NON compaiono MAI CLASSI ISOLATE (es. NomeClasse)

Tutte le classi cui appartengono gli oggetti DEVONO essere dichiarate nel diagramma di classe

Tutti i metodi (segnali, messaggi) chiamatisugli oggetti DEVONO essere definiti nella classe dell’oggetto su cui il metodo è chiamato (quello sulla punta della freccia) e NON sulla classe dell’oggetto chiamante (quello da cui parte la freccia)

# Diagrammi Di Collaborazione

I diagrammi di collaborazione o anche diagrammi di comunicazione mostrano una particolare sequenza di messaggi scambiata tra un certo numero di oggetti, esattamente come i diagrammi di sequenza, con la differeza che i diagrammi di sequenza seguono l'ordinamento temporale mentre quelli di collaborazione modellano l'organizzazione del flusso di controllo, mostrando collegamenti tra gli oggetti considerando una particolare sequenza di messaggi alla volta.

I diagrammi di Collaborazione sono COMPLEMENTARI ai diagrammi di Sequenza

![[diag_collaborazione.png|center]]

# 9. Diagrammi di stato

I diagrammi di stato descrivono il comportamento di singoli oggetti in più use case.

Vengono utilizzati per mostrare il comportamento di un singolo oggetto, per oggetti multipli si utilizzano i diagrammi di sequenza e di attività.

Non vanno scritti per ogni classe ma solo per casi significativi o poco chiari.

# Elementi

![[diag_stato_elem.png|center big]]

# Transizioni

Sono il cambiamento tra uno stato all'altro e presentano i seguenti elementi:

- __source__ e __target__ state: collegati da una linea che indica la transizione
- __trigger event__: evento che innesca la transizione
- __guard condition__: espressione booleana valutata quando si verifica il trigger event, la transizione può avvenire solo se si avvera la condizione di guardia
- __action__: una computazione atomica eseguibile che agisce direttamente sull’oggetto o indirettamente su altri oggetti ad esso visibili
- __Stato iniziale__ e __stati finali__: sono indicati rispettivamente tramite un cerchio nero, ed un cerchio nero circondato da un cerchio vuoto

![[transizioni.png|center big]]

# Azioni

Hanno durata istantanea, e sono associate alle [[#Transizioni]]

![[azioni.png|center big]]

# Attività

Hanno durata prolungata e sono associate agli stati

![[attivita.png|center big]]

# Decomposizioni

## OR

C'è un solo stato attivo

## AND

esecuzione parallela

### Fork

Genera due flussi paralleli

### Join

Chiede la terminazione di entrambi i flussi

## Sincronizzazione

Si generano eventi per sincronizzare processi paralleli

![[sinc_eventi.png|center]]

# Superstati

![[superstati.png|center]]

# Stati Concorrenti

![[Pasted image 20230509151721.png|center]]


# 11. Test e Verifica

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

