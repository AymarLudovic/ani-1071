# Démonstration 8 — Où passe le temps ? (Compilation vs Exécution)

> **Note :** Réponse rédigée par **ABOM MARIE LUDOVIC**.
> **Compilateur utilisé :** `g++` (GCC)

## 1. Protocole de test et programmes comparés

L'expérimentation mesure et compare le temps nécessaire pour **compiler** puis **exécuter** deux programmes C++ distincts :

1. **Programme Minimal :** Un programme de base sans en-tête supplémentaire :
   ```cpp
   int main() {
       return 0;
   }
