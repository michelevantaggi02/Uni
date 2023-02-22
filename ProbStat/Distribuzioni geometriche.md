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

con N = popolazione, K = elementi positivi, N = elementi osservati (estratti)

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
