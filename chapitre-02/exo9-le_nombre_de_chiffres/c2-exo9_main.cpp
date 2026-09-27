#include <cstdio>

int main() {
    int nombre;
    int chiffres = 0;

    std::printf("Entrez un entier positif : ");
    std::scanf("%d", &nombre);

    if (nombre == 0) {
        chiffres = 1;
    } else {
        while (nombre > 0) {
            nombre = nombre / 10;
            chiffres++;
        }
    }

    std::printf("Nombre de chiffres : %d\n", chiffres);

    return 0;
}
