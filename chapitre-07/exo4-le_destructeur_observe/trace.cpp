#include <cstdio>

class Trace
{
private:
    const char* nom;

public:
    Trace(const char* n) : nom(n)
    {
        std::printf("%s nait\n", nom);
    }

    ~Trace()
    {
        std::printf("%s meurt\n", nom);
    }
};

void fonction()
{
    Trace locale("fonction");
    std::printf("fin fonction\n");
} // locale meurt ici

int main()
{
    Trace m("main");

    fonction();

    {
        Trace bloc("bloc simple");
        std::printf("fin bloc simple\n");
    } // bloc simple meurt ici

    Trace* fuite = new Trace("new sans delete");
    (void)fuite; // volontairement jamais delete : l'objet ne meurt pas

    Trace* dynamique = new Trace("new avec delete");
    delete dynamique;

    {
        Trace premier("premier du bloc double");
        Trace second("second du bloc double");
        std::printf("fin bloc double\n");
    } // destruction dans l'ordre inverse : second puis premier

    std::printf("fin main\n");

    m.~Trace(); // Appel manuel volontaire : le destructeur automatique arrivera encore a la sortie.
    return 0;
}
