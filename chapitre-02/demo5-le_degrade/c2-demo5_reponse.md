# Réponse

J'ai utilisé les caractères `" .:-=+*#@"` pour créer un dégradé allant du clair au sombre.

La bande contient 60 colonnes et 4 lignes.

Pour chaque colonne `x`, j'utilise la formule :

```cpp
x * 9 / 60
```

Cette formule transforme la position de la colonne en un indice compris entre `0` et `8`.

L'indice permet de choisir le caractère correspondant dans la chaîne `" .:-=+*#@"`.

Ainsi, les premières colonnes sont claires et les dernières sont de plus en plus sombres.

C'est le même principe qu'un shader : une position est transformée en une valeur qui détermine le résultat affiché.
