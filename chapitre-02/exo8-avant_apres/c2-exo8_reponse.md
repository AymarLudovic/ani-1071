# Réponse

Au début, `a` vaut `3`.

Après :

`int b = a++ + 1;`

`a++` donne d'abord `3`, puis augmente `a` à `4`. Donc `b` vaut `4`.

Après :

`int c = ++a * 2;`

`++a` augmente d'abord `a` à `5`. Donc `c` vaut `10`.

La dernière ligne :

`int d = a-- - --a;`

est volontairement mauvaise. Elle modifie `a` plusieurs fois dans la même expression. Ce genre de code est à éviter car le résultat n'est pas fiable.

J'ai donc retenu la différence suivante :

* `a++` : utilise la valeur puis augmente.
* `++a` : augmente puis utilise la valeur.
* `a--` : utilise la valeur puis diminue.
* `--a` : diminue puis utilise la valeur.
