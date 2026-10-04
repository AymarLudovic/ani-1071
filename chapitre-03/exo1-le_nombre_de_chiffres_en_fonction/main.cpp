#include <iostream>

using namespace std;

int nombreDeChiffres(int n)
{
    if (n == 0)
    {
        return 1;
    }

    long long valeur = n;

    if (valeur < 0)
    {
        valeur = -valeur;
    }

    int compteur = 0;

    while (valeur > 0)
    {
        valeur = valeur / 10;
        compteur++;
    }

    return compteur;
}

int main()
{
    int n;
    bool aLuUnNombre = false;

    while (cin >> n)
    {
        cout << nombreDeChiffres(n) << '\n';
        aLuUnNombre = true;
    }

    if (!aLuUnNombre)
    {
        cout << "AUCUN\n";
    }

    return 0;
}
