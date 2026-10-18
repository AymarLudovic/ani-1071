
#include <iostream>
using namespace std;

// Creer une image de l caracteres de largeur et h de hauteur
char* creerImage(int l, int h)
{
    char* img = new char[l * h];

    for (int i = 0; i < l * h; ++i)
    {
        img[i] = ' ';
    }

    return img;
}

void detruireImage(char* img)
{
    delete[] img;
}


void point(char* img, int l, int h, int x, int y, char c)
{
    if (x < 0 || x >= l || y < 0 || y >= h)
    {
        return;
    }

    img[y * l + x] = c;
}

// Afficher l'image ligne par ligne
void afficher(const char* img, int l, int h)
{
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < l; ++x)
        {
            cout << img[y * l + x];
        }

        cout << '\n';
    }
}

// Dessiner un cercle dans l'image
void cercle(char* img, int l, int h)
{
    int cx = l / 2;
    int cy = h / 2;
    int r = h / 2 - 1;

    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < l; ++x)
        {
            int dx = x - cx;
            int dy = y - cy;

            if (dx * dx + dy * dy <= r * r)
            {
                point(img, l, h, x, y, '#');
            }
        }
    }
}

int main()
{
    cout << "Image 30 x 10 :\n";

    char* image1 = creerImage(30, 10);
    cercle(image1, 30, 10);
    afficher(image1, 30, 10);
    detruireImage(image1);

    cout << "\nImage 80 x 24 :\n";

    char* image2 = creerImage(80, 24);
    cercle(image2, 80, 24);
    afficher(image2, 80, 24);
    detruireImage(image2);

    return 0;
}
