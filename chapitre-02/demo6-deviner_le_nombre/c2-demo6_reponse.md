# Réponse

J'ai réalisé un programme qui choisit un nombre secret entre `1` et `100`, puis demande au joueur de proposer des nombres.

Après chaque proposition, le programme indique « Plus ! » si le nombre secret est plus grand, ou « Moins ! » s'il est plus petit. Le nombre d'essais est compté jusqu'à ce que le joueur trouve le nombre.

Lors de mon test, j'ai choisi le nombre secret `2` et j'ai proposé `2` directement. Le programme a donc trouvé le nombre en **1 essai**.

Le nombre minimal d'essais qui garantit de trouver le nombre est **7 essais** si l'on choisit toujours le nombre au milieu des possibilités restantes.

À chaque essai, on peut éliminer environ la moitié des possibilités. `2^6 = 64`, ce qui ne suffit pas pour 100 nombres, alors que `2^7 = 128` suffit.

C'est le principe de la recherche binaire.
