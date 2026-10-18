
#include <iostream>
using namespace std;

// Retrouver la colonne x et la ligne y d'une case
void deplier(int i, int largeur, int& x, int& y)
{
    x = i % largeur;
    y = i / largeur;
}

// Trouver la plus petite et la plus grande valeur
void minMax(const int t[], int n, int& min, int& max)
{
    min = t[0];
    max = t[0];

    for (int i = 1; i < n; ++i)
    {
        if (t[i] < min)
        {
            min = t[i];
        }

        if (t[i] > max)
        {
            max = t[i];
        }
    }
}

// Diviser sans modifier les résultats 
bool diviser(int a, int b, int& quotient, int& reste)
{
    if (b == 0)
    {
        return false;
    }

    quotient = a / b;
    reste = a % b;

    return true;
}

int main()
{
    int x;
    int y;
    int largeur = 40;

    cout << "Deplier :\n";

    deplier(0, largeur, x, y);
    cout << "i = 0 : x = " << x << ", y = " << y << '\n';

    deplier(39, largeur, x, y);
    cout << "i = 39 : x = " << x << ", y = " << y << '\n';

    deplier(40, largeur, x, y);
    cout << "i = 40 : x = " << x << ", y = " << y << '\n';

    deplier(79, largeur, x, y);
    cout << "i = 79 : x = " << x << ", y = " << y << '\n';

    int nombres[] = {12, 7, 19, 3, 15};
    int min;
    int max;

    minMax(nombres, 5, min, max);

    cout << "\nMinMax : min = " << min
         << ", max = " << max << '\n';

    int quotient = 0;
    int reste = 0;

    if (diviser(17, 5, quotient, reste))
    {
        cout << "17 / 5 : quotient = " << quotient
             << ", reste = " << reste << '\n';
    }

    if (diviser(20, 4, quotient, reste))
    {
        cout << "20 / 4 : quotient = " << quotient
             << ", reste = " << reste << '\n';
    }

    quotient = 123;
    reste = 456;

    cout << "Avant division par zero : quotient = "
         << quotient << ", reste = " << reste << '\n';

    bool succes = diviser(10, 0, quotient, reste);

    cout << "Succes : " << boolalpha << succes << '\n';
    cout << "Apres division par zero : quotient = "
         << quotient << ", reste = " << reste << '\n';

    return 0;
}
