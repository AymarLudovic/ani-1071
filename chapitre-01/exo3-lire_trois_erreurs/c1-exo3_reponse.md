# Rapport d'analyse d'erreurs - Exercice 3

---

## Faute 1 : Retirer un point-virgule (`;`)

* **Modification effectuée :** Suppression du point-virgule à la fin de la ligne `std::printf("Bonjour le monde\n")`
* **Message d'erreur exact :**
  `error: expected ';' after expression`
* **Ligne signalée par l'outil :** Ligne 6 (la ligne `return 0;`)
* **Ligne réellement fautive :** Ligne 4 (la ligne où il manque le point-virgule)
* **Étape de la chaîne qui a parlé :** **Le compilateur** (étape de l'analyse syntaxique / parsing).

---

## Faute 2 : Écrire `Printf` au lieu de `printf`

* **Modification effectuée :** Remplacement de `std::printf` par `std::Printf` (avec une majuscule)
* **Message d'erreur exact :**
  `error: no member named 'Printf' in namespace 'std'; did you mean 'printf'?`
* **Ligne signalée par l'outil :** Ligne 4
* **Ligne réellement fautive :** Ligne 4
* **Étape de la chaîne qui a parlé :** **Le compilateur** (étape de la vérification des types et de la résolution des identificateurs).

---

## Faute 3 : Retirer la ligne `#include <cstdio>`

* **Modification effectuée :** Suppression complète de la première ligne `#include <cstdio>`
* **Message d'erreur exact :**
  `error: use of undeclared identifier 'printf'`
* **Ligne signalée par l'outil :** Ligne 3 (au niveau de l'appel à `printf`)
* **Ligne réellement fautive :** Ligne 1 (absence de la directive `#include <cstdio>`)
* **Étape de la chaîne qui a parlé :** **Le compilateur** (lors de la vérification des déclarations).

---

## Synthèse

Toutes ces erreurs sont détectées par le **compilateur** lors de l'analyse du code source. Les messages indiquent souvent la ligne immédiatement après la faute réelle lorsqu'il s'agit d'une ponctuation manquante (comme le point-virgule), car le compilateur continue de lire jusqu'à ce qu'il réalise qu'il manque un élément fondamental.
