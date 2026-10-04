#include <iostream>

using namespace std;

int chiffresRecursif(int n)
{
    long long valeur = n;

    if (valeur < 0)
    {
        valeur = -valeur;
    }

    if (valeur < 10)
    {
        return 1;
    }

    return 1 + chiffresRecursif(static_cast<int>(valeur / 10));
}

int sommeChiffresRecursif(int n)
{
    long long valeur = n;

    if (valeur < 0)
    {
        valeur = -valeur;
    }

    if (valeur < 10)
    {
        return static_cast<int>(valeur);
    }

    return static_cast<int>(valeur % 10)
        + sommeChiffresRecursif(static_cast<int>(valeur / 10));
}

int main()
{
    int n;
    bool aLuUnNombre = false;

    while (cin >> n)
    {
        cout << chiffresRecursif(n) << '\n';
        cout << sommeChiffresRecursif(n) << '\n';

        aLuUnNombre = true;
    }

    if (!aLuUnNombre)
    {
        cout << "AUCUN\n";
    }

    return 0;
}
