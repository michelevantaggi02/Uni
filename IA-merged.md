# 0. Intelligent Agent

![[intelligent_agent.svg|center small]]

# Esempi Di Intelligent Agent

A seconda delle necessità gli attori possono sfruttare vari ruoli nell'utilizzo dell'agente, questi sono solo alcuni esempi (non da prendere alla lettera)

## Robotic Agent

![[robotic_agent.svg]]

Esempio di un agente (in questo caso un robot) che interagisce con il mondo reale attraverso diversi dispositivi

## Gamer Agent

![[gamer_agent.svg]]

Esempio di un agente che interagisce contro di noi (ad esempio in una partita a scacchi)

## Diagnostic Agent

![[diagnostic_agent.svg]]

Sulla base delle informazioni ricevute l'agente elabora delle informazioni che possono passare anche attraverso un'intermediario (es: il dottore che effettua poi una diagnosi)

## Crawler

![[crawler.svg]]

Il crawler svolge il suo lavoro indipendentemente dalla presenza di utenti che lo utilizzano, una volta che un utente gli chiede qualcosa svolge le valutazioni necessarie sui dati presenti nel suo database e risponde di conseguenza

# Keywords

Parole chiave che caratterizzano l'ambiente:

- **completamente** / *parzialmente* osservabile
- **deterministico** / *stocastico*
- **discreto** / *continuo*
- **benigno** / *avversariale*

Una volta individuato l'ambiente in cui ci troviamo, possiamo scegliere l'algoritmo più adatto

```ad-note
title: Branching factor

Diramazioni rispetto alla scelta presa dall'agente

```

^3ea88e

## Partially observing agent
![[partial_agent.svg]]
Bisogna fare ipotesi sul prossimo stato assunto dall'ambiente, senza avere a disposizione tutte le informazioni


# 1. Agente Razionale


Un agente che di solito fa la cosa giusta

```ad-question
title: Ma come si decide qual è la cosa giusta?


```

- Misura di prestazione
- Conoscenza dell'ambiente
- Azioni che può eseguire
- Sequenza percettiva

```ad-important
title: Agente razionale


Per ogni possibile sequenza di percezioni, un agente razionale dovrebbe __scegliere un'azione che massimizzi il valore atteso__ della sua misura di prestazione, date le informazioni __fornite dalla sequenza percettiva__ e da ogni ulteriore conoscenza dell'agente
```

```ad-example
title: Aspirapolvere

![[aspirapolvere.png]]

Pulisce la stanza se è sporca, altrimenti va nell'altra stanza.

3 azioni:
- Vai nella stanza a destra
- Vai nella stanza a sinistra
- Aspira la sporcizia

~~~ad-question
title: è razionale?

Non possiamo rispondere senza un criterio

__Misura di prestazione__:
	$m_1$ +1 per ogni stanza pulita
~~~
```

# Rappresentazione Degli Stati

![[RapprStati.png]]

Noi lavoreremo sugli stati __atomici__

# Search Problem

| alg | completezza | ottimalità |             costo spazio             |             costo tempo              |
|:---:|:-----------:|:----------:|:------------------------------------:|:------------------------------------:|
| BFS |     si      |     si     |               $O(b^m)$               |               $O(b^m)$               |
| UCS |     si      |     si     | $O(b^{\frac {C*}{\varepsilon} + 1})$ | $O(b^{\frac {C*}{\varepsilon} + 1})$ |
| DFS |     no      |     no     |               $O(bd)$                |               $O(b^d)$               |
| DLS |     no      |     no     |               $O(bl)$               |               $O(b^l)$                |
| IDS |     si      |     si     |               $O(bd)$                | $O(b^d)$                                     |

