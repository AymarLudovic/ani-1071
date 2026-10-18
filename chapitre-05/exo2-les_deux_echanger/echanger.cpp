
#include <iostream>
using namespace std;

// Version avec des pointeurs
void echanger(int* a, int* b)
{
    int temporaire = *a;
    *a = *b;
    *b = temporaire;
}

// Version avec des references
void echanger(int& a, int& b)
{
    int temporaire = a;
    a = b;
    b = temporaire;
}

void echangerDouble(double& a, double& b)
{
    double temporaire = a;
    a = b;
    b = temporaire;
}

void echangerChar(char& a, char& b)
{
    char temporaire = a;
    a = b;
    b = temporaire;
}

int main()
{
    int x = 1;
    int y = 2;

    cout << "Avant le premier echange : "
         << x << " " << y << '\n';

    echanger(&x, &y);

    cout << "Apres l'echange par pointeurs : "
         << x << " " << y << '\n';

    echanger(x, y);

    cout << "Apres l'echange par references : "
         << x << " " << y << '\n';

    double premier = 1.5;
    double second = 2.5;

    cout << "Doubles avant : "
         << premier << " " << second << '\n';

    echangerDouble(premier, second);

    cout << "Doubles apres : "
         << premier << " " << second << '\n';

    char lettre1 = 'A';
    char lettre2 = 'B';

    cout << "Caracteres avant : "
         << lettre1 << " " << lettre2 << '\n';

    echangerChar(lettre1, lettre2);

    cout << "Caracteres apres : "
         << lettre1 << " " << lettre2 << '\n';

    return 0;
}
