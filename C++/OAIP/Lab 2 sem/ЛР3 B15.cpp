#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	double a, b, h, x, y, s, l;
	int n, k, i;
	cout << "Vvedite a,b,k: " << endl;
	cin >> a >> b >> k;
	h = (b - a) / 10;
	x = a;
	s = 0;
	cout << setw(15) << "x" << setw(15) << "y(x)" << setw(15) << "s(x)" << endl;
	do
	{
		
		for (n = 0; n <= k; n++)
		{
			l = 1;
			for (i = 1; i <= 2 * n; i++)
			{
				l *= i;
			}
			s += pow(-4,n)*pow(x,2*n)/l;
		}
		y = cos(2 * x);
		cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
		x += h;
	} while (x <= b + h / 2);
	cout << endl;
	return 0;
}