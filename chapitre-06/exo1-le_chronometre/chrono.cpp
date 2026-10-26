#include <chrono>
#include <cstdio>

double maintenant()
{
    using namespace std::chrono;
    auto t = steady_clock::now().time_since_epoch();
    return duration<double>(t).count();     // en secondes
}

int main()
{
    // --- PARTIE 1 : Mesure de la boucle (3 fois) ---
    std::printf("--- Mesures de la boucle (1 à 1 000 000) ---\n");
    for (int tour = 0; tour < 3; ++tour)
    {
        double debut = maintenant();
        
        long long total = 0; // Utilisation de long long (car > 2 milliards)
        for (long long i = 1; i <= 1000000; ++i)
        {
            total += i;
        }
        
        double fin = maintenant();
        double duree = fin - debut;
        
        std::printf("Tour %d -> Total = %lld | Duree = %.8f s\n", tour + 1, total, duree);
    }

    // --- PARTIE 2 : Mesure de 5 printf de suite ---
    std::printf("\n--- Mesures de 5 printf ---\n");
    double durees_printf[5];
    
    for (int i = 0; i < 5; ++i)
    {
        double debut = maintenant();
        std::printf("Ligne courte numero %d\n", i + 1);
        double fin = maintenant();
        durees_printf[i] = fin - debut;
    }

    // Affichage groupé des durées des printf après coup
    std::printf("\nDurees des printf stockees :\n");
    for (int i = 0; i < 5; ++i)
    {
        std::printf("printf %d : %.8f s\n", i + 1, durees_printf[i]);
    }

    return 0;
}
