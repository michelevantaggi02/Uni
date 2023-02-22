Abbiamo visto le distribuzioni di probabilità esplicite (o non parametriche) ([[Statistica inferenziale#PMF Date Esplicitamente|PMF]])

$\newcommand{\indep}{\perp \!\!\! \perp}$

$$f_x(x|\theta)$$

$$x \in \Omega=\{0,1\}$$

$$\theta\in\Theta$$

$\Theta$ spazio parametrico

Con distribuzione Bernoulliana

$$x \sim> Bernou[\vartheta], \vartheta \in [0,1]$$

$$f_x(x|\theta)=\begin{cases} \theta & x=1 \\ \theta-1 & x=0 \end{cases}$$

$$\begin{cases}
P(x=0)=1-\vartheta=1 \\
P(x=1) = \vartheta
\end{cases}
\implies
\begin{cases}
E(x)=0\cdot q + 1 \cdot \vartheta = \vartheta \\
E(x^2)=0^2\cdot q + 1^2 \cdot \vartheta = \vartheta \\
V(x) = E(x^2) - [E(x)]^2 = \vartheta -\vartheta^2 = \vartheta(1-\vartheta)=\vartheta q
\end{cases}$$

# Altri Modelli

Si costruiscono basandosi su successioni di v.a. $x_1,x_2,...$
con $x_i \sim Bern(\vartheta)$ non dipendente da i, quindi "identicamente distribuite", e $x_i \indep x_j$

## Indipendenza Stocastica

$x_1\indep x_2$ se il verificarsi di una variabile aleatoria non influenza la distribuzione di probabilità dell'altra .

Presi due eventi $E_1$ "indotto" da $x_1$ e $E_2$ indotto da $x_2$
$$P(E_1 \wedge E_2)=P(E_1)P(E_2)$$
Considerando condizionate
$$P(E_1|E_2)=P(E_1)$$
| dato, prendiamo $E_1$ nel contesto in cui $E_2$ è mezzo (scenario)

```ad-note

Le proprietà condizionate sono un "ponte" tra le probabilità congiunte e le marginali

$$P(E_1 \wedge E_2)=P(E_1|E_2)P(E_2)$$

$$P(E_2\wedge E_1)=P(E_2|E_1)P(E_1)$$

```

## Operazioni Varie Sulla Successione

Tornando a $x_1,x_2,...x$ sono i.i.d (indipendenti e identicamente distribuite) con $x_i \sim Bern(p)$.

Possiamo introdurre:
- $x=x_1+x_2+...+x_n$ numero di successi in n prove (distribuzione binomiale)
	- $x \sim binomiale(n,p)$
	- $(n,p) = \vartheta \in N x [0,1]$


$X_1,X_2,...$ i.i.d. $x_i \sim Bern(p)$
X= numero di "insuccessi" prima di ottenere il "primo" successo

```ad-example
title: Esempio
Se osservo la sequenza $0,0,0,0,1,...$

- 0 vuol dire insuccesso
- 1 vuol dire successo
- x=4

$$x\sim Geom(p), p \in [0,1]$$
$$\Omega=\{0,1,2,3,...\}=N_0$$
$$PMF \, P(X=k)=, k \in \Omega$$


```

```ad-attention
title: Attenzione
Alcuni testi chiamano le v.a. geometriche 

Y="n di prove per ottenere il primo successo"
$$Y=X+1 \implies \Omega=\{1,2,3,...\}$$
$$P(Y=k)=P(X+1=k)=P(X=k-1)=q^{k-1}p$$
$$E(Y)=E(X+1)=E(X)+1=\frac qp+1=\frac{q+p}p=\frac{1-p+p}p= \frac 1p$$
$$V(Y)=V(X+1)=V(X)$$

```

```ad-note
Notiamo che $P(X \geq n), n\in N_0$
$$P(X\geq n)=\sum_{k=n}^{+\infty}{P(X=k)}=\sum_{k=n}^{+\infty}{q^kp}=q^np\sum_{j=0}^{+\infty}{q^j}$$
Serie geometrica di base q con somma $\frac 1{1-q} = \frac 1p = q^np\frac 1p=q^n$

Da cui otteniamo $F_X(x)$ riguardare
```

Inoltre

$$P(X \geq t+s|X\geq t)= \frac{P((X\geq t+s)\wedge(X\geq t)) }{P(X \geq t)}=\frac{P(X\geq t+s)}{P(X\geq t)}=\frac{q^{t+s}}{q^t}=q^s=P(X\geq s)$$
$$t,s \in N$$

Le v.a. geometriche si possono generalizzare con v.a. che misurano il numero di insuccessi prima di avere l'nesimo succcesso con $n\in N$
Riguardare

## Altri modelli di conteggio

### Numero di positivi in n estratti senza reimmissione
$$X\sim Hyper(N,K,n), \Theta=(\theta_1,\theta_2,\theta_3)\in N\cdot\{0,...,N\}\cdot \{1,...,K\}$$
Con N=\#Popolazione, K= \#elementi "positivi", n=\#osservati
$$\Omega=\{0,...,n\}\quad PMFP(X=x)==\frac{}{}$$
Riguardare con calma

### Numero di osservazioni di fenomeni rari

X=v.a.g.n. con distribuzione di Poisson (Incidenti, crash, particelle radioattive,contagi...)
$$X\sim Pois(\lambda \in R^+), \Theta \in (0, +\infty)=R^+$$
$$\Omega\{0,1,1,...\}$$

$$PMFP(X=k)=\frac{\lambda^k}{k!}e^{-\lambda}$$