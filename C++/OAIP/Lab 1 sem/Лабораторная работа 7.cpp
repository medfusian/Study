#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>
using namespace std;

struct strc
{
    char group[20];
    char mark[20];
    char data[12];
    char sost[12];
} mkvit[100];

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, i, j;
    bool w;
    char vibgroup[20];
    cout << "Введите количество квитанций: "; cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Введите наименование группы: ";
        cin >> mkvit[i].group;
        cout << "Введите марку: ";
        cin >> mkvit[i].mark;
        cout << "Введите дату приема: ";
        cin >> mkvit[i].data;
        cout << "Введите состояние: ";
        getchar();
        gets_s(mkvit[i].sost, 12);
        cout << endl;
    }

    cout << "Выберете группу: ";
    cin >> vibgroup;
    cout << setw(15) << "Марка" << setw(15) << "Дата приема" << setw(15) << "Состояние" << endl;
    for (i = 0; i < n; i++)
    {
        w = 1;
        for (j = 0; mkvit[i].group[j] != '\0' || vibgroup[j] != '\0'; j++)
            if (mkvit[i].group[j] != vibgroup[j])
                w = 0;
        if (w == 1 && mkvit[i].group[j] == '\0' && vibgroup[j] == '\0')
            cout << setw(15) << mkvit[i].mark << setw(15) << mkvit[i].data << setw(15) << mkvit[i].sost << endl;
    }
    return 0;
}