
#include <cstdio>

int main()
{
    int a = 5, b = 9;

    int* p = &a;
    int* q = &b;

    printf("%d %d\n", *p, *q);

    *p = *q;

    printf("%d %d\n", a, b);

    p = q;

    *p = 1;

    printf("%d %d\n", a, b);

    return 0;
}
