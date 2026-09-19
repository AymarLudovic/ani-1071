# Démonstration 6 — Un programme qui échoue exprès (Banc de test)

> **Note :** Réponse rédigée par **ABOM MARIE LUDOVIC**.
> **Compilateur utilisé :** `g++`

## 1. Code du programme C++

Le programme lit un entier depuis l'entrée standard (`std::cin`) et retourne `0` (succès) si le nombre est pair, ou `1` (échec) si le nombre est impair.

```cpp
#include <iostream>

int main() {
    int nombre;
    std::cin >> nombre;
    
    if (nombre % 2 == 0) {
        return 0; // Succès : le nombre est pair
    } else {
        return 1; // Échec : le nombre est impair
    }
}
