#include <cstdio>
#include <stdexcept>
#include <cstdlib>

int pgcd(int a, int b)
{
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0)
    {
        int reste = a % b;
        a = b;
        b = reste;
    }
    return (a == 0) ? 1 : a;
}

class Fraction
{
private:
    int numerateur;
    int denominateur;

public:
    Fraction(int n, int d)
    {
        if (d == 0) throw std::invalid_argument("denominateur nul interdit");

        if (d < 0)
        {
            n = -n;
            d = -d;
        }

        int diviseur = pgcd(n, d);
        numerateur = n / diviseur;
        denominateur = d / diviseur;
    }

    Fraction operator+(const Fraction& b) const
    {
        return Fraction(numerateur * b.denominateur + b.numerateur * denominateur,
                        denominateur * b.denominateur);
    }

    Fraction operator-(const Fraction& b) const
    {
        return Fraction(numerateur * b.denominateur - b.numerateur * denominateur,
                        denominateur * b.denominateur);
    }

    Fraction operator*(const Fraction& b) const
    {
        return Fraction(numerateur * b.numerateur, denominateur * b.denominateur);
    }

    Fraction operator/(const Fraction& b) const
    {
        if (b.numerateur == 0) throw std::invalid_argument("division par une fraction nulle");
        return Fraction(numerateur * b.denominateur, denominateur * b.numerateur);
    }

    bool operator==(const Fraction& b) const
    {
        return numerateur == b.numerateur && denominateur == b.denominateur;
    }

    void afficher() const
    {
        std::printf("%d/%d", numerateur, denominateur);
    }
};

int main()
{
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction somme = a + b;
    std::printf("1/2 + 1/3 = "); somme.afficher(); std::printf("\n");

    Fraction difference = a - b;
    std::printf("1/2 - 1/3 = "); difference.afficher(); std::printf("\n");

    Fraction produit = Fraction(2, 3) * Fraction(9, 4);
    std::printf("2/3 * 9/4 = "); produit.afficher(); std::printf("\n");

    Fraction quotient = Fraction(3, 4) / Fraction(2, 5);
    std::printf("3/4 / 2/5 = "); quotient.afficher(); std::printf("\n");

    Fraction signe(2, -6);
    std::printf("2/-6 = "); signe.afficher(); std::printf("\n");

    Fraction egale1(1, 2);
    Fraction egale2(2, 4);
    Fraction differente(3, 4);
    std::printf("1/2 == 2/4 : %s\n", egale1 == egale2 ? "true" : "false");
    std::printf("1/2 == 3/4 : %s\n", egale1 == differente ? "true" : "false");

    try
    {
        Fraction impossible(1, 0); // essai demande : le constructeur refuse
        impossible.afficher();
    }
    catch (const std::invalid_argument& e)
    {
        std::printf("Fraction(1, 0) : exception : %s\n", e.what());
    }

    try
    {
        Fraction impossible = Fraction(1, 2) / Fraction(0, 1);
        impossible.afficher();
    }
    catch (const std::invalid_argument& e)
    {
        std::printf("Division par 0/1 : exception : %s\n", e.what());
    }

    return 0;
}
