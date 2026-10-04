#include <iostream>

using namespace std;

unsigned int factorielle32(unsigned int n)
{
    unsigned int resultat = 1;

    for (unsigned int i = 2; i <= n; i++)
    {
        resultat *= i;
    }

    return resultat;
}

unsigned long long factorielle64(unsigned long long n)
{
    unsigned long long resultat = 1;

    for (unsigned long long i = 2; i <= n; i++)
    {
        resultat *= i;
    }

    return resultat;
}

int main()
{
    unsigned long long n;

    cin >> n;

    cout << factorielle32(static_cast<unsigned int>(n)) << '\n';
    cout << factorielle64(n) << '\n';

    return 0;
}
