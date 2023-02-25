#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x, y, f, w;
    int q;
    cout << "Vvedite x: ";
    cin >> x;
    cout << "Vvedite y: ";
    cin >> y;
    cout << "Viberite f: 1 - sh(x), 2 - x^2, 3 - exp(x) ";
    cin >> q;
    switch (q)
    {
    case 1: f = sinh(x); break;
    case 2: f = pow(x, 2); break;
    case 3: f = exp(x); break;
    default: cout << "Ne vuibrana funkciya "; return 1;
    }
    if (2 * x / y == 0) w = pow(f, 1 / 3.) - x * y;
    else
        if (2 * x / y < 0) w = pow(sin(x), 2) - y;
        else w = 4 * y - tan(x);
    cout << "Result = " << w;
    return 0;
}