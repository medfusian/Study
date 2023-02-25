#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

typedef double (*uf)(double, double, int&);
void tabl(double, double, double, double, uf);
double y(double, double, int&);
double s(double, double, int&);

int main()
{
    double a, b, h, eps;
    cout << "Vvedite a, b, eps: ";
    cin >> a >> b >> eps;
    h = (b - a) / 10;
    cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
    tabl(a, b, h, eps, y);
    cout << endl;
    cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
    tabl(a, b, h, eps, s);
    return 0;
}
void tabl(double a, double b, double h, double eps, uf fun)
{
    int k = 0;
    double rez;
    for (double x = a; x < b + h / 2; x += h)
    {
        rez = fun(x, eps, k);
        cout << setw(8) << x << setw(15) << rez << setw(10) << k << endl;
    }
}
double y(double x, double eps, int& k)
{
    return cos(2 * x);
}
double s(double x, double eps, int& k)
{
    double p, sum;
    sum = p = 1;
    for (k = 1; fabs(p) > eps; k++)
    {
        p *= (-4) * x * x / (2 * k * (2 * k - 1));
        sum += p;
    }
    return sum;
}