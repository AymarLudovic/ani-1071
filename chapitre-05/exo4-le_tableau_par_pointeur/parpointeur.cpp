
#include <iostream>
#include <cstring>
using namespace std;


int somme(const int* t, int n)
{
    int resultat = 0;

    while (n > 0)
    {
        resultat += *t;
        ++t;
        --n;
    }

    return resultat;
}

// Trouver la plus grande valeur
int maximum(const int* t, int n)
{
    int resultat = *t;

    ++t;
    --n;

    while (n > 0)
    {
        if (*t > resultat)
        {
            resultat = *t;
        }

        ++t;
        --n;
    }

    return resultat;
}


void inverser(int* t, int n)
{
    int* gauche = t;
    int* droite = t + n;

    while (gauche < droite)
    {
        --droite;

        if (gauche >= droite)
        {
            break;
        }

        int temporaire = *gauche;
        *gauche = *droite;
        *droite = temporaire;

        ++gauche;
    }
}

// Compter les octets avant le caractere de fin
int longueur(const char* s)
{
    const char* p = s;

    while (*p != '\0')
    {
        ++p;
    }

    return static_cast<int>(p - s);
}

int main()
{
    int nombres[] = {12, 7, 19, 3, 15};

    cout << "Somme : " << somme(nombres, 5) << '\n';
    cout << "Maximum : " << maximum(nombres, 5) << '\n';

    int a[] = {1, 2, 3, 4, 5};

    cout << "Avant inversion : ";
    for (int i = 0; i < 5; ++i)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    inverser(a, 5);

    cout << "Apres inversion : ";
    for (int i = 0; i < 5; ++i)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    const char* bonjour = "bonjour";
    const char* yaounde = "Yaoundé";

    cout << "Longueur de bonjour : "
         << longueur(bonjour) << '\n';
    cout << "strlen de bonjour : "
         << strlen(bonjour) << '\n';

    cout << "Longueur de Yaoundé : "
         << longueur(yaounde) << '\n';
    cout << "strlen de Yaoundé : "
         << strlen(yaounde) << '\n';

    return 0;
}
