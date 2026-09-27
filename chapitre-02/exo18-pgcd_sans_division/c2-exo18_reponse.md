# Réponse

J'ai réalisé deux versions du calcul du PGCD.

La première version utilise uniquement des soustractions. À chaque tour, on soustrait le plus petit nombre du plus grand jusqu'à ce que les deux nombres soient égaux.

Pour `(1071, 462)`, le PGCD est `21` et il faut **11 tours**.

Pour `(1000000, 1)`, le PGCD est `1` et il faut **999999 tours**.

La deuxième version utilise `%`, avec l'algorithme d'Euclide. À chaque tour, on calcule le reste de la division, puis on remplace les nombres par le diviseur et le reste. On continue jusqu'à obtenir un reste égal à zéro.

Pour `(1071, 462)`, le PGCD est `21` et il faut seulement **3 tours**.

Pour `(1000000, 1)`, le PGCD est `1` et il faut seulement **1 tour**.

On voit donc que la méthode avec `%` demande beaucoup moins de tours que la méthode par soustractions. La différence devient particulièrement importante avec des nombres comme `1000000` et `1`, où la méthode par soustractions nécessite `999999` tours contre seulement `1` tour avec l'algorithme d'Euclide.
