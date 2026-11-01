#include <cstdio>

struct Couleur
{
    unsigned char r, g, b, a;

    Couleur(unsigned char rouge, unsigned char vert, unsigned char bleu, unsigned char alpha)
        : r(rouge), g(vert), b(bleu), a(alpha) {}

    // Constructeur inverse : 0xRRGGBBAA vers les quatre composantes.
    Couleur(unsigned int rgba)
        : r(static_cast<unsigned char>((rgba >> 24) & 0xFFu)),
          g(static_cast<unsigned char>((rgba >> 16) & 0xFFu)),
          b(static_cast<unsigned char>((rgba >> 8) & 0xFFu)),
          a(static_cast<unsigned char>(rgba & 0xFFu)) {}

    unsigned int empaqueter() const
    {
        return (static_cast<unsigned int>(r) << 24) |
               (static_cast<unsigned int>(g) << 16) |
               (static_cast<unsigned int>(b) << 8) |
               static_cast<unsigned int>(a);
    }
};

static unsigned char borner(double valeur)
{
    if (valeur < 0.0) valeur = 0.0;
    if (valeur > 255.0) valeur = 255.0;
    return static_cast<unsigned char>(valeur + 0.5);
}

Couleur operator*(Couleur c, double k)
{
    // Le facteur agit sur RGB ; l'opacite alpha reste inchangee.
    return Couleur(borner(c.r * k), borner(c.g * k), borner(c.b * k), c.a);
}

Couleur operator+(Couleur c, Couleur d)
{
    return Couleur(borner(c.r + d.r), borner(c.g + d.g),
                   borner(c.b + d.b), borner(c.a + d.a));
}

Couleur lerp(Couleur c, Couleur d, double t)
{
    return Couleur(
        borner(c.r + (static_cast<double>(d.r) - c.r) * t),
        borner(c.g + (static_cast<double>(d.g) - c.g) * t),
        borner(c.b + (static_cast<double>(d.b) - c.b) * t),
        borner(c.a + (static_cast<double>(d.a) - c.a) * t));
}

void afficher(const char* nom, Couleur c)
{
    std::printf("%s = (%u, %u, %u, %u), paquet = 0x%08X\n",
                nom, static_cast<unsigned>(c.r), static_cast<unsigned>(c.g),
                static_cast<unsigned>(c.b), static_cast<unsigned>(c.a), c.empaqueter());
}

int main()
{
    unsigned char brut = static_cast<unsigned char>(200 + 200);
    std::printf("Sans saturation : 200 + 200 range dans unsigned char donne %u\n", static_cast<unsigned>(brut));

    Couleur c = {200, 100, 50, 255};
    Couleur d{100, 200, 250, 10};
    afficher("c", c);
    afficher("c * 2", c * 2.0);
    afficher("c + d", c + d);
    afficher("lerp(c, d, 0.5)", lerp(c, d, 0.5));
    std::printf("Alpha de c * 2 reste %u\n", static_cast<unsigned>((c * 2.0).a));

    unsigned int paquet1 = c.empaqueter();
    Couleur retour1(paquet1);
    std::printf("Aller-retour 1 : 0x%08X -> 0x%08X\n", paquet1, retour1.empaqueter());

    Couleur autre{12, 34, 56, 78};
    unsigned int paquet2 = autre.empaqueter();
    Couleur retour2(paquet2);
    std::printf("Aller-retour 2 : 0x%08X -> 0x%08X\n", paquet2, retour2.empaqueter());

    // Couleur c = {200, 100, 50, 255}; // compile grace au constructeur a quatre composantes ci-dessus.
    return 0;
}
