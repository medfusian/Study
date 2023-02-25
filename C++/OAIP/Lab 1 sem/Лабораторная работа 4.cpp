#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int k, i, j, r;
	char A[200];
	cout << "Количество символов: ";
	cin >> k;
	cout << "Введите элемены массива: ";
	for (i = 0; i < k; i++) cin >> A[i];
	for (i = 0; i < k; i++)
		for (j = 1; j < k; j++)
		{
			if (A[j] < A[j - 1])
			{
				r = A[j - 1]; A[j - 1] = A[j]; A[j] = r;
			}
		}

	for (i = 0; i < k; i++) cout << A[i];
	cout << endl;

	for (i = 1; i <= k; i++)
		if (A[i] != A[i - 1] && A[i] != A[i + 1]) cout << A[i];
	return 0;
}