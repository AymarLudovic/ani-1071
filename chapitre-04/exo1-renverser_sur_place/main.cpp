```cpp
#include <iostream>
using namespace std;

void renverser(int t[], int n)
{
    for (int i = 0; i < n / 2; i++) {
        int temporaire = t[i];
        t[i] = t[n - 1 - i];
        t[n - 1 - i] = temporaire;
    }
}

int main()
{
    int t[1000];
    int n;

    cin >> n;

    if (n == 0) {
        cout << "AUCUN\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    renverser(t, n);

    for (int i = 0; i < n; i++) {
        cout << t[i] << '\n';
    }

    return 0;
}
```
