#include <cstdio>

int main() {
    int a = 3;
    int b = a++ + 1;
    int c = ++a * 2;
    int d = a-- - --a;

    std::printf("a = %d\n", a);
    std::printf("b = %d\n", b);
    std::printf("c = %d\n", c);
    std::printf("d = %d\n", d);

    return 0;
}
