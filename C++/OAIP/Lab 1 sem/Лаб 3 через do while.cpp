#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	double a, b, h, x, y, s, p;
	int k, i, f;
	cout << "Vvedite a,b,k" << endl;
	cin >> a >> b >> k;
	h = (b - a) / 10;
	x = a;
	do
	{
		p = s = 1;
		for (i = 1; i <= k; i++)
		{
			f = 2 * i;
			p *= (-4) * pow(x, 2) / (pow(f, 2) - f);
			s += p;
		}
		y = cos(2 * x);
		cout << setw(15) << x << setw(15) << y << setw(15) << s << setw(15) << fabs(s - y) << endl;
		x += h;
	}
	while (x <= b + h / 2);
	cout << endl;
	return 0;
}