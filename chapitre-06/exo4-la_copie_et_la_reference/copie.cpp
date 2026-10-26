#include <cstdio>
#include <cmath>

struct Vec2
{
    double x;
    double y;
};

// 1. Passage par valeur (copie)
void bougerCopie(Vec2 p)
{
    p.x += 1.0;
}

// 2. Passage par référence
void bougerRef(Vec2& p)
{
    p.x += 1.0;
}

// 3. Passage par référence constante
double longueurRef(const Vec2& p)
{
    // Ligne refusée gardée en commentaire (comme demandé) :
    // p.x = 0.0;
    
    return std::sqrt(p.x * p.x + p.y * p.y);
}

int main()
{
    Vec2 v = {3.0, 4.0};

    std::printf("Depart : x = %.1f, y = %.1f\n", v.x, v.y);

    bougerCopie(v);
    std::printf("Apres bougerCopie : x = %.1f, y = %.1f\n", v.x, v.y);

    bougerRef(v);
    std::printf("Apres bougerRef : x = %.1f, y = %.1f\n", v.x, v.y);

    double len = longueurRef(v);
    std::printf("Apres longueurRef (longueur = %.1f) : x = %.1f, y = %.1f\n", len, v.x, v.y);

    return 0;
}
