#include <iostream>
using namespace std;

void fun(int*, int*, double*, double*, double*);

int main()
{
	int k=1, l; double s=10, p, q=0;
	cout << "Vvedite sumarniy probeg: "; cin >> l;
	cout << "Vvedite procent (0<P<50): "; cin >> p;
	fun(&k, &l, &s, &p, &q);
	cout << "Kolvo dney: " << k << endl;
	cout << "Probeg: " << q;
	return 0;
}

void fun(int* k, int* l, double* s, double* p, double* q)
{
	*q += *s;
	if (*q >= *l) return;
	else { *k += 1; return fun(k, l, &(*s += *s * (*p / 100)), p, q); }
}