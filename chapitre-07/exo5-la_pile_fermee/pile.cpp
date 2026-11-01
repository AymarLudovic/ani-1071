#include <cstdio>

class Pile
{
private:
    static const int CAPACITE = 100;
    int elements[CAPACITE];
    int nombre;

public:
    Pile() : nombre(0) {}

    void empiler(int v)
    {
        if (!pleine()) elements[nombre++] = v;
    }

    int depiler()
    {
        return (nombre > 0) ? elements[--nombre] : -1;
    }

    int sommet() const
    {
        return (nombre > 0) ? elements[nombre - 1] : -1;
    }

    bool vide() const { return nombre == 0; }
    bool pleine() const { return nombre == CAPACITE; }
    int taille() const { return nombre; }
};

class File
{
private:
    static const int CAPACITE = 100;
    int elements[CAPACITE];
    int tete;
    int queue;
    int nombre;

public:
    File() : tete(0), queue(0), nombre(0) {}

    void enfiler(int v)
    {
        if (pleine()) return;
        elements[queue] = v;
        queue = (queue + 1) % CAPACITE;
        nombre++;
    }

    int defiler()
    {
        if (vide()) return -1;
        int v = elements[tete];
        tete = (tete + 1) % CAPACITE;
        nombre--;
        return v;
    }

    bool vide() const { return nombre == 0; }
    bool pleine() const { return nombre == CAPACITE; }
    int taille() const { return nombre; }
};

int main()
{
    Pile p;
    // p.nombre = -5; // REFUSE : nombre est prive.

    for (int i = 0; i < 150; i++) p.empiler(i);
    std::printf("Pile apres 150 empilements : %d (pleine=%s)\n",
                p.taille(), p.pleine() ? "oui" : "non");

    for (int i = 0; i < 200; i++) p.depiler();
    std::printf("Pile apres 200 depilements : %d (vide=%s)\n",
                p.taille(), p.vide() ? "oui" : "non");

    File f;
    // f.tete = 7; // REFUSE : tete est prive.

    for (int i = 0; i < 150; i++) f.enfiler(i);
    std::printf("File apres 150 enfilements : %d (pleine=%s)\n",
                f.taille(), f.pleine() ? "oui" : "non");

    for (int i = 0; i < 60; i++) f.defiler();
    std::printf("File apres 60 defilements : %d\n", f.taille());

    for (int i = 0; i < 150; i++) f.enfiler(1000 + i);
    std::printf("File apres 150 nouveaux enfilements : %d (pleine=%s)\n",
                f.taille(), f.pleine() ? "oui" : "non");

    return 0;
}
