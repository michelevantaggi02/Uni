# Distribuzione Binomiale

è una distribuzione di probabilità discreta che descrive il numero di successi in un processo di Bernoulli, ovvero la variabile $S_N = X_1,...,X_N$ che somma n variabili aleatorie indipendenti di uguale distribuzione di Bernoulli.

```ad-example
title: Esempi

Lancio di una moneta, 

```

# Distribuzione Di Bernoulli

La distribuzione di Bernoulli è una distribuzione di probabilità su due soli valori (0 e 1)

# Processo Di Bernoulli

Un processo di Bernoulli è un processo aleatorio discreto, ossia una famiglia numerabile di variabili aleatorie indipendenti aventi la medesima legge di Bernoulli.

# Distribuzione Geometrica

Data una serie di bernoulli, $X_i\sim Bern(p)$

X è il numero di insuccessi prima di ottenere il primo successo

```ad-example

Nella sequenza 0,0,0,0,1

X=4

```

# Binomiale Negativa

Numero di insuccessi prima di avere l' n-esimo successo (per n=1 si ottiene una v.a. geometrica)

$$X\sim NegBinom(n,p)$$

$$PMFP(X=x)=\binom{n+k-1}{k}q^kp^n \to \substack{E(X)=\frac np \\ V(X) = \frac {nq}{p^2}}$$

# Distribuzione Ipergeometrica

Numero di positivi in n estratti senza reimmissione

$$X \sim Hyper(N, K, n)$$

con N = popolazione, K = elementi positivi, n = elementi osservati (estratti)

$$PMFP(X=x) = \frac {\text{casi favorevooli}}{\text{casi possibili}} = \frac{\binom{K}{x} \binom{N-K}{n-x}}{\binom{N}{n}}$$

$E(X) = n \frac kn$

$V(X) = \frac{K(N_K)n(N-n)}{N^2(N-1)}$

# Distribuzione Di Poisson

Numero di osservazioni di eventi rari (incidenti, crash, contagi,...)

$$X\sim Pois(\lambda)$$

$\lambda \in (0, + \infty) = R^+$

$$PMFP(X=x) = \frac {\lambda^x}{x!}e^{-\lambda}\quad \lambda > 0$$

$E(X) = \lambda = V(X)$

```ad-example

Numeri di guasti che in un anno si verificano in una centralina telefonica ($\lambda = 3$).

Qual è la probabilità che si verifichino in un anno 4 guasti?

$$P(X = 4) = \frac{\lambda^X}{X!} e^{-\lambda} = \frac{3^4}{4!}e^{-3}=\frac{81 \cdot 0,0497}{24} = 0,1677375$$

```

# Distribuzioni Normali

Principali modelli per v.a. continue $\Omega$ ha potenza del, cioè i singoli valori $\omega \in \Omega$ hanno tutti probabilità nulla.

Si descrivono attraverso le densità di probabilità

# Distribuzione Uniforme (continue)

Si usa quando si conoscono solo i limiti di X

$$X \sim Unif(a,b)$$

$$f_X(x) = \begin{cases}
\frac 1{b-a} & x\in[a,b]\\
0
\end{cases}$$
$$F_X(x) = \begin{cases}
0 & x<a\\
\frac{x-a}{b-a} & a \leq x \leq b\\
1 & x>b
\end{cases}$$

``````ad-example

a = -1

b = 1

```functionplot
---
title:
xLabel:
yLabel:
bounds: [-2,2,-1,2]
disableZoom: true
grid: true
---
f(x) = x< -1 ? 0 : x >1 ? 1 : (x+1)/2

```
``````



$E(X) = \frac {a+b}2$

$V(X) = \frac {(b-a)^2}{12}$

# V.A. Con Distribuzione Esponenziale

Per descrivere la "durata" di un fenomeno o il tempo di attesa per osservare fenomeni rari
$$

f_X(x) = \begin{cases}

\lambda e^{-\lambda x} & x > 0\\

0

\end{cases}

$$
$E(X) = \frac 1\lambda$

$V(X) = \frac 1{\lambda^2}$

$$F_X(x) = \begin{cases}
0 & x \leq 0 \\
1 - e^{-\lambda x} & x > 0
\end{cases}$$


``````ad-example

Con $\lambda = 3$

