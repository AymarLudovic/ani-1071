#include <iostream>

using namespace std;

long long pgcd(long long a, long long b)
{
    if (a < 0)
    {
        a = -a;
    }

    if (b < 0)
    {
        b = -b;
    }

    while (b != 0)
    {
        long long reste = a % b;
        a = b;
        b = reste;
    }

    return a;
}

long long ppcm(long long a, long long b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }

    if (a < 0)
    {
        a = -a;
    }

    if (b < 0)
    {
        b = -b;
    }

    return (a / pgcd(a, b)) * b;
}

int main()
{
    long long a;
    long long b;
    bool aLuUnCouple = false;

    while (cin >> a >> b)
    {
        cout << pgcd(a, b) << '\n';
        cout << ppcm(a, b) << '\n';

        aLuUnCouple = true;
    }

    if (!aLuUnCouple)
    {
        cout << "AUCUN\n";
    }

    return 0;
}
