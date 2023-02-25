#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x, y, f, b;
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
    if (f > 0) b = (pow(x, 2) + pow(f, 2)) / y;
    else
        if (f < 0) b = log(fabs(pow(f, 3))) + cos(f);
        else b = pow(pow(sin(y), 2), 1 / 3.);
    cout << "Result = " << b;
    return 0;
}