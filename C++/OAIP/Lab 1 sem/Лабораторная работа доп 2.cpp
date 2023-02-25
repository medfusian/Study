#include <iostream>
using namespace std;

struct vokzal
{
	int svbm;
	int nomp;
	int vrem;
	char gorod[100];
};

void vremotp(vokzal*, int*);
void kolsvob(vokzal*, int*);

int main()
{
	int n;
	cout << "Vvedite kolvo poezdov: "; cin >> n;
	cout << "Svob mesta   Nomer poezda   Vrema otprav   Gorod" << endl;
	vokzal* p = new vokzal[n];
	for (int i = 0; i < n; i++)
		cin >> (p + i)->svbm >> (p + i)->nomp >> (p + i)->vrem >> (p + i)->gorod;
	vremotp(p, &n);
	kolsvob(p, &n);
	return 0;
}

void vremotp(vokzal* p, int* n)
{
	int vremx, vremy; char gorod1[100];
	cout << "Vvedite gorod: "; cin >> gorod1;
	cout << "Vvedite promej otp (x y): "; cin >> vremx >> vremy;
	for (int i = 0; i < *n; i++)
		if (!strcmp((p + i)->gorod, gorod1))
			if ((p + i)->vrem > vremx && (p+i)->vrem < vremy)
				cout << "Vrema otp takogo poezda: " << (p + i)->vrem << endl;
}

void kolsvob(vokzal* p, int* n)
{
	int nomp1;
	cout << "Vvedite nomer poezda: "; cin >> nomp1;
	for (int i = 0; i < *n; i++)
		if ((p + i)->nomp == nomp1)
			cout << "kolvo svobod mest: " << (p + i)->svbm;
}