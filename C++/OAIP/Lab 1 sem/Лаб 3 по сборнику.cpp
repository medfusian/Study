#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	double a, b, h, x, y, s, p;
	int n, i;
	cout << "Vvedite a,b,h,n" << endl;
	cin >> a >> b >> n;
	h = (b - a) / 10;
	x = a;

	do
	{
		p = 1; s = 0;
		for (i = 1; i <= n; i++)
		{
			p *= pow(-1, i + 1) * pow(x, 2) / (4 * i - 2);
			s += p;
		}
		y = x * atan(x) - log(pow(1 + pow(x,2), 1. / 2));
		cout << setw(15) << x << setw(15) << y << setw(15) << s << setw(15) << fabs(y - s) << endl;
		x += h;
	} while (x <= b + h / 2);
	cout << endl;
	return 0;
}