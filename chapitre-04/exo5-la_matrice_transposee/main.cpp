#include <iostream>
using namespace std;

void transposer(const int source[], int lignes, int colonnes, int destination[])
{
    for (int y = 0; y < lignes; y++) {
        for (int x = 0; x < colonnes; x++) {
            int indiceSource = y * colonnes + x;
            int indiceDestination = x * lignes + y;

            destination[indiceDestination] = source[indiceSource];
        }
    }
}

int main()
{
    int lignes, colonnes;
    int source[10000];
    int destination[10000];

    cin >> lignes >> colonnes;

    for (int i = 0; i < lignes * colonnes; i++) {
        cin >> source[i];
    }

    transposer(source, lignes, colonnes, destination);

    for (int y = 0; y < colonnes; y++) {
        for (int x = 0; x < lignes; x++) {
            if (x > 0) {
                cout << ' ';
            }

            cout << destination[y * lignes + x];
        }

        cout << '\n';
    }

    return 0;
}
