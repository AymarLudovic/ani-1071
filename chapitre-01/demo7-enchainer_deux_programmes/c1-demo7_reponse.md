# Démonstration 7 — Enchaîner deux programmes selon le code de sortie

> **Note :** Réponse rédigée par **ABOM MARIE LUDOVIC**.
> **Compilateur utilisé :** `g++`

## 1. Code du programme source C++ (`c1-demo6_main.cpp`)

Le programme lit un entier et retourne `0` si le nombre est pair, ou `1` si le nombre est impair :

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
