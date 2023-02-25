#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double funs(double, int);
double funy(double);
double table(double, double);

double funs(double x, int k)
{
    double p = 1, s = 1;
    for (int i = 1; i <= k; i++)
    {
        p *= (-4) * x * x / (2 * i * (2 * i - 1));
        s += p;
    }
    return s;
}
double funy(double x)
{
    return cos(2 * x);
}


int main()
{
    double a, b, h, y, s;
    int k;
    cout << "Vvedite a, b, k: " << endl;
    cin >> a >> b >> k;
    h = (b - a) / 10;
    cout << setw(15) << "x" << setw(15) << "y" << setw(15) << "s" << endl;
    for (double x = a; x < b + h / 2; x += h)
    {
        s = funs(x, k);
        y = funy(x);
        cout << setw(15) << x << setw(15) << y << setw(15) << s << setw(15) << endl;
    }
    return 0;
}