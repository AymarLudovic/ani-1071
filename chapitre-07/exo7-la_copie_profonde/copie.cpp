#include <cstdio>
#include <cstring>

class Image
{
private:
    int largeur_;
    int hauteur_;
    char* pixels_;
    static int vivantes;

public:
    Image(int l, int h)
        : largeur_(l), hauteur_(h), pixels_(new char[l * h])
    {
        effacer();
        vivantes++;
    }

    Image(const Image& autre)
        : largeur_(autre.largeur_), hauteur_(autre.hauteur_),
          pixels_(new char[autre.largeur_ * autre.hauteur_])
    {
        std::memcpy(pixels_, autre.pixels_, largeur_ * hauteur_);
        vivantes++;
    }

    Image& operator=(const Image& autre)
    {
        // if (this == &autre) return *this; // PROTECTION volontairement retiree pour l'experience.
        const char* source = autre.pixels_;
        int nouvelleLargeur = autre.largeur_;
        int nouvelleHauteur = autre.hauteur_;
        delete[] pixels_;
        largeur_ = nouvelleLargeur;
        hauteur_ = nouvelleHauteur;
        pixels_ = new char[largeur_ * hauteur_];
        std::memcpy(pixels_, source, largeur_ * hauteur_); // source devient invalide si *this == autre
        return *this;
    }

    ~Image()
    {
        delete[] pixels_;
        vivantes--;
    }

    void effacer(char c = ' ')
    {
        for (int i = 0; i < largeur_ * hauteur_; i++) pixels_[i] = c;
    }

    void point(int x, int y, char c = '#')
    {
        if (x < 0 || x >= largeur_ || y < 0 || y >= hauteur_) return;
        pixels_[y * largeur_ + x] = c;
    }

    void afficher() const
    {
        for (int y = 0; y < hauteur_; y++)
        {
            for (int x = 0; x < largeur_; x++)
            {
                unsigned char caractere = static_cast<unsigned char>(pixels_[y * largeur_ + x]);
                std::printf("%c", (caractere >= 32 && caractere <= 126) ? caractere : '.');
            }
            std::printf("\n");
        }
    }

    const void* adressePixels() const { return static_cast<const void*>(pixels_); }
    static int nombreVivantes() { return vivantes; }
};

int Image::vivantes = 0;

int main()
{
    {
        Image a(6, 4);
        a.point(1, 1, 'A');
        a.point(2, 1, 'A');

        Image b = a; // constructeur de copie profonde
        b.point(1, 1, 'B');

        std::printf("Original a apres modification de b :\n");
        a.afficher();
        std::printf("Copie b :\n");
        b.afficher();

        Image c(2, 2);
        c = a; // affectation profonde
        c.point(2, 1, 'C');
        std::printf("Original a apres modification de c :\n");
        a.afficher();
        std::printf("Copie c :\n");
        c.afficher();
        std::printf("Vivantes dans le bloc : %d\n", Image::nombreVivantes());

        std::printf("\nAvant a = a : %p\n", a.adressePixels());
        a = a; // auto-affectation volontaire sans garde : comportement indefini
        std::printf("Apres a = a :  %p\n", a.adressePixels());
        std::printf("Image a apres auto-affectation :\n");
        a.afficher();
    }

    std::printf("Vivantes apres le bloc : %d\n", Image::nombreVivantes());
    return 0;
}
