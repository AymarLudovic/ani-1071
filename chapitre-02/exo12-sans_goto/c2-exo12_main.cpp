#include <cstdio>

int main() {
    int n = 1;

    while (n <= 20) {
        if (n % 3 != 0) {
            std::printf("%d ", n);
        }

        n++;
    }

    std::printf("\n");

    return 0;
}
