# Réponse
La couleur `0x2A7FCCFF` contient quatre valeurs de 8 bits :

* Rouge : `42`
* Vert : `127`
* Bleu : `204`
* Alpha : `255`

J'ai utilisé `>>` et `&` pour récupérer chaque composante.

Ensuite, j'ai utilisé `<<` et `|` pour reconstruire la couleur. La couleur obtenue est bien la même que la couleur de départ.

Enfin, j'ai divisé le rouge, le vert et le bleu par 2 pour assombrir la couleur. Je n'ai pas modifié l'alpha.

La couleur assombrie est `153F66FF`.
