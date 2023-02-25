#include <iostream> 
#include <cstdio> 
#include <io.h> 

using namespace std;
FILE* fl;

struct Karts
{
	int nomk;
	char fio[50];
	int skidka;
} *list, karta;

char fname[20] = "";
int n = 0;

void spuz();
void fadd();
void frd();
void rezc();
void rezf();
int menu();

bool flopen(const char*);

int main()
{
	while (true)
	{
		switch (menu())
		{
		case 1: fadd(); break;
		case 2: frd(); break;
		case 3: rezc(); break;
		case 4: rezf(); break;
		case 5: spuz(); break;
		case 6: return 0;
		default:"Error!";
		}
		system("pause");
		system("cls");
	}
	return 0;
}

int menu()
{
	cout << "Select: " << endl;
	cout << "1.Enter data and write to file" << endl;
	cout << "2.Read data from file" << endl;
	cout << "3.Display the result on the screen" << endl;
	cout << "4.Write the result to a file" << endl;
	cout << "5.Sortirovka puzirkom" << endl;
	cout << "6.QuickSort" << endl;
	cout << "7.Exit" << endl;
	int i;
	cin >> i;
	return i;
}

bool flopen(const char* r)
{
	if (!strlen(fname))
	{
		cout << "Enter file name: " << endl;
		cin >> fname;
	}

	if (fopen_s(&fl, fname, r))
	{
		cout << "Error" << endl;
		return false;
	}
	else
		return true;
}


void fadd()
{
	if (!flopen("ab+"))
		return;
	int i, n;
	cout << "Enter the number of products: ";
	cin >> n;
	cout << "--------------------------------" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "Vvedite nomer karti: "; cin >> karta.nomk;  getchar();
		cout << "Vvedite fio: "; gets_s(karta.fio, 50);
		cout << "Vvedite skidku: "; cin >> karta.skidka; cout << endl;
		fwrite(&karta, sizeof(Karts), 1, fl);
	}
	fclose(fl);
}

void frd()
{
	if (!flopen("rb"))
		return;
	n = _filelength(_fileno(fl)) / sizeof(Karts);
	list = new Karts[n];
	fread(list, sizeof(Karts), n, fl);
	for (int i = 0; i < n; i++)
		cout << endl << list[i].nomk << ": FIO - " << list[i].fio << ", Skidka - " << list[i].skidka;
	cout << endl;
	delete[]list;
	fclose(fl);
}

void rezc()
{
	if (!flopen("rb")) return;
	n = _filelength(_fileno(fl)) / sizeof(Karts);
	for (int i = 0; i < n; i++)
	{
		fread(&karta, sizeof(Karts), 1, fl);
		if (karta.skidka == 10)
			cout << karta.nomk << "   " << karta.fio << endl;
	}
	fclose(fl);
}

void rezf()
{
	char fnamet[20];
	cout << "Enter the name of the txt file" << endl;
	cin >> fnamet;
	FILE* ft;
	if (fopen_s(&ft, fnamet, "w"))
	{
		cout << "File not created!";
		return;
	}
	if (!flopen("rb")) return;
	n = _filelength(_fileno(fl)) / sizeof(Karts);
	for (int i = 0; i < n; i++)
	{
		fread(&karta, sizeof(Karts), 1, fl);
		if (karta.skidka == 10)
			fprintf(ft, "%d %s\n", karta.nomk, karta.fio);
	}
	fclose(ft);
	fclose(fl);
}

void spuz()
{
	if (!flopen("rb")) return;
	n = _filelength(_fileno(fl)) / sizeof(Karts);
	list = new Karts[n];
    int i, j, t;
	fread(list, sizeof(Karts), n, fl);
	for (i = 1; i < n; i++)
	{
		for (j = n - 1; j >= i; j--)
		{
			if (list[j - 1].nomk > list[j].nomk)
			{
				t = list[j - 1].nomk;
				list[j - 1].nomk = list[j].nomk;
				list[j].nomk = t;
			}

		}
	}
	delete[]list;
	fclose(fl);
}