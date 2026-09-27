# Réponse

Avec une hauteur de départ de `100 mètres`, le temps d'impact change selon la valeur de `dt`.

Avec `dt = 0.1`, l'impact arrive vers `4.5 s`. Avec `dt = 0.01`, il arrive vers `4.52 s`, et avec `dt = 1.0`, il arrive vers `5.0 s`.

Le résultat change parce que la simulation ne calcule pas la chute à chaque instant réel, mais avance par étapes de temps.

Plus `dt` est grand, plus chaque étape est importante et moins la simulation est précise.

Dans un jeu à 30 ou 144 images par seconde, un petit pas de temps permet généralement d'obtenir une simulation plus précise et plus stabl