f(x):
```functionplot
---
title:
xLabel:
yLabel:
bounds: [-1,3,0,4]
disableZoom: true
grid: false
---
f(x) = x > 0 ? 3*E^(-3*x) : 0
```

F(X):

```functionplot
---
title:
xLabel:
yLabel:
bounds: [-1,3,0,2]
disableZoom: true
grid: false
---
f(x) = x > 0 ? 1-E^(-3*x) : 0
g(x) = 1
```

``````

# Distribuzione Normale (gaussiane)

Usata per misurazioni fisiche e sociali (altezza, peso, temperatura, reddito, rendimento, età, ...)

$$f_X(x)=\frac 1{\sqrt{2\pi\sigma^2}} e^{-\frac{(x-\mu)^2}{2\sigma^2}}$$
$E(X) = \mu$

$V(X) = \sigma^2$

``````ad-example

$\sigma$ grande = alta variabilità e bassa concentrazione
$\sigma = 1, \mu = 2$
```functionplot
---
title:
xLabel:
yLabel:
bounds: [-1,5,-.1,.5]
disableZoom: true
grid: false
---
f(x) = (1/((2 * PI)*1))*E^(- ((x-2)^2)/2)

```

$\sigma$ piccolo = bassa variabilità alta concentrazione

$\sigma = 0.1, \mu = 2$
```functionplot
---
title:
xLabel:
yLabel:
bounds: [-1,5,-.1,2]
disableZoom: true
grid: false
---
f(x) = (1/((2 * PI)*0.1))*E^(- ((x-2)^2)/0.2)

```

``````

![[curva gauss.png]]

Si usa una distribuzione normale "di riferimento" se la variabile aleatoria X:

$$X \sim N(\mu, \sigma) \implies Z = \frac {X-\mu}\sigma=\frac 1\sigma X - \frac \mu\sigma \sim N(0,1)$$

$$E(Z)=E(\frac 1\sigma X - \frac \mu\sigma)=\frac 1\sigma E(X) - \frac \mu\sigma=\frac\mu\sigma-\frac\mu\sigma=0$$

$$V(Z) = \frac 1{\sigma^2}V(X)=\frac 1{\sigma^2}\sigma^2 = 1$$

Per Z si hanno approssimazioni numeriche della sua CDF $$F_Z(z)=P(Z\leq z)= \int_{-\infty}^{+\infty} {\frac 1{\sqrt{2\pi}} e^{-\frac{t^2}2}}\,dt=\Phi(z)$$ Ci si riconduce sempre a questa CDF

$$P(x_1 \le X \le x_2) = P(X \leq x_2) - P(X < x_1) = F_X(x_2) - F_X(x_1)$$

Ma $P(X\leq x_2) = P(\frac{X-\mu}\sigma \leq \frac{x_2 - \mu}\sigma) = \Phi(\frac{x_2 -\mu}\sigma)$

Quindi $P(x_1\leq X \leq x_2) = \Phi(\frac{x_2-\mu}\sigma) - \Phi(\frac{x_1-\mu}\sigma)$

# Notazione per I Quantili

Notazione per i quantili di $Z\sim N(0,1)$

Si denota con $-z_\alpha$ il quantile di livello $\alpha$ fissato un $\alpha \in [0,1]$

Quindi $P(|Z| \leq x) = P(-x \leq Z \leq X) = \Phi(x) - \Phi(-x)=\Phi(x) - (1-\Phi(x)) = 2\Phi(x)-1$

# Distribuzione Beta

Modelli utili a descrivere la variabilità di una qualche proporzione (percentuale) di elementi che abbiano una qualche proprietà al variare della popolazione (fumatori sani, uomini,....)

$$X \sim Beta(\alpha, \beta),\, \alpha,\beta\in R\quad parametri \, \Theta=R^2$$

Tornando alla densità $f_X(x)=\frac 1{Beta(\alpha,\beta)}x^{\alpha-1}(1-\alpha)^{\beta-1}$

$$Beta(\alpha, \beta) = \frac{T'(\alpha)T'(\beta)}{T'(\alpha + \beta)}$$
$$T'(\alpha) = \int_0^{+\infty}{t^{\alpha-1}e^-t \quad dt}$$


Se $\alpha \geq 1 \,e\,\beta < 1$ o $\alpha <1 \, e \, \beta \geq 1 \implies f_X$ è monotona

Se $\alpha < 1 \, e\, \beta < 1 \implies f_x$ è "unimodale"