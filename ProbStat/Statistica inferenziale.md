Come passare dalla statistica descrittiva alla statistica inferenziale.

Individuare e usare modelli statistici idonei a descrivere il fenomeno aleatorio.

Fondamentalmente passare dal *campione* a *tutta la popolazione* (induzione statistica)

# Modelli Statistici Aleatori

Funzioni di probabilità (rispettano le regole del calcolo probabilistico) che descrivono i diversi gradi di "fiducia" con cui si possono "realizzare" dei valori della v.a. X che vengono usati per fare previsioni sulla variabile aleatoria.

## Diversi Nomi per v.a.

- Variabili casuali
- Fenomeni aleatori
- Variabili stocastiche
Sono tutti sinonimi di "popolazione" stocastica.
<mark style="background: #FF5582A6;">Non usare il termine "randomico"</mark>

## Caratterizzazione

Le v.a. si caratterizzano con due elementi:

1. Insieme dei valori possibili (modalità =$\Omega$, spazio campionario)
2. La "distribuzione" delle probabilità
La v.a. X può essere vista come un "potenziale esperimento" con possibile esito in $\Omega$.
Bisogna usare la "distribuzione di probabilità" per esprimere la nostra fiducia che $(x \in E )\subseteq \Omega$
```ad-note

- E sta per "Evento", espressione di senso compiuto che si possa verificare se è vera o falsa.
- Spesso la variabile X si intende come funzione $x:\Omega \to R$.
- Spazio campionario: Insieme in cui possono essere espresse le modalità di un campione.
```

## Funzioni Di Probabilità

Funzioni d'insieme

$$P:A \subseteq 2^\Omega \to [0,1]$$

$2^\Omega$ insieme delle parti

Per le v.a. discrete di solito $A=2^\Omega$

Per v.a. continue $A \subset 2^\Omega$, una famiglia chiusa che sia una $\sigma$ algebra (algebra infinita) contenente almeno $\{ \emptyset , \Omega\}$

### Assiomi

Non tutte le funzioni possono essere considerate "di probabilità", ma solo quelle che rispettano delle proprietà di "razionalità" (assiomi)

1. $\forall E \in A, P(E) \in [0,1], P(\Omega) = 1$
	1. $P(\Omega)$ evento certo $x \in \Omega$, attenzione che non vale in generale il viceversa ($P(E) = 1 \centernot \implies E=\Omega$)
2. Monotonia
	1. $E_1, E_2 \in A$
	2. $E_1 \subseteq E_2 \implies P(E_1) \leq P(E_2)$
3. Additività (finita)
	1. $E_1, E_2 \in A$
	2. $E_1 \wedge E_2 = \varnothing$
	3. $P(E_1 \vee E_2) = P(E_1) + P(E_2)$
Se A è $\sigma$-algebra (algebra infinita) si richiede la $\sigma$-additività:
Successione di eventi incompatibili.

$$E_1,E_2,...\quad E_1 \land E_2 = \emptyset \implies P(\bigvee_{i=1}^\infty{E_i}) = \sum_{i=1}^\infty{P(E_i)}$$
