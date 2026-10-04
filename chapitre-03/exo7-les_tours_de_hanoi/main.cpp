#include <iostream>

using namespace std;

long long nombreDeplacements = 0;

void hanoi(int n, char depart, char arrivee, char intermediaire)
{
    if (n <= 0)
    {
        return;
    }

    if (n == 1)
    {
        cout << depart << '>' << arrivee << '\n';
        nombreDeplacements++;
        return;
    }

    hanoi(n - 1, depart, intermediaire, arrivee);

    cout << depart << '>' << arrivee << '\n';
    nombreDeplacements++;

    hanoi(n - 1, intermediaire, arrivee, depart);
}

int main()
{
    int n;
    cin >> n;

    hanoi(n, 'A', 'C', 'B');

    cout << nombreDeplacements << '\n';

    return 0;
}
