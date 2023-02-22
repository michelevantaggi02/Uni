Data una funzione di probabilità $P:A\to [0,1]$

Che soddisfi i 3 assiomi

1. Se si può calcolare P(E) con $E \in A$ allora $P(E^c) = 1-P(E)$
	dim: $E \land E^c = \emptyset$ e $E \lor E^c = \Omega$ dall'assioma di additività (assioma 1) $P(E \lor E^c) = P(E) + P(E^c), P(\Omega) =1, P(E) = 1-P(E^c)$
2. Più in generale, considerando una partizione di $\Omega$ ($E_1,...,E_k : E_1 \lor ... \lor E_k = \bigvee_{i=1}^k{E_i}=\Omega$), $E_i \wedge E_j = \emptyset \quad \forall i \neq j \in \{1,...k\}$ deve necessariamente valere $$\sum_{i=1}^k{P(E_i)}=1$$

# V.A. Discrete

Una v.a. x discreta induce una partizione "naturale" su $\Omega$ con eventi $E_i \equiv (x = \{ 2_i\})$ con $w_i$ singola modalità di $\Omega$

$$P(E_i) \in [0,1] : \sum_{i=1}^k P(E_i) = 1$$

Proprietà soddisfatte dalle $f_i$ di un campione.

Come primo passo "inferenziale" si può prendere

$$P(E_i)=f_i$$

Nel caso $\Omega$ con cardinalità numerabile ($\Omega = \{\omega_1,\omega_2,...\}$) si richiede la $\sigma$-additività $$\sum_{i=1}^\infty{P(E_i)}=1,\quad E_i = (X = \{\omega_i\})$$

Quindi per conoscere tutta la P su A basta conoscere le $P(E_i)=P(x=\{w_i\})$ ed estenderla per additività

$$E=VE_i \implies P(E)= \sum_{i\in I}{P(E_i)}$$

```ad-important
title: Importante

L'insieme dei $P(E_i)$ si definisce Funzione di "massa" di probabilità (PMF)
```

# V.A. Continue

Nel caso di v.a. continue invece si richiede che la funzione di probabilità P sia "assolutamente continua" cioè che esist a un'altra funzione $f_x: \Omega \to R_0^+$ (funzione reale non negativa) tale che

$$P(E) = \int_E f_x(\omega)\; d\omega \quad \forall E\in A$$

```ad-important
title: Importante

$f_x$ densità di probabilità (PDF)
```

Abbiamo già incontrato le densità **empiriche** nelle distribuzioni in classi $h_i=\frac{f_i}{c_i - c_{i-1}} \geq 0$

$$\int_{c_{i-1}}^{c_i}{h_i} \; d\omega=(c_i - c_{i-1}) \cdot h_i = f_i$$

```ad-seealso
title: Altre osservazioni


$f_i$ deve soddisfare $$\int_{\Omega}{f_x({\omega})} \; d\omega = P(\Omega)= 1$$

```

# Funzione Cumulata Di Probabilità

Per conoscere tutta la $P:A \to [0,1]$ basta conoscere le

$$ \begin{matrix}
P(E_i)\leftarrow PMF
\\ o \\
f_x(\omega) \leftarrow PDF
\end{matrix} \iff \begin{matrix}
\text{funzione cumulata di probabilità} \\
F_X(x)=P(X \leq x)
\begin{matrix}
	\nearrow \sum_{\omega_i \in x}{P(E_i)} \\
	\searrow \int_{- \infty}^x {f_x(\omega)} d\omega
\end{matrix}\end{matrix}$$
Proprietà generali delle $F_X(x)$ CDF (<mark style="background: #FFB86CA6;">Cumulative Density Function</mark>)
- Monotone non decrescenti
- Continue a destra
- $\lim\limits_{x \to - \infty}{F_X(x)=0} \quad e \quad \lim\limits_{x \to \infty}{F_X(x)}=1$
Conoscendo la $F_X(x)$ si ottiene
$$P(E_i) = F_X(\omega_i) - F_X(\omega_{i-1}) \quad o \quad \frac{d}{d\omega}F_X(\omega)=f_x(\omega)$$
Nei diversi contesti pratici si usano ==classi== di funzioni di densità o <mark style="background: #FFF3A3A6;">massa</mark> di probabilità.
Le maggiormente usate sono:
- Funzioni date esplicitamente (elenco)
- Funzioni date implicitamente (come funzioni al variare di $\omega \in \Omega$)
	- forma parametrica $X \sim f(x|\theta)$
		- $\sim$ si distribuisce
		- $x \in \Omega$
		- $\theta \in \Theta$ spazio parametrico

## PMF Date Esplicitamente

Per variabili qualitative discrete, dobbiamo avere l'elenco di tutti i valori $P(E_i)$

### Esempio

X= successo di un generico post
$\Omega =$ {"basso", "medio", "alto"} = $P(E_1)=\frac 15 = \omega_1, P(E_2) = \frac 35 = \omega_2, P(E_3) = \frac 15 = 1-(P(E_1) + P(E_2)) = \omega_3$

### Esempio

Generale X con k modalità
$\Omega = \{ m_1, m_2, ..., m_k\}$
La PMF esplicita è l'elenco
$P(E_1)=P_1$
$P(E_2)=P_2$
$\vdots$
$P(E_k) = 1 - \sum_{i=1}^{k-1} P_i$

### Variabili Aleatorie Con Distribuzione Uniforme Discreta

Caso particolare in cui tutte le $P_i$ sono uguali
$$P_i = \frac 1k, \forall i=1,...,k$$

## Distribuzioni Di Probabilità

Indici sintentici:
- valore atteso E
- previsione P
- media M
riguardare 23-11-2022

### Indice Di Variabilità (varianza teorica)

$$V(x) = E((x - E(x))^2)=E(x^2) - [E(x)]^2$$
x: "nuova" variabile aleatoria

### Indici Di Posizione E Valori Soglia

Quantili teorici $x_q : F_x(x_q)=q$ se F continua, altrimenti $min F_x(x) \geq q$

### Proprietà Fondamentali

1. E(aX+b) = aE(x)+b, con $a,b \in R$
2. $E(x_1 + x_2) = E(x_1) + E(x_2)$
3. V(aX+b)=$a^2V(x)$
4. $V(x_1+x_2) = V(x_1) + V(x_2) + 2Cov(x_1,x_2)$
5. $Cov(x_1,x_2)=E((x_1-E(x_1)) (x_2-E(x_2))) = E(x_1x_2)-E(x_1)E(x_2)$

