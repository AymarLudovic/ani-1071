#include <iostream>

int calculer();

int main() {
    // Appel de la fonction déclarée mais non définie
    int resultat = calculer();
    std::cout << "Résultat : " << resultat << std::endl;
    return 0;
}
