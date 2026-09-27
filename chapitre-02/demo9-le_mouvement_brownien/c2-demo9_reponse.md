# Réponse

Le point commence au centre d'une grille de `21 × 21`.

À chaque tour, une direction est choisie au hasard avec `rand() % 4`, puis un `switch` permet de déplacer le point d'une case.

Après `200` tours, j'obtiens une position finale représentée par `#`. Les cases qui ont été visitées sont représentées par `.`.

Mon programme donne :

```text
Cases distinctes visitees : 87
```

J'ai donc visité **87 cases distinctes**.

Comme aucun tableau n'est utilisé, le programme rejoue le même parcours aléatoire avec la même graine et vérifie, pour chaque case de la grille, si le parcours est passé dessus. Cela permet de compter les cases visitées sans avoir à les mémoriser dans un tableau.
