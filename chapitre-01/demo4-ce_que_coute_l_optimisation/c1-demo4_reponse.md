# Démonstration 4 — Ce que coûte l'optimisation (-O2)

> **Note :** Réponse rédigée par **ABOM MARIE LUDOVIC**.
> **Compilateur utilisé :** `g++`

## 1. Protocole de test et programmes utilisés

Deux programmes ont été compilés selon deux modes différents : sans optimisation (compilation par défaut) et avec l'option d'optimisation **`-O2`**.

1. **Programme 1 (Simple) :** Un affichage basique `std::cout << "Hello";`.
2. **Programme 2 (Calcul) :** Une boucle effectuant 1 000 000 d'additions successives :
   ```cpp
   #include <iostream>

   int main() {
       volatile long long somme = 0; // volatile pour empêcher le compilateur de supprimer la boucle
       for (int i = 0; i < 1000000; ++i) {
           somme += i;
       }
       std::cout << "Somme : " << somme << std::endl;
       return 0;
   }
