# Réponses à l'exercice 9 — Le massacre du point-virgule

> **Note :** Le compilateur utilisé pour cet exercice est **g++**.

## 1. Code d'origine et protocole d'expérimentation

Le programme de départ contient 5 instructions se terminant par un point-virgule dans la fonction `main()` :

```cpp
#include <iostream>

int main() {
    int x = 10;
    int y = 20;
    int somme = x + y;
    std::cout << "La somme est : " << somme << std::endl;
    return 0;
}
