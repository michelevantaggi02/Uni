- Statistica inferenziale
- Statistica parametrica
- Diversi modelli (famiglie di distribuzioni di probabilità) a seconda della natura del "fenomeno"
- Capire quale valore dare al parametro $\theta$ sulla base di un campione osservato

# Esempio

$$X\sim Bernoulli(p)$$

osserviamo 1,0,0,1,1

# Stimatori

Sono delle variabili aleatorie che variano a seconda dei valori assunti dal campione ($X_1,...,X_n$) casuale osservato.

Per $\theta$ si userà il valore $\hat\theta = S(X_1,...,X_n)$


# Metodo Dei Momenti

Si fanno coincidere i momenti teorici (valore atteso, varianza...) di X con quelli empirici (media aritmetica, varianza campionaria,..) basati su $x_1,x_2,...,x_n$

## In Particolare

 - Se $\theta$ è unidimensionale il valore atteso $\hat\theta$ è $E(X) = \bar x$ la media aritmetica
 - Se $\theta$ è **bidimensionale** ($\theta_1, \theta_2$)il valore atteso $\hat\theta$ è la soluzione del sistema $$\begin{cases}E(X) = \bar x \\ V(X) = s^2 = \sum_{i=1}^n \frac {(x_i - \bar x)^2}{n-1}\end{cases}$$ con E(X) e V(X) che dipendono funzionalmente da $\theta_1$ e $\theta_2$ 

# Metodi Di Massima Verosimiglianza

Si sceglie il parametro che massimizza la "probabilità" di aver osservato il campione empirico.

Si definisce **Funzione di verosimiglianza**

$$L(\theta|x_1,...,x_n) = \prod_{i=1}^n{f(x_i|\theta)}$$


# Nozione Di Correttezza

```ad-summary
title: Definizione

Uno  stimatore $S(x_1,..,x_n)$ per $\theta$ si definisce "corretto" se $E(S) = \theta$ valore atteso di S determinato dalla sua distribuzione

```

Uno degli stimatori più comuni è la media aritmetica.