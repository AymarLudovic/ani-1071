#include <cstdio>

struct P
{
    int a;

    // Ancienne declaration : elle ne fournit PAS de constructeur sans parametre.
    P(int v) : a(v) {}

    // Variante observee dans la deuxieme partie de l'exercice :
    // P() : a(0) {}

    // Version finale demandee : constructeur par defaut genere par le compilateur.
    // Attention : avec P x; le membre entier a n'est pas initialise.
    P() = default;
};

int main()
{
    P x;
    P t[10];

    // Lecture volontairement demandee par l'exercice, mais non fiable :
    // x.a a une valeur indeterminee. Lire cette valeur a un comportement indefini.
    std::printf("x.a = %d\n", x.a);

    // Evite un avertissement pour tableau inutilise sans lire ses membres.
    (void)t;
    return 0;
}
