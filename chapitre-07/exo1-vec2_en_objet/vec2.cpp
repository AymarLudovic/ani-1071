#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

struct Vec2
{
    double x;
    double y;

    Vec2() : x(0.0), y(0.0) {}

    Vec2(double x_, double y_) : x(x_), y(y_) {}

    double length() const
    {
        return std::sqrt(x * x + y * y);
    }

    double dot(Vec2 b) const
    {
        return x * b.x + y * b.y;
    }

    Vec2 normalized() const
    {
        double l = length();
        if (l == 0.0)
        {
            return Vec2();
        }
        return Vec2(x / l, y / l);
    }

    void normalize()
    {
        double l = length();
        if (l != 0.0)
        {
            x /= l;
            y /= l;
        }
    }

    Vec2& operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& operator*=(double scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    double& operator[](int index)
    {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Indice Vec2 invalide");
    }

    const double& operator[](int index) const
    {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Indice Vec2 invalide");
    }
};

Vec2 operator+(const Vec2& a, const Vec2& b)
{
    return Vec2(a.x + b.x, a.y + b.y);
}

Vec2 operator-(const Vec2& a, const Vec2& b)
{
    return Vec2(a.x - b.x, a.y - b.y);
}

Vec2 operator-(const Vec2& v)
{
    return Vec2(-v.x, -v.y);
}

Vec2 operator/(const Vec2& v, double scalar)
{
    if (scalar == 0.0)
    {
        throw std::invalid_argument("Division d'un Vec2 par zero");
    }
    return Vec2(v.x / scalar, v.y / scalar);
}

bool operator==(const Vec2& a, const Vec2& b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vec2& a, const Vec2& b)
{
    return !(a == b);
}

Vec2 operator*(const Vec2& v, double scalar)
{
    return Vec2(v.x * scalar, v.y * scalar);
}

Vec2 operator*(double scalar, const Vec2& v)
{
    return v * scalar;
}

void afficher(const char* nom, const Vec2& v)
{
    std::cout << nom << " = (" << v.x << ", " << v.y << ")\n";
}

int main()
{
    std::cout << std::fixed << std::setprecision(4);

    std::cout << "=== ESSAIS DE VEC2 ===\n";

    Vec2 nul;
    afficher("Constructeur par defaut", nul);

    Vec2 a(3.0, 4.0);
    Vec2 b(1.0, 2.0);
    afficher("Constructeur avec deux valeurs (a)", a);
    afficher("Constructeur avec deux valeurs (b)", b);

    std::cout << "length(a) = " << a.length() << '\n';
    std::cout << "dot(a, b) = " << a.dot(b) << '\n';

    Vec2 aNormalise = a.normalized();
    afficher("a.normalized()", aNormalise);
    afficher("a apres normalized()", a);

    Vec2 c(3.0, 4.0);
    c.normalize();
    afficher("c apres normalize()", c);

    Vec2 nulNormalise = nul.normalized();
    afficher("nul.normalized()", nulNormalise);
    nul.normalize();
    afficher("nul apres normalize()", nul);

    afficher("a + b", a + b);
    afficher("a - b", a - b);
    afficher("-a", -a);
    afficher("a / 2", a / 2.0);
    std::cout << "a == Vec2(3, 4) : " << (a == Vec2(3.0, 4.0) ? "true" : "false") << '\n';
    std::cout << "a != b : " << (a != b ? "true" : "false") << '\n';
    afficher("a * 2", a * 2.0);
    afficher("2 * a", 2.0 * a);

    Vec2 modifiable = a;
    modifiable += b;
    afficher("apres += b", modifiable);
    modifiable -= b;
    afficher("apres -= b", modifiable);
    modifiable *= 2.0;
    afficher("apres *= 2", modifiable);

    Vec2 indice(1.0, 2.0);
    indice[1] = 5.0;
    afficher("indice apres indice[1] = 5", indice);
    std::cout << "indice[0] = " << indice[0] << '\n';
    std::cout << "indice[1] = " << indice[1] << '\n';

    std::cout << "\n=== CHUTE DE LA BALLE ===\n";

    Vec2 p(0.0, 10.0);
    Vec2 v(3.0, 0.0);
    Vec2 g(0.0, -9.81);
    const Vec2 pInitial(0.0, 10.0);
    const double dt = 0.1;
    double t = 0.0;

    std::cout << "t = " << t
              << " | p = (" << p.x << ", " << p.y << ")"
              << " | v = (" << v.x << ", " << v.y << ")\n";

    while (p.y >= 0.0)
    {
        v += g * dt;
        p += v * dt;
        t += dt;

        std::cout << "t = " << t
                  << " | p = (" << p.x << ", " << p.y << ")"
                  << " | v = (" << v.x << ", " << v.y << ")\n";
    }

    const double tSol = std::sqrt((2.0 * pInitial.y) / -g.y);
    std::cout << "\nInstant theorique du contact avec le sol = " << tSol << " s\n";
    std::cout << "Premier pas ou p.y devient negatif = " << t << " s\n";

    return 0;
}
