#include <cstdio>

// 1. Structures initiales
struct Vec2
{
    double x;
    double y;
};

struct Particule
{
    Vec2   position;
    Vec2   vitesse;
    double vie;
};

// 2. Structures A, B, C
struct A { char c; int n; };
struct B { char c; double d; char e; };
struct C { double d; char c; char e; };

// 3. Seconde Particule (vie en premier, puis char etat, puis position et vitesse)
struct ParticuleR1
{
    double vie;
    char etat;
    Vec2 position;
    Vec2 vitesse;
};

// Ordres supplémentaires essayés pour la Particule
struct ParticuleR2
{
    Vec2 position;
    Vec2 vitesse;
    double vie;
    char etat;
};

struct ParticuleR3
{
    Vec2 position;
    double vie;
    char etat;
    Vec2 vitesse;
};

int main()
{
    std::printf("--- Mesures des tailles en octets ---\n");
    std::printf("Vec2 : %zu\n", sizeof(Vec2));
    std::printf("Particule : %zu\n", sizeof(Particule));
    std::printf("A : %zu\n", sizeof(A));
    std::printf("B : %zu\n", sizeof(B));
    std::printf("C : %zu\n", sizeof(C));
    std::printf("ParticuleR1 : %zu\n", sizeof(ParticuleR1));
    std::printf("ParticuleR2 : %zu\n", sizeof(ParticuleR2));
    std::printf("ParticuleR3 : %zu\n", sizeof(ParticuleR3));

    return 0;
}
