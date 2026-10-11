#include <iostream>
using namespace std;

bool estPalindrome(const char s[])
{
    int longueur = 0;

    while (s[longueur] != '\0') {
        longueur++;
    }

    for (int i = 0; i < longueur / 2; i++) {
        if (s[i] != s[longueur - 1 - i]) {
            return false;
        }
    }

    return true;
}

void renverserTexte(char s[])
{
    int longueur = 0;

    while (s[longueur] != '\0') {
        longueur++;
    }

    for (int i = 0; i < longueur / 2; i++) {
        char temporaire = s[i];
        s[i] = s[longueur - 1 - i];
        s[longueur - 1 - i] = temporaire;
    }
}

int main()
{
    char s[201];

    cin >> s;

    if (estPalindrome(s)) {
        cout << "oui\n";
    } else {
        cout << "non\n";
    }

    renverserTexte(s);

    cout << s << '\n';

    return 0;
}
