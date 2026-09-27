#include <cstdio>

int main() {
    for (int nombre = 2; nombre < 100; nombre++) {
        bool premier = true;

        for (int diviseur = 2; diviseur < nombre; diviseur++) {
            if (nombre % diviseur == 0) {
                premier = false;
                break;
            }
        }

        if (premier) {
            std::printf("%d ", nombre);
        }
    }

    std::printf("\n");

    return 0;
}
