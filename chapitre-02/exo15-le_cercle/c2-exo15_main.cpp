#include <cstdio>

int main() {
    int r;

    std::printf("Entrez le rayon : ");
    std::scanf("%d", &r);

    for (int y = -r; y <= r; y++) {
        for (int x = -r; x <= r; x++) {
            if (x * x + y * y <= r * r) {
                std::printf("##");
            } else {
                std::printf("  ");
            }
        }

        std::printf("\n");
    }

    return 0;
}
