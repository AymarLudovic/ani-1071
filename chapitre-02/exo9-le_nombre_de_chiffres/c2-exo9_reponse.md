# Réponse
J'ai utilisé une boucle qui divise le nombre par 10 à chaque tour et compte le nombre de divisions.

Par exemple, pour `1000`, il faut 4 divisions pour arriver à 0, donc le nombre possède 4 chiffres.

J'ai testé avec `7`, `42`, `1000` et `2147483647`. Les résultats sont respectivement `1`, `2`, `4` et `10` chiffres.

Pour `0`, le programme donne `1`, car 0 possède un chiffre
