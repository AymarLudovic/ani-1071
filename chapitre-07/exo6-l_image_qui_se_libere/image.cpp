#include <cstdio>

class Image
{
private:
    int largeur_;
    int hauteur_;
    char* pixels_;
    static int vivantes;

    static double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }

public:
    Image(int l, int h)
        : largeur_(l), hauteur_(h), pixels_(new char[l * h])
    {
        effacer();
        vivantes++;
    }

    ~Image()
    {
        delete[] pixels_;
        vivantes--;
    }

    Image(const Image&) = delete;             // pas de copie
    Image& operator=(const Image&) = delete;  // pas d'affectation

    void effacer(char c = ' ')
    {
        for (int i = 0; i < largeur_ * hauteur_; i++) pixels_[i] = c;
    }

    void point(int x, int y, char c = '#')
    {
        if (x < 0 || x >= largeur_ || y < 0 || y >= hauteur_) return;
        pixels_[y * largeur_ + x] = c;
    }

    void segment(double x0, double y0, double x1, double y1, char c = '#')
    {
        const int pas = 60;
        for (int i = 0; i <= pas; i++)
        {
            double t = i / static_cast<double>(pas);
            point(static_cast<int>(lerp(x0, x1, t) + 0.5),
                  static_cast<int>(lerp(y0, y1, t) + 0.5), c);
        }
    }

    void afficher() const
    {
        for (int y = 0; y < hauteur_; y++)
        {
            for (int x = 0; x < largeur_; x++)
                std::printf("%c", pixels_[y * largeur_ + x]);
            std::printf("\n");
        }
    }

    int largeur() const { return largeur_; }
    int hauteur() const { return hauteur_; }

    static int nombreVivantes() { return vivantes; }
};

int Image::vivantes = 0;

int main()
{
    std::printf("Avant la boucle : %d image(s) vivante(s)\n", Image::nombreVivantes());

    for (int i = 0; i < 10; i++)
    {
        Image image(20, 10);
        image.segment(1, 1, 18, 8);
        std::printf("Tour %d : %d image(s) vivante(s)\n", i + 1, Image::nombreVivantes());
    }

    std::printf("Apres la boucle : %d image(s) vivante(s)\n", Image::nombreVivantes());

    {
        Image dessin(21, 11);
        dessin.segment(1, 1, 19, 9);
        dessin.segment(1, 9, 19, 1);
        std::printf("\nDessin (%d x %d) :\n", dessin.largeur(), dessin.hauteur());
        dessin.afficher();
        // Image b = dessin; // REFUSE : le constructeur de copie est delete.
        std::printf("Pendant le dessin : %d image(s) vivante(s)\n", Image::nombreVivantes());
    }

    std::printf("A la fin : %d image(s) vivante(s)\n", Image::nombreVivantes());
    return 0;
}
