#include <cstdio>

int main() {
    int a = 1071;
    int b = 462;
    int tours = 0;

    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }

        tours++;
    }

    std::printf("=== PGCD par soustractions ===\n");
    std::printf("PGCD(1071, 462) = %d\n", a);
    std::printf("Nombre de tours : %d\n", tours);

    a = 1000000;
    b = 1;
    tours = 0;

    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }

        tours++;
    }

    std::printf("PGCD(1000000, 1) = %d\n", a);
    std::printf("Nombre de tours : %d\n", tours);

    a = 1071;
    b = 462;
    tours = 0;

    while (b != 0) {
        int reste = a % b;
        a = b;
        b = reste;

        tours++;
    }

  
    std::printf("\n=== PGCD avec %% (Euclide) ===\n");
    std::printf("PGCD(1071, 462) = %d\n", a);
    std::printf("Nombre de tours : %d\n", tours);

    a = 1000000;
    b = 1;
    tours = 0;

    while (b != 0) {
        int reste = a % b;
        a = b;
        b = reste;

        tours++;
    }

    std::printf("PGCD(1000000, 1) = %d\n", a);
    std::printf("Nombre de tours : %d\n", tours);

    return 0;
}
