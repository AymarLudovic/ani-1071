#include <iostream>
using namespace std;

long long trierParBulles(int t[], int n)
{
    long long echanges = 0;

    for (int i = 0; i < n - 1; i++) {
        bool echangeEffectue = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (t[j] > t[j + 1]) {
                int temporaire = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temporaire;

                echanges++;
                echangeEffectue = true;
            }
        }

        if (!echangeEffectue) {
            break;
        }
    }

    return echanges;
}

int main()
{
    int n;
    int t[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    long long echanges = trierParBulles(t, n);

    for (int i = 0; i < n; i++) {
        cout << t[i] << '\n';
    }

    cout << echanges << '\n';

    return 0;
}
