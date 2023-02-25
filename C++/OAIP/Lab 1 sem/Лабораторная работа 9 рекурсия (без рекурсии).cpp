#include <iostream>
using namespace std;

void fun(int*, int*, double*, double*, double*);

int main()
{
	int k = 1, l; double s, p, q=10;
	cout << "Vvedite sumarniy probeg: "; cin >> l;
	cout << "Vvedite procent (0<P<50): "; cin >> p;
	fun(&k, &l, &s, &p, &q);
	cout << "Kolvo dney: " << k << endl;
	cout << "Probeg: " << q;
	return 0;
}

void fun(int* k, int* l, double* s, double* p, double* q)
{
	for (*s = 10; *q <= *l; *s += *s * (*p / 100), *k+=1, *q+=*s);
}