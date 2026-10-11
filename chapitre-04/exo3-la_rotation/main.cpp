#include <iostream>
using namespace std;

void tourner(int t[], int n, int k)
{
    if (n <= 0) {
        return;
    }

    k = k % n;

    if (k < 0) {
        k += n;
    }

    int temporaire[1000];

    for (int i = 0; i < n; i++) {
        temporaire[i] = t[(i + k) % n];
    }

    for (int i = 0; i < n; i++) {
        t[i] = temporaire[i];
    }
}

int main()
{
    int n, k;
    int t[1000];

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    tourner(t, n, k);

    for (int i = 0; i < n; i++) {
        cout << t[i] << '\n';
    }

    return 0;
}
