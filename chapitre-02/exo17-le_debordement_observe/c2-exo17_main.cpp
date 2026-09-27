#include <cstdio>

int main() {
    std::printf("=== int avec x *= 2 ===\n");

    int x = 1;

    for (int tour = 0; tour <= 32; tour++) {
        std::printf("Tour %d : x = %d\n", tour, x);
        x *= 2;
    }

    std::printf("\n=== long long avec x *= 2 ===\n");

    long long y = 1;

    for (int tour = 0; tour <= 64; tour++) {
        std::printf("Tour %d : x = %lld\n", tour, y);
        y *= 2;
    }

    std::printf("\n=== unsigned int avec x *= 2 ===\n");

    unsigned int z = 1;

    for (int tour = 0; tour <= 32; tour++) {
        std::printf("Tour %d : x = %u\n", tour, z);
        z *= 2;
    }

    std::printf("\n=== int avec x <<= 1 ===\n");

    int a = 1;

    for (int tour = 0; tour <= 32; tour++) {
        std::printf("Tour %d : x = %d\n", tour, a);
        a <<= 1;
    }

    std::printf("\n=== long long avec x <<= 1 ===\n");

    long long b = 1;

    for (int tour = 0; tour <= 64; tour++) {
        std::printf("Tour %d : x = %lld\n", tour, b);
        b <<= 1;
    }

    std::printf("\n=== unsigned int avec x <<= 1 ===\n");

    unsigned int c = 1;

    for (int tour = 0; tour <= 32; tour++) {
        std::printf("Tour %d : x = %u\n", tour, c);
        c <<= 1;
    }

    return 0;
}
