#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, x, y, h;
    int n, i;
    cout << "Vvedite a,b,n: " << endl;
    cin >> a >> b >> n;
    h = (b - a) / 10;
    x = a;
    do
    {
        y = 1;
        for (i = 1; i <= n; i++)
        {
            y += (3 * pow(x, 2 * i) + 4 * exp(3 * i));
        }
        cout << setw(15) << x << setw(15) << y << endl;
        x += h;
    } while (x <= b + h / 2);
    return 0;
}