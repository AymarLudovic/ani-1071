# Réponse

J'ai refait la simulation de la chute en utilisant uniquement des `int`.

Les positions sont exprimées en millimètres, les vitesses en millimètres par seconde et le temps en millisecondes.

Avec cette version, j'obtiens un temps d'impact de **4500 ms**, soit **4,50 secondes**.

La version précédente avec `double` donnait également environ **4,5 secondes**. Le résultat est donc très proche.

L'utilisation des entiers permet d'éviter les calculs en nombres décimaux et peut être plus rapide sur des machines moins puissantes.

Pendant plusieurs générations de consoles, les développeurs utilisaient cette technique car les processeurs avaient moins de puissance et de mémoire.

Les calculs entiers demandaient moins de ressources et permettaient de consacrer davantage de puissance aux graphismes et aux autres éléments du jeu.

En revanche, les calculs sont moins précis et les développeurs doivent gérer eux-mêmes les unités et les arrondis.

Il faut donc trouver un compromis entre la précision, la vitesse et les ressources disponibles.
