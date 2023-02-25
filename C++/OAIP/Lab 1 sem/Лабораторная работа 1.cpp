#include <iostream> 
#include <math.h> 

using namespace std;

int main()
{
	double x, y, z, a, b, c, d, e;
	cout << "Vvedite x: ";
	cin >> x;
	cout << "Vvedite y: ";
	cin >> y;
	cout << "Vvedite z: ";
	cin >> z;
	a = pow(x, y + 1) + exp(y - 1);
	b = 1 + x * fabs(y - tan(z));
	c = 1 + fabs(y - x);
	d = pow(fabs(y - x), 2) / 2;
	e = pow(fabs(y - x), 3) / 3;
	cout << "s = " << a / b * c + d - e;
	return 0;
}