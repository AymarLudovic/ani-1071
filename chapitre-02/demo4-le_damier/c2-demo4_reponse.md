# Réponse

Pour construire le damier, j'utilise deux boucles pour parcourir les 8 lignes et les 8 colonnes.

Chaque case fait 4 caractères de large et 2 lignes de haut.

Le motif alterne avec la condition :

```cpp
(x + y) % 2 == 0 ? '#' : ' '
```

Le `% 2` permet de savoir si la somme de `x` et `y` est paire ou impaire. Le ternaire affiche `#` lorsque la somme est paire et un espace lorsqu'elle est impaire.

En répétant ce motif sur les 8 × 8 cases, on obtient un damier.
