
#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    int y = 2;

    const int* a = &x;
    int* const b = &x;
    const int* const c = &x;


    *b = 5;


    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';

    cout << "a designe y : " << (*a == y) << '\n';
    cout << "b designe toujours x : " << (*b == x) << '\n';
    cout << "c designe toujours x : " << (*c == x) << '\n';

    return 0;
}
