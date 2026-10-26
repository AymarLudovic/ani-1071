#include <cstdio>
#include <cmath>

// Définition de Pi (car M_PI peut ne pas être défini avec -std=c++17)
const double PI = 3.14159265358979323846;

struct Vec2
{
    double x;
    double y;
};

// 1. Somme, différence et multiplication par un scalaire
Vec2 add(Vec2 a, Vec2 b)
{
    return {a.x + b.x, a.y + b.y};
}

Vec2 sub(Vec2 a, Vec2 b)
{
    return {a.x - b.x, a.y - b.y};
}

Vec2 scale(Vec2 a, double k)
{
    return {a.x * k, a.y * k};
}

// 2. Produit scalaire et longueur
double dot(Vec2 a, Vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

double length(Vec2 a)
{
    return std::sqrt(dot(a, a));
}

// 3. Normalisation (avec protection contre la division par zéro)
Vec2 normalize(Vec2 a)
{
    double len = length(a);
    if (len == 0.0)
    {
        return {0.0, 0.0};
    }
    return scale(a, 1.0 / len);
}

// 4. Interpolation linéaire (lerp)
Vec2 lerp(Vec2 a, Vec2 b, double t)
{
    return add(a, scale(sub(b, a), t));
}

// 5. Perpendiculaire et Rotation
Vec2 perp(Vec2 a)
{
    return {-a.y, a.x};
}

Vec2 rotate(Vec2 a, double angle)
{
    double c = std::cos(angle);
    double s = std::sin(angle);
    return {a.x * c - a.y * s, a.x * s + a.y * c};
}

// 6. Réflexion (rebond)
Vec2 reflect(Vec2 v, Vec2 n)
{
    double d = dot(v, n);
    return sub(v, scale(n, 2.0 * d));
}

// 7. Conversion degrés -> radians
double radians(double degres)
{
    double r = degres * PI / 180.0;
    return r;
}

int main()
{
    // 8. Les quatre vérifications principales
    printf("--- Les quatre ---\n");
    printf("length({3, 4}) = %.17g\n", length({3.0, 4.0}));
    printf("dot({1, 0}, {0, 1}) = %.17g\n", dot({1.0, 0.0}, {0.0, 1.0}));
    
    Vec2 rot = rotate({1.0, 0.0}, radians(90.0));
    printf("rotate({1, 0}, radians(90)) = {%.17g, %.17g}\n", rot.x, rot.y);
    
    Vec2 ref = reflect({1.0, -1.0}, {0.0, 1.0});
    printf("reflect({1, -1}, {0, 1}) = {%.17g, %.17g}\n", ref.x, ref.y);

    // 9. Essais pour les fonctions restantes
    printf("\n--- Mes essais ---\n");
    Vec2 r_add = add({1.0, 2.0}, {3.0, 4.0});
    printf("add({1, 2}, {3, 4}) = {%.17g, %.17g}\n", r_add.x, r_add.y);
    
    Vec2 r_sub = sub({3.0, 4.0}, {1.0, 2.0});
    printf("sub({3, 4}, {1, 2}) = {%.17g, %.17g}\n", r_sub.x, r_sub.y);
    
    Vec2 r_scale = scale({1.0, 2.0}, 2.5);
    printf("scale({1, 2}, 2.5) = {%.17g, %.17g}\n", r_scale.x, r_scale.y);
    
    Vec2 r_norm = normalize({3.0, 4.0});
    printf("normalize({3, 4}) = {%.17g, %.17g}\n", r_norm.x, r_norm.y);
    
    Vec2 r_lerp = lerp({0.0, 0.0}, {10.0, 10.0}, 0.5);
    printf("lerp({0, 0}, {10, 10}, 0.5) = {%.17g, %.17g}\n", r_lerp.x, r_lerp.y);
    
    Vec2 r_perp = perp({1.0, 2.0});
    printf("perp({1, 2}) = {%.17g, %.17g}\n", r_perp.x, r_perp.y);

    return 0;
}
