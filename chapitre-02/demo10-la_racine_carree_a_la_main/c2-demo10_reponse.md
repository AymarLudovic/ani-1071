# Réponse

J'ai calculé la racine carrée sans utiliser `sqrt`, avec la méthode de Héron.

La méthode consiste à commencer avec `x = n`, puis à calculer :

`x = (x + n / x) / 2`

À chaque tour, je compare l'ancienne valeur avec la nouvelle. Lorsque leur différence devient inférieure à `10^-9`, le calcul s'arrête.

Pour `n = 2`, j'obtiens :

```text
Racine carree = 1.414213562373
Nombre de tours = 5
```

Pour `n = 1000`, j'obtiens :

```text
Racine carree = 31.622776601684
Nombre de tours = 10
```

Pour `n = 10^12`, j'obtiens :

```text
Racine carree = 1000000.000000000000
Nombre de tours = 26
```

La méthode de Héron converge progressivement vers la racine carrée. Même pour un nombre très grand comme `10^12`, elle permet d'obtenir rapidement une valeur très précise.
