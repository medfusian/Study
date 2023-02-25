#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x, y, z, w;
    cout << "Vvedite 1-oe chislo: ";
    cin >> x;
    cout << "Vvedite 2-oe chislo: ";
    cin >> y;
    cout << "Vvedite 3-e chislo: ";
    cin >> z;
    cout << "Vvedite 4-oe chislo: ";
    cin >> w;
    if ((x + y) == (z + w)) { cout << "ravna"; }
    else { cout << "ne ravna"; }
    return 0;
}