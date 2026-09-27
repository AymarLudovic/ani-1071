# Réponse

J'ai créé un menu avec quatre choix : nouvelle partie, charger, options et quitter.

J'ai utilisé un `switch` pour afficher la réponse correspondant au chiffre choisi, avec un `default` si le chiffre n'est pas compris entre 1 et 4.

Ensuite, j'ai retiré un seul `break`.

Quand on choisit le cas où le `break` a été retiré, le programme continue directement dans le cas suivant au lieu de s'arrêter. C'est ce qu'on appelle un **fall-through**.

Les autres choix continuent de normalement fonctionner
