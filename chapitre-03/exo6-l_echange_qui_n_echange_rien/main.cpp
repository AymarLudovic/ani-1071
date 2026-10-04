#include <iostream>

using namespace std;

void echangerParValeur(int a, int b)
{
    int temporaire = a;
    a = b;
    b = temporaire;
}

void echangerParReference(int& a, int& b)
{
    int temporaire = a;
    a = b;
    b = temporaire;
}

int main()
{
    int a;
    int b;

    cin >> a >> b;

    echangerParValeur(a, b);

    cout << a << '\n';
    cout << b << '\n';

    echangerParReference(a, b);

    cout << a << '\n';
    cout << b << '\n';

    return 0;
}