- state space ($S$)
- initial state ($s_i \in S$)
- goal_test($S$)$\to$ true | false
- actions($S$) = $\{a_1,...,a_n\}$
- results($S,a$)$\to S'$
- path_cost($S\substack {a\\\to} ... \substack {a_n \\ \to}S_n$) = $n$
  step_cost($S,a,S'$) = $n$

Se ho step_cost posso calcolare path_cost

```ad-example
title: Romania🇷🇴

![[mappaRomania.png]]

Se voglio andare da __Arad__ a __Bucarest__ basta rappresentare le città come stati e le azioni come lo spostarsi da una città ad un'altra

- state space: tutte le città
- initial state: Arad
- goal_test(S): is Bucarest?
- actions(S): {vai a città #}, # è una città raggiungibile
- results(S,a) = città di arrivo
- step_cost(S,a,S') = costo sulla mappa


```

## Best-first-search

	function BEST-FIRST-SEARCH(problem, f ) returns a solution node or failure
		node ← NODE(STATE=problem.INITIAL)
		frontier ← a priority queue ordered by f , with node as an element
		reached ← a lookup table, with one entry with key problem.INITIAL and value node
		while not IS-EMPTY(frontier ) do
			node ← POP(frontier )
			if problem.IS-GOAL(node.STATE) then return node
			for each child in EXPAND(problem, node) do
				s ← child .STATE
				if s is not in reached or child .PATH-COST < reached [s].PATH-COST then
					reached [s] ← child
					add child to frontier
		return failure


	function EXPAND(problem, node) yields nodes
		s ← node.STATE
		for each action in problem.ACTIONS(s) do
			s′ ← problem.RESULT(s, action)
			cost ← node.PATH-COST + problem.ACTION-COST(s, action, s′)
			yield NODE(STATE=s′, PARENT=node, ACTION=action, PATH-COST=cost)

## Breadth-first-search (BFS)

Riguardare anche [[a1. Grafi#Breadth First Search]]

	function BREADTH-FIRST-SEARCH(problem) returns a solution node or failure
		node ← NODE(problem.INITIAL)
		if problem.GOAL-TEST(node.STATE) then return node
		frontier ← a FIFO queue, with node as an element
		reached ← {problem.INITIAL}
		while not IS-EMPTY(frontier ) do
			node ← POP(frontier )
			for each child in EXPAND(problem, node) do
				s ← child .STATE
				if problem.GOAL-TEST(s) then return child
				if s is not in reached then
					add s to reached
					add child to frontier
		return failure

### Proprietà

Processa tutti i nodi più superficiali, data la profondità della soluzione più superficiale come $s$, il tempo e lo spazio di ricerca sono di $O(b^s)$.

- $s$ è finito se esiste una soluzione, quindi è completo.
- è __ottimale__ solo se __i costi sono tutti 1__

## Uniform-cost-search (UCS)

	function UNIFORM-COST-SEARCH(problem) returns a solution or failure
		node <- NODE(problem.INITIAL)
		frontier <- priority queue ordered by PATH-COST, with node as only element
		explored <- empty set
		while NOT IS-EMPTY(frontier) do
			node <- POP(frontier) //chooses the lowest-cost node
			if problem.GOAL-TEST(node.state) then return node
			add node.STATE to explored
			for each action in problem.ACTIONS(node.STATE) do
				child <- CHILD-NODE(problem, node, action)
				if child.STATE is not in explored or frontier then
					add child to frontier
				else if child.STATE is in frontier with higher PATH-COST then
					replace frontier node with child
			
		return failure

### Proprietà

Processa tutti i nodi con costo minore della soluzione con costo minore, se quella soluzione costa $C^*$ e gli archi hanno costo di almeno $\varepsilon$, allora la "profondità effettiva" è di $C^* / \varepsilon$ e il tempo e lo spazio di esecuzione sono quindi $O(b^{C^* / \varepsilon})$

- Assumendo che la soluzione abbia costo finito e che il costo minimo di un arco sia positivo, allora è completo
- è ottimale (Prova tramite $A^*$)

## Depth-first-search (DFS)

Riguarda anche [[a1. Grafi#Visita in Profondità (DFS-visit)]]

	function DEPTH-FIRST-SEARCH(problem) returns a solution or failure
		node <- NODE(problem.INITIAL)
		frontier <- LIFO queue with node as element
		explored <-  empty set
		while NOT IS-EMPTY(frontier) do
			node <- POP(frontier)
			if problem.GOAL-TEST(node.state) then return node
			add node.state to explored
			for each child in EXPAND(problem, node) do
				if child.state not in explored and child not in frontier then
					add child to frontier
		return failure

### Proprietà

Espande alcuni nodi a sinistra dell'albero (potrebbe processare tutto l'albero), se $m$ è finito, impiega in tempo $O(b^m)$ e in spazio $O(bm)$

- è completo solo se preveniamo i cicli, quindi $m$ potrebbe essere finito
- __Non è ottimale__, trova solamente la soluzione "più a sinistra",

## Tree-search

	function TREE-SEARCH(problem):
	frontier = {[initial]}
	loop:
		if frontier is empty: return fail
		path = remove_choice(frontier)
		s = path.end
		if s is a goal: return path
		for a in actions:
		add [path + a to result(S, G)] to frontier

## Proprietà Degli Algoritmi Di Ricerca

- Completo: è garantito che trovi una soluzione se questa esiste?
- Ottimo: è garantito che trovi il percorso di costo minore?
- Complessità di tempo
- Complessità spaziale

![[0. Intelligent Agent#^3ea88e]]

- più è grande il branching factor (b) più è complessa la ricerca
- _m_ è la profondità massima
- Le soluzioni si possono trovare a diverse profondità
- numero di nodi nell'intero albero:$$1+ b + b^2 + ... + b^m = O(b^m)$$

![[prop_algoritmi_ricerca.png|center]]

``````ad-example
title: Ottimalità BFS

\# passi o costo se $\text{step\_cost(a)} = \text{step\_cost(a')} \forall a,a' \in \text{ACTIONS}$

$$O(b^n) \text{ spazio}$$
$$O(b^n) \text{ tempo}$$

```ad-question
title: Completezza

si perché se esiste soluzione l'albero ha costo finito

```

``````

```ad-example
title: Ottimalità UCS

- Completezza: si
- Ottimalità: si
$$O(b^{\frac {C*}{\varepsilon} + 1}) \text{ spazio e tempo}$$

```

```ad-example
title: Ottimalità DFS

- Completezza: no
- Ottimalità: no

$$O(bm) \text{ spazio}$$
$$O(b^m) \text{ tempo}$$
```

## Iterative Deepening

L'idea è di utilizzare la DFS per il suo costo in spazio, con i vantaggi di tempo della BFS.

Eseguo la DFS con un limite sulla profondità che aumenta ad ogni iterazione.

```ad-question
title: Non è uno spreco eseguire tante volte gli stessi passi?

Si, ma la maggior parte dei calcoli va fatta nel livello più basso (o il limite in questo caso), quindi non è così male

```

	function ITERATIVE-DEEPENING-SEARCH(problem) returns a solution or failure
		for depth = 0 to INFINITE do
			result <- DEPTH-LIMITED-SEARCH(problem, depth)
			if result is not cutoff then
				return result

	function DEPTH-LIMITED-SEARCH(problem, l) return a node or failure or cutoff
		frontier <- STACK with NODE(problem.INITIAL) as element
		result <- failure
		while not IS-EMPTY(frontier) do
			node <- POP(frontier)
			if problem.GOAL-TEST(node.state) then return node
			if DEPTH(node) > l then
				result <- cutoff
			else if not IS-CYCLE(node) do
				for each child in EXPAND(problem, node) do
					add child to frontier
		return result

# Ricerca Informata (Euristica)

```ad-important
title: Funzione euristica

funzione arbitraria problem specific, stima il costo per raggiungere il goal dallo stato.
- $h(\text{goal}) = 0$
- $h(s) > 0$

è calcolabile in tempi ragionevoli

```


```ad-important
title: Greedy  Best First

[[#Best-first-search]] con coda di priorità organizzata secondo $h$

```


```ad-important
title: Algoritmo $A^*$

Combina:

- Costo $g(n) = \text{PATH\_COST}(n)$ per raggiungere $n$ dallo stato iniziale
- Euristica $h(n)$ stima per raggiungere il GOAL a partire da $n$
$$f(n) = g(n) + h(n)$$

Se $h$ è __ammissibile e consistente__ allora $A^*$ è __ottimale__

```

![[comp_algoritmi.png]]

Con $A^*$ abbiamo trovato lo stesso percorso espandendo molti meno nodi.

A parità di costo bisogna avere "fortuna", dato che i nodi vengono poi espansi in ordine

```ad-fail
title: Problema

![[sovrastima.png]]

Abbiamo sovrastimato il costo di $A$ impedendogli di avere la possibilità di essere espanso

```

## Euristica Ammissibile

Un'euristica $h$ è ammissibile se $$h(n) \leq h^*(n)$$

dove $h^*(n)$ è il vero costo per il goal più vicino.

Trovare un'euristica ammissibile è il lavoro più grande nell'usare $A^*$ in pratica.

```ad-check
title: $h$ ammissibile e $A^*$ ottimale

Se $h$ è ammissibile $\implies$ $A^*$ è ottimale rispetto al costo.

Per assurdo $h$ ammissibile e $\exists$ percorso meno costoso di quello trovato da $A^*$

- $C^*$ costo cammino ottimo
- $n$ nodo sul cammmino ottimo che non è stato espanso, $f(n) > C^*$
- $g^*(n)$ costo ottimo del cammmino fino ad $n$
- $h^*(n)$ costo ottimo da $n$ fino al goal


$$f(n) = g(n) + h(n) = g^*(n) + h(n) \leq g^*(n) + h^* (n) = C^* \implies f(n) \leq C^*$$

L'ipotesi di $h$ ammissibile e $A^*$ non ottimale è assurda

```

### Consistenza

$h(n)$ è __consistente__ se $\forall$ nodo $n, n' : n' \in \text{ACTIONS}(n)$ allora $h(n) \leq h(n') + c(n, a , n')$

Se $h$ è consistente allora è anche ammissibile, ma non il contrario

![[RomaniaAstar.png]]

## Contorni Di $A^*$

$A^*$ è ottimamente efficiente, ma non ci interessa

![[contorni_Astar.png|center]]

Rispetto alla [[#Uniform-cost-search (UCS)]] lo spazio di ricerca di f$A^*$ è completamente diverso. Se $h$ è fatta bene, $A^*$ controlla nodi di soluzione sempre crescente e i contorni saranno incentrati al percorso ottimale.

### Proprietà Di $A^*$

- Completezza, a meno che non ci siano infiniti nodi di costo maggiore
- Ottimale, nessun altro algoritmo euristico ne espande di meno
- Tempo esponenziale nel caso peggiore
- Spazio esponenziale nel caso peggiore

### Ricerca $A^*$ Pesata

_A* ha molte qualità ma espande troppi nodi_ (quindi occupa tanta memoria), quindi il compromesso giusto è quello di __determinare una soluzione sub-ottima__, in A* un euristica __inammissibile è utilizzabile__ se la soluzione è abbastanza ottima.

Il problema di espandere troppi nodi può essere rilevante se lo spazio in cui lavora è molto grande In **A* pesata** la funzione f è uguale alla solita ma utilizzia in più un valore W che pesa l'euristica, cioè $$f(n) = g(n) + W \times h(n)$$

_Quando si utilizza A* con un'euristica consistente_, sebbene possa espandere un gran numero di nodi durante la ricerca, l'efficienza complessiva è mantenuta grazie alla capacità dell'euristica di _"potare" (eliminare - pruning)_ rami dell'albero di ricerca che non sono necessari per trovare la soluzione ottima. Questa è una delle caratteristiche chiave di A* che lo rende un algoritmo di ricerca efficiente quando è ben bilanciato in quanto i percorsi che va ad espandere sono in qualche modo correlati al percorso ottimo. È molto più __facile trovare__ euristica __buone ma non ammissibili__ che euristiche ammissibili.

## $A^*$ Ad Approfondimento Iterativo (IDA*)

- Elimina le limitazioni di memoria di $A^*$ senza sacrificare l'ottimalità della soluzione
- Ogni iterazione dell'algoritmo è una [[#Depth-first-search (DFS)]] che tiene traccia del costo $f(n) = g(n) + h(n)$ di ogni nodo generato
- Quando il costo di nodo eccede la soglia per quell'iterazione, il suo percorso viene tagliato fuori, e la ricerca torna indietro
- La soglia del costo viene inizializzata all'euristica stimata dello stato iniziale
- Ad ogni iterazione la soglia viene aumentata del costo totale del nodo con costo più basso che è stato rimosso nella precedente iterazione.
- L'algoritmo termina quando viene raggiunto un goal il cui costo totale non eccede la soglia attuale.

### Vantaggi

- Se l'__euristica__ è __ammissibile__, IDA* trova la __soluzione ottimale__
- I requisiti in memoria sono lineari rispetto alla profondità massima di ricerca

### Difetti

- Non è una ricerca best-first a tutti gli effetti
- Si espandono gli stessi nodi, spesso sono quelli più vicini alla radice che sono di meno e hanno un costo che possiamo sopportare
- Quando ricomincia scarta tutte le informazioni tranne la prossima soglia

## Recursive-best-first (RBFS)

	function RECURSIVE-BEST-FIRST(problem) returns a solution or failure
		solution, fvalue <- RBFS(problem, NODE(problem.INITIAL), INFINITE)
		return solution

	function RBFS(problem, node, f_limit) returns solution or failure and a new limit
		if problem.GOAL-TEST(node.STATE) then return node
		successors <- LIST(EXPAND(node))
		if IS-EMPTY(successors) then return failure, INFINITE
		for each s in successors do //aggiorno f con il valore della ricerca precedente
			s.f <- max(s.PATH-COST + h(s), node.f) 
		while true do
			best <- nodo in successors con f-value minore
			if best.f > f_limit then return failure, best.f
			alternative <- secondo f-value tra i successori
			result, best.f <- RBFS(problem, best, min(f_limit, alternative))
			if result is not failure then return result, best.f

L'idea è quella di avere tutti i vantaggi della [[#Breadth-first-search (BFS)]], con un'utilizzo lineare della memoria:

- Non mantiene aperti tutti i rami (Come fa A*),ma usa una variabile per ricordare la seconda scelta migliore
- Quando la prima scelta fallisce (diventa peggiore della seconda), l'algoritmo sa dove andare
- Cancella il ramo che fallisce, ricordandosi il valore migliore di $f$ per quel ramo


### Proprietà

- Come A* è ottimale se $h(n)$ è ammissibile
- La complessità in tempo è difficile da caratterizzare
	- dipende dall'accuratezza di $h(n)$ e quanto spesso cambia il percorso migliore
	- Può finire a fare avanti e indietro con i cambiamenti di ramo
- La complessità in spazio è  $O(bd)$ (altro estremo di A*, usa troppa poca memoria)

Troppa poca memoria vuol dire che deve rigenerare troppi nodi ad ogni iterazione, anche se c'è della memoria disponibile questa non può essere usata dall'algoritmo

## SMA*

Esiste la possibilità di avere un A* memory-bounded (MA*), una sua versione semplificata, chiamata SMA* ha queste caratteristiche:

- Come A* espande il child migliore, ma ha un limite in memoria
- Quando la memoria è piena deve cancellare un nodo, quello con il valore f-value più alto
- Come la RBFS mantiene il valore del nodo cancellato e il suo nodo padre

- Completo se c'è abbastanza memoria da contenere la soluzione
- Ottimale se viene raggiunta la soluzione ottima

# 2. Giochi avversari


Search-non adversary:

- Ricerca euristica per trovare il goal
- Possiamo trovare la soluzione ottima
- Le funzioni di valutazione vengono determinate dal costo

Games-adversary:

- Strategia per ogni possibile mossa dell'avversario
- Il limite di tempo obbliga ad approssimare la soluzione
- Le funzioni di valutazione delle volte non sono ovvie

La difficoltà del gioco è determinata dal branching factor (il numero di mosse possibli in un certo livello).

Sappiamo che un gioco è __risolto__ quando la __soluzione è ottima__.

# Tipi Di Giochi

- deterministici o stocastici
- uno, due o più giocatori
- Somma zero
- informazioni perfette (puoi vedere lo stato)

Voglio un algoritmo che calcoli una strategia (policy) che consigli una mossa per ogni stato.

## Giochi Deterministici

Ci sono molte formalizzazioni possibili, una è:

- Stati: $S$ (parte da $s_0$)
- Giocatori $P= \{1,...,n\}$ (di solito a turni)
- Azioni: $A$ (dipendono dal giocatore / stato)
- Funzioni di transizione: $S\times A \to S$
- Test terminali: $S \to \{t,f\}$
- Utilità terminali: $S \times P \to R$

La soluzione per un giocatore è un insieme di azioni chiamata __policy__:$S \to A$

## Giochi a Somma Zero

- Gli agenti hanno utilità opposte
- Ci fa pensare ad un singolo valore che uno massimizza e un'altro minimizza
- Avversari, pura competizione

### Giochi Generali

- Gli agenti hanno utilità indipendenti
- Cooperazione, indifferenza, competizione e altro sono tutti possibili

# Algoritmo MiniMax

	function MINIMAX-SEARCH(game, state) returns an action
		player <- game.TO-MOVE(state)
		value, move <- MAX-VALUE(game, state)
		return move

	function MAX-VALUE(game, state) returns (utility, move)
		if game.IS-TERMINAL(state) then return game.UTILITY(state, player), null
		v <- -INFINITE
		for each a in game.ACTIONS(state) do
			v2, a2 <- MIN-VALUE(game, game.RESULT(state, a))
			if v2 > v then
				v, move <- v2, a
		return v, move

	function MIN-VALUE(game, state) returns (utility, move)
		if game.IS-TERMINAL(state) then return game.UTILITY(state, player), null
		v <- INFINITE
		for each a in game.ACTIONS(state) do
			v2, a2 <- MAX-VALUE(game, game.RESULT(state, a))
			if v2 < v then
				v, move <- v2, a
		return v, move

- Algoritmo di gioco completo
- utility(s) $\forall s$ terminale definito utility di max

$$
\max(s) = \begin{cases}

\text{utility}(s, \max)&&\text{if s è terminale}\\
\substack{\max \\ a \in \text{actions(s)}} & \text{minimax(results(s,a))}& \max=\text{to\_move(s)}\\
\substack{\min \\ a \in \text{actions(s)}} & \text{minimax(results(s,a))}& \min=\text{to\_move(s)}\\

\end{cases}
$$

Definizione problema gioco a 2 giocatori a somma 0

## Implementazione Minimax

	function max-value(state):
		v <- -INFINITE
		for each successor of state:
			v = max(v, min-value(successor))
		return v

	function min-value(state):
		v = INFINITE
		for each successor of state:
			v = min(v, max-value(successor))
		return v

![[imp_minimax.png|center big]]

```ad-example
title: Minimax

![[minimax.svg]]

Abbiamo gli stessi vantaggi della ricerca in profondità, quindi possiamo eliminare i nodi che non ci servono, con tempo esponenziale


![[minimax 1.svg]]

Una volta trovato il primo min (3), se troviamo un valore che sia inferiore possiamo ignorare tutti gli altri valori superiori.

Se stiamo calcolando il MIN-VALUE di un certo nodo $n$:

- Iteriamo tra i child di $n$
- La stima dei child sta calando
- A chi importa del valore di $n$? MAX
- Sia $a$ il valore migliore che MAX possa scegliere lungo il percorso corrente dalla radice
- Se $n$ diventa peggiore di $a$, MAX lo eviterà, così possiamo ignorare gli altri figli di $n$

Per MAX è la stessa cosa ma al contrario

```

## Alfa-Beta Pruning

	function ALFA-BETA-SEARCH(game, state) returns an action
		player <- game.TO-MOVE(state)
		value, move <- MAX-VALUE(game, state, -INFINITE, INFINITE)
		return move

	function MAX-VALUE(game, state, alfa, beta) returns (utility, move)
		if game.IS-TERMINAL(state) then return game.UTILITY(state, player), null
		v <- -INFINITE
		for each a in game.ACTIONS(state) do
			v2, a2 <- MIN-VALUE(game, game.RESULT(state, a), alfa, beta)
			if v2 > v then
				v, move <- v2, a
				alfa <- MAX(alfa, v)
			if v >= beta then return v, move
		return v, move

	function MAX-VALUE(game, state, alfa, beta) returns (utility, move)
		if game.IS-TERMINAL(state) then return game.UTILITY(state, player), null
		v <- INFINITE
		for each a in game.ACTIONS(state) do
			v2, a2 <- MAX-VALUE(game, game.RESULT(state, a), alfa, beta)
			if v2 < v then
				v, move <- v2, a
				beta <- MIN(beta, v)
			if v <= alfa then return v, move
		return v, move

![[minimax 1.svg]]

- Il pruning non ha effetto sui valori calcolati per la radice
- I valori dei nodi intermedi potrebbero essere sbagliati
- Un buon ordinamento dei child migliora l'efficacia del pruning
- Con un ordinamento perfetto:
	- Complessità di tempo scende a $O(b^{m/2})$
	- Raddoppia la profondità risolvibile
	- La ricerca completa resta senza speranze (ad esempio a scacchi)

Questo è un esempio di __metareasoning__ (pensare a cosa calcolare)

# Limitare La Profondità

Realisticamente nei giochi non si può cercare tutto fino alle foglie, per questo viene suggerita la Depth-limited search.

- Invece di controllare tutto il grafo, si controlla soltanto fino a un certo limite di profondità
- Si rimpiazzano le utilities terminali con una __funzione di valutazione__ per le posizioni che non terminano.

```ad-example

Supponendo di avere 100 secondi per eseguire una mossa e che il nostro calcolatore può esplorare 10k nodi / secondo, possiamo esplorare 1 milione di nodi a mossa.

Con [[#Alfa-Beta pruning]] raggiungiamo all'incirca una profondità di 8, che in un programma di scacchi è una profondità decente.

```

## Funzioni Di Valutazione

Queste funzioni servono a dare un valore ai nodi non terminali che si raggiungono alla fine di una depth-limited search.

Idealmente dovrebbero ritornare l'effettivo valore minimax della posizione controllata, cosa che è effettivamente impossibile.

Nella pratica infatti si utilizza una somma di determinati valori (Es: la differenza tra il numero di pezzi dello stesso tipo) $$Eval(s) = w_1f_1(s) + ...+w_nf_n(s)$$

Queste funzioni sono __sempre imperfette__, più in profondità "nascondiamo" la funzione di valutazione, meno importante sarà la sua qualità.

# Risultati Incerti

Se vogliamo modellare elementi casuali che accadono nel mondo bisogna costruire algoritmi efficienti basati sulla casualità (Ex: Monte Carlo Tree Search), questi risultati incerti __non vengono controllati dall'avversario__, ma dalla __probabilità__

## Expectimax Search

```ad-question
title: Perché non possiamo sapere quale sarà il risultato di un'azione?

Potrebbe essere perché il gioco è basato sulla casualità (Es: tirare un dado), oppure l'avversario è imprevedibile (avversario che risponde casualmente), oppure alcune azioni possono fallire (Un robot che ha un malfunzionamento)

```

I valori in questo caso dovrebbero riflettere il __caso medio__ (expectimax), e non il caso peggiore (minimax)

```ad-important
title: Expectimax search

Calcola il valore meido secondo la giocata ottimale:

- Nodi MAX come in [[#Algoritmo MiniMax]]
- I nodi chance sono come i nodi MIN ma il risultato è incerto
- Calcola la loro utilità aspettata
- Prende la media pesata (aspettativa) dei figli

```

	function EXPECTIMAX-SEARCH(state)
		if IS-TERMINAL(state) then return state.utility
		else if NEXT-AGENT(state) = MAX then return MAX-VALUE(state)
		else if NEXT-AGENT(state) = MIN then return EXP-VALUE(state)

	function MAX-VALUE(state)
		v <- -INFINITE
		for each successor of state do
			v <- max(v, value(successor))
		return v

	function EXP-VALUE(state)
		v <- 0
		for each successor of state do
			p <- probability(successor)
			v += p * value(successor)
		return v

```ad-question
title: Quali probabilità usare?

Con la ricerca expectimax abbiamo un modello di probabilità di come l'avversario (o l'ambiente) si comporteranno in ogni stato. Il modello può essere sia semplice (come il tiro di un dado) che sofisticato (richiedenndo una grande quantità di calcoli).

Abbiamo un nodo probabilità per ogni risultato fuori dal nostro controllo: avversario o ambiente.

Il modello potrebbe anche dire che le azioni dell'avversario si assomigliano, per il momento bisogna assumere che ogni nodo probabilità venga fuori magicamente con delle probabilità che specificano la distribuzione sul suo risultato.

```

```ad-example
title: Probabilità informata

Diciamo che tu sappia che il tuo avversario stia utilizzando un minimax a profondità 2, utilizzando il suo risultato L'80% delle volte, mentre il 20% si muove casualmente.


In questo caso possiamo utilizzare expectimax per capire ogni probabilità dei nodi, eseguendo una simulazione del tuo avversario.

Questo tipo di cose diventano lente molto velocentente, ed è ancora peggio se devi simulare il tuo avversario che simula te che simuli tu ecc...

... Tranne per minimax, visto che viene tutto raggruppato in un singolo albero

```

# Mixed Layer

Un esempio è il backgammon, l'ambiente è un ulteriore "agente casuale" che si muove dopo ogni mossa di un agente min/max. Ogni nodo calcola l'appropriata combinazione dei suoi figli.

```ad-example
title: Backgammon

Il tiro di dadi aumenta $b: 21$ possibili tiri con 2 dadi.

A backgammon ci sono circa 20 mosse, con una profondità di 2 si ha $$\text{ Depth 2} = 20 \cdot (21 \cdot 21)^3 = 1.2 \cdot 10^9$$
Con l'aumentare della profondità, la probabilità che si raggiunga un dato nodo diminuisce, quindi è meno utile utilizzare la ricerca e limitare la profondità crea meno danni, ma è difficile il pruning.

TDGammon utilizza depth-2 search + funzione di valutazione molto buona + reinforcement learning + livello di gioco da campionato mondiale, risultato: 1a IA campione del mondo


```

# Utilità Multi-agente

Se il gioco non è a somma zero, oppure ha più giocatori, si può utilizzare una generalizzazione di minimax:

- I terminali hanno tuple di utilità
- I valori dei nodi sono anche loro tuple di utilità
- Ogni giocatore massimizza il proprio componente
- Può gestiire la cooperazione o la competizione dinamicamente

# Difficoltà con la ricerca

Anche utilizzando [[#Alfa-Beta Pruning]] e [[#Limitare La Profondità]], un $b$ molto grande crea problemi (ricorda che la complessità in tempo migliore è $b^{m/2}$).

Sugli scacchi è fattibile, con alfa-beta si ha $35^{(8/2)} \approx 1M$ , profondità 8 va abbasta bene;

Ma con GO: $300^{(8/21)} \approx 8B$ 

Inoltre limitare la profondità richiede di creare delle buone funzioni di valutazione __per ogni problema__, che se fatte male possono generare soluzioni inefficienti.

# 3. Machine Learning



