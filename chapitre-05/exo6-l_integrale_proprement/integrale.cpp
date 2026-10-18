
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Type : une fonction qui prend un double et rend un double
using Fonction = double (*)(double);

// Fonction qui calcule l'aire sous une courbe
double integrale(Fonction f, double a, double b)
{
    double pas = (b - a) / 1000.0;
    double somme = 0.0;

    for (int i = 0; i < 1000; ++i)
    {
        somme += f(a + i * pas) * pas;
    }

    return somme;
}

// Fonction qui approche la derivee
double derivee(Fonction f, double x)
{
    double h = 1e-6;

    return (f(x + h) - f(x - h)) / (2.0 * h);
}

// Fonction dont on cherche un zero
double zero(Fonction f, double a, double b)
{
    double fa = f(a);

    for (int i = 0; i < 1000 && b - a > 1e-12; ++i)
    {
        double milieu = (a + b) / 2.0;
        double fm = f(milieu);

        if (fm == 0.0)
        {
            return milieu;
        }

        if ((fa < 0.0 && fm > 0.0) ||
            (fa > 0.0 && fm < 0.0))
        {
            b = milieu;
        }
        else
        {
            a = milieu;
            fa = fm;
        }
    }

    return (a + b) / 2.0;
}

// Trois fonctions compatibles avec le type Fonction
double carre(double x)
{
    return x * x;
}

double racineDeux(double x)
{
    return x * x - 2.0;
}

int main()
{
    cout << fixed << setprecision(6);

    double aireSin = integrale(sin, 0.0, 3.14159);
    double aireCarre = integrale(carre, 0.0, 1.0);

    cout << "Integrale de sin : " << aireSin << '\n';
    cout << "Integrale de carre : " << aireCarre << '\n';

    cout << "Derivee de sin en 0 : "
         << derivee(sin, 0.0) << '\n';

    double resultat = zero(racineDeux, 1.0, 2.0);

    cout << "Zero de x*x - 2 : " << resultat << '\n';
    cout << "sqrt(2) : " << sqrt(2.0) << '\n';
    cout << "Ecart : " << abs(resultat - sqrt(2.0)) << '\n';

    return 0;
}
