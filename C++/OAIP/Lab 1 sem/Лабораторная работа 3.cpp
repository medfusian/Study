#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	double a, b, h, x, y, s, p;
	int k, i;
	cout << "Vvedite a,b,k" << endl;
	cin >> a >> b >> k;
	h = (b - a) / 10;
	cout << setw(15) << "X" << setw(15) << "Y(x)" << setw(15) << "S(x)" << endl;
	for (x = a; x < b + h / 2; x += h)
	{
		for (i = 1, p = 1, s = 1; i <= k; i++)
		{
			p *= (-4) * x * x / (2 * i * (2 * i - 1));
			s += p;
		}
		y = cos(2 * x);
		cout << setw(15) << x << setw(15) << y << setw(15) << s << setw(15) << fabs(s - y) << endl;
	}
	cout << endl;
	return 0;
}