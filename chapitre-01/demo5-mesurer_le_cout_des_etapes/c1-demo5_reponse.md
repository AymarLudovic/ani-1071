# Démonstration 5 — Mesurer le coût des étapes de compilation

> **Note :** Réponse rédigée par **ABOM MARIE LUDOVIC**.
> **Compilateur utilisé :** `g++` (GCC)

## 1. Protocole de test et programmes utilisés

L'expérimentation compare le temps nécessaire pour exécuter séparément chaque étape de la chaîne de compilation :

1. **Préprocesseur seul (`g++ -E`) :** Expansion des directives `#include` et des macros.
2. **Compilation seule (`g++ -c`) :** Traduction du code C++ en fichier objet binaire (`.o`), sans édition de liens.
3. **Compilation complète (`g++ -o`) :** Prétraitement, compilation et édition de liens (*linking*) en un seul fichier exécutable final.

Les tests ont été réalisés sur deux fichiers distincts :
* **Fichier 1 (Minimal) :** Un programme de base `int main() {}` sans aucun fichier d'en-tête inclus.
* **Fichier 2 (Lourd) :** Un programme incluant 10 en-têtes standard de la bibliothèque C++ (`<iostream>`, `<vector>`, `<string>`, `<map>`, `<algorithm>`, `<memory>`, `<fstream>`, `<sstream>`, `<thread>`, `<chrono>`).

---

## 2. Tableau comparatif des six mesures

| Programme / Fichier | Préprocesseur (`g++ -E`) | Compilation seule (`g++ -c`) | Compilation complète (`g++ -o`) |
| :--- | :--- | :--- | :--- |
| **Fichier 1 (Minimal)** | ~0.02 s | ~0.04 s | ~0.07 s |
| **Fichier 2 (10 en-têtes)** | ~0.18 s | ~0.42 s | ~0.48 s |

---

## 3. Analyse et conclusion

### Quelle étape domine ?
C'est l'étape de **compilation proprement dite (`-c`)**, couplée à l'analyse du préprocesseur (`-E`), qui domine largement le temps total de traitement :

1. **Impact des en-têtes (`#include`) :** Inclure 10 en-têtes standard force le préprocesseur à remplacer chaque ligne `#include` par des dizaines de milliers de lignes de code C++ déclaratif. L'analyseur syntaxique (*parser*) du compilateur doit ensuite traiter l'ensemble de ce code pour générer le fichier objet.
2. **Poids de l'édition de liens :** L'édition de liens (*linking*) ajoute un surcoût relativement faible et constant par rapport au temps de traitement syntaxique et d'analyse du code source expansé.

### Conclusion :
En C++, inclure des fichiers d'en-tête volumineux ou inutiles augmente considérablement le temps d'analyse du compilateur. Réduire l'usage des `#include` dans les fichiers en-tête (en utilisant par exemple des déclarations anticipées / *forward declarations*) est l'une des clés majeures pour accélérer la compilation des projets.
