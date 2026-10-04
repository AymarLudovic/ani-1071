#include <iostream>

using namespace std;

long long fibonacci(int n, long long& appels)
{
    appels++;

    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1, appels) + fibonacci(n - 2, appels);
}

int main()
{
    int n;
    cin >> n;

    long long appels = 0;

    long long resultat = fibonacci(n, appels);

    cout << resultat << '\n';
    cout << appels << '\n';

    return 0;
}
