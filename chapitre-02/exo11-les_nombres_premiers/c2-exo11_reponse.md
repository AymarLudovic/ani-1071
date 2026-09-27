# Réponse
J'ai utilisé deux boucles pour tester chaque nombre inférieur à 100.
Pour chaque nombre, le `bool` `premier` indique au départ que le nombre est premier.

La deuxième boucle cherche un diviseur. Si elle en trouve un, `premier` devient `false` et le `break` arrête la boucle.

Un nombre premier est donc affiché seulement s'il n'a trouvé aucun diviseur.

Il suffit de tester les diviseurs jusqu'à la racine carrée car, si un nombre possède un diviseur plus grand que sa racine carrée, il possède forcément un autre diviseur plus petit que sa racine carrée.
