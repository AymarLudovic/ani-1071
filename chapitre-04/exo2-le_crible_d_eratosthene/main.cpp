#include <iostream>
using namespace std;

void cribler(bool premier[], int n)
{
    for (int i = 0; i <= n; i++) {
        premier[i] = false;
    }

    for (int i = 2; i <= n; i++) {
        premier[i] = true;
    }

    for (int i = 2; 1LL * i * i <= n; i++) {
        if (premier[i]) {
            for (long long j = 1LL * i * i; j <= n; j += i) {
                premier[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    if (n < 2) {
        cout << "AUCUN\n";
        return 0;
    }

    bool premier[100001];

    cribler(premier, n);

    for (int i = 2; i <= n; i++) {
        if (premier[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
