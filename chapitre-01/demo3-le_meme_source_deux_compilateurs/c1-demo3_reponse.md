# Démonstration 3 — Un même code source avec deux compilateurs

> **Note :** Réponse rédigée par **ABOM MARIE LUDOVIC**.

## 1. Outils et environnement de comparaison

Faute d'avoir `clang++` immédiatement disponible, l'expérimentation a été réalisée en comparant deux outils / versions distinctes de GCC disponibles sur l'environnement MSYS2/MinGW :

* **Compilateur 1 :** `g++` (GCC principal, version 13.x)
* **Compilateur 2 :** `x86_64-w64-mingw32-g++` (ou alternativement `g++ -O2` / autre version de GCC disponible)

Le code source utilisé pour la comparaison est le programme C++ classique d'affichage :

```cpp
#include <iostream>

int main() {
    std::cout << "Test de comparaison de compilateurs" << std::endl;
    return 0;
}
