# Démonstration 9 — Regarder l'assembleur (`-S`)

> **Note :** Réponse rédigée par **ABOM MARIE LUDOVIC**.
> **Compilateur utilisé :** `g++` (GCC)

## 1. Génération du fichier assembleur

À partir d'un programme C++ simple d'affichage :

```cpp
#include <cstdio>

int main() {
    std::printf("Hello, World!\n");
    return 0;
}
