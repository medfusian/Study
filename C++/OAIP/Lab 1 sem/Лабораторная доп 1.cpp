#include <iostream>
using namespace std;

void poisk(int*, int*, int*, int&, int&);
void in(int*, int*);
void Outt(int*, int*);

int main()
{
	int n = 0, imin = 0, imax = 0, sred = 0;
	cout << "Vvedite kolich elementov: "; cin >> n;
	int* mas = new int[n];
	in(&n, mas);
	Outt(&n, mas);
	poisk(mas, &n, &sred, imax, imin);
	delete[] mas;
	mas = nullptr;
	return 0;
}

void in(int* n, int* mas)
{
	for (int i = 0; i < *n; i++) {
		cout << "Vvedite " << i + 1 << " element masiva: ";
		cin >> mas[i];
	}
}

void Outt(int* n, int* mas)
{
	for (int i = 0; i < *n; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;
}

void poisk(int* mas, int* n, int* sr, int& imax, int& imin)
{
	for (int i = 0; i < *n; i++) {
		*sr += *(mas + i) / static_cast <double>(*n);
	}
	cout << "Sred znach: " << *sr << endl;
	int min = *mas, max = 0;
	for (int i = 0; i < *n; i++)
	{
		if (*(mas + i) > max) {
			max = *(mas + i); imax = i;
		}
		else if (*(mas + i) < min) {
			min = *(mas + i); imin = i;
		}
	}
	cout << "Index min elem: " << imin << " Index max elem: " << imax;
}