#include <cstdio>

int main() {
  
    int n;
    int etapes = 0;

    std::printf("Entrez un entier superieur a 1 : ");
    std::scanf("%d", &n);

    while (n != 1) {
        std::printf("%d ", n);

        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        etapes++;
    }

  
    std::printf("1\n");
    std::printf("Nombre d'etapes : %d\n", etapes);

    return 0;
}
