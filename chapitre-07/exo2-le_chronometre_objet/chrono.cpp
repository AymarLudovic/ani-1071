#include <chrono>
#include <cstdio>

// Rend le nombre de secondes depuis l'epoque de steady_clock.
double maintenant()
{
    using namespace std::chrono;
    auto t = steady_clock::now().time_since_epoch();
    return duration<double>(t).count();
}

class Chrono
{
private:
    double depart;

public:
    Chrono() : depart(maintenant()) {}

    double ecoule() const
    {
        return maintenant() - depart;
    }

    void redemarrer()
    {
        depart = maintenant();
    }
};

int main()
{
    // Trois mesures de la meme boucle, comme trois lancements du programme.
    for (int essai = 1; essai <= 3; essai++)
    {
        long long total = 0;
        Chrono c;
        for (long long i = 0; i < 100000000; i++) total += i;
        std::printf("Boucle %d : total = %lld, duree = %.9f s\n", essai, total, c.ecoule());
    }

    Chrono c;
    std::printf("\nCinq mesures immediatement apres redemarrer :\n");
    for (int i = 0; i < 5; i++)
    {
        c.redemarrer();
        std::printf("Mesure %d : %.9f s\n", i + 1, c.ecoule());
    }

    const Chrono k;
    std::printf("\nLecture sur un Chrono constant : %.9f s\n", k.ecoule());
    // k.redemarrer(); // REFUSE : redemarrer modifie l'objet, donc n'est pas const.

    return 0;
}
