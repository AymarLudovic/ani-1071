# Réponse

J'ai simulé une horloge avec trois variables : `h` pour les heures, `m` pour les minutes et `s` pour les secondes.

La boucle avance l'heure d'une seconde à chaque tour.

J'utilise l'opérateur `%` pour faire revenir automatiquement les compteurs à `0` lorsqu'ils atteignent leur limite : `60` pour les secondes et les minutes, et `24` pour les heures.

Le format `%02d` permet d'afficher les heures, les minutes et les secondes sur deux chiffres.

Mon programme affiche bien :

```text
23:59:58
23:59:59
00:00:00
```

Le passage de minuit se fait sans utiliser de `if`.
