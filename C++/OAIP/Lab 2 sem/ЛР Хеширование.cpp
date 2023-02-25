#include <iostream>
using namespace std;

struct Cars
{
	char marka[10];
	int maxSpeed;
	int godVipuska;
}*masCars;

void tabAdd(int inf, int M, Cars H[], int in)
{
	int i = inf % M;
	if (H[i].maxSpeed == -1) {
		H[i].maxSpeed = inf;
		strcpy_s(H[i].marka, masCars[in].marka);
		H[i].godVipuska = masCars[in].godVipuska;
	}
	else {
		int c = 1 + (inf % (M - 2));
		while (H[i].maxSpeed != -1)
		{
			i = i - c;
			if (i < 0) i = i + M;
		}
		H[i].maxSpeed = inf;
		strcpy_s(H[i].marka, masCars[i].marka);
		H[i].godVipuska = masCars[i].godVipuska;
	}
}

int search(int inf, int M, Cars H[])
{
	int i = inf % M;
	while (H[i].maxSpeed != -1) {
		if (H[i].maxSpeed == inf) return i;
		int c = 1 + (inf % (M - 2));
		i = i - c;
		if (i < 0) i = i + M;
	}
	return -1;
}

int main()
{
	int n, M;
	cout << "Vvedite n: "; cin >> n;
	cout << "Vvedite M: "; cin >> M;
	Cars *H = new Cars[M];
	masCars = new Cars[n];
	for (int i = 0; i < n; i++) {
		cout << "Vvedite marku " << i + 1 << " mashini: "; getchar(); gets_s(masCars[i].marka);
		cout << "Vvedite max skor " << i + 1 << " mashini: "; cin >> masCars[i].maxSpeed;
		cout << "Vvedite god vipuska " << i + 1 << " mashini: "; cin >> masCars[i].godVipuska;
		cout << endl;
	}
	for (int i = 0; i < M; i++) H[i].maxSpeed = -1;
	for (int i = 0; i < n; i++) tabAdd(masCars[i].maxSpeed, M, H, i);
	int inf = 0, ii;
	while (inf != -1) {
		cout << "Vvod ('-1' to exit): "; cin >> inf;
		ii = search(inf, M, H);
		if (ii == -1) cout << "Net elementa" << endl;
		else cout << H[ii].marka << " " << H[ii].maxSpeed << " " << H[ii].godVipuska << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) cout << masCars[i].marka << " " << masCars[i].maxSpeed << " " << masCars[i].godVipuska << endl;
	cout << endl;
	for (int i = 0; i < M; i++) cout << H[i].maxSpeed << "   ";

	delete[] H;
	delete[] masCars;
}