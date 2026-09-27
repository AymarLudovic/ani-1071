# Réponse

J'ai utilisé `sizeof` pour mesurer la taille des types de base du C++.

Sur ma machine Windows avec Clang, j'obtiens :

```text
bool          : 1 octet
char          : 1 octet
unsigned char : 1 octet
short         : 2 octets
int           : 4 octets
long          : 4 octets
long long     : 8 octets
unsigned int  : 4 octets
float         : 4 octets
double        : 8 octets
long double   : 16 octets
```

Pour `void`, `sizeof` provoque une erreur de compilation :

```text
c2-exo9_main.cpp:15:49: error: invalid application of 'sizeof' to an incomplete type 'void'
   15 |     std::printf("void          : %zu octets\n", sizeof(void));
      |                                                 ^     ~~~~~~
1 error generated.
```

Cela signifie que `void` ne représente pas un type d'objet ayant une taille en mémoire que l'on peut mesurer avec `sizeof`.

## Taille différente selon le système

Le type qui peut avoir une taille différente selon le système est `long`.

Sur ma machine Windows, `long` occupe 4 octets. Sur beaucoup de systèmes Linux 64 bits, il occupe généralement 8 octets.

Un programme qui suppose que `long` possède toujours la même taille peut donc fonctionner différemment lorsqu'il est compilé sur un autre système.

## Nombre de valeurs

Un octet contient 8 bits.

Avec `n` octets, un type peut avoir :

`2^(8 × n)`

représentations différentes.

Le plus petit des types testés occupe 1 octet. Il peut donc avoir :

`2^8 = 256`

valeurs différentes.

Par exemple, un `unsigned char` peut représenter 256 valeurs, de `0` à `255`.
