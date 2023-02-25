#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    vector<int> mass;
    int sizeMass;

    cout << "Введите количество символов: ";
    cin >> sizeMass;
    mass.reserve(sizeMass);

    srand(time(NULL));
    for (int i = 0; i < sizeMass; i++)
    {
        mass.push_back(rand() % 100 - 50);
    }

    cout << endl << "Массив: ";
    for (int i = 0; i < mass.size(); i++)
    {
        cout << "\t" << mass[i];
    }
    cout << endl << endl;

    int result = 0, n;
    for (int i = 0; i < mass.size(); i += 2)
    {
        if (mass[i] > 0)
        {
            result = mass[i];
            n = i;
            break;
        }
    }
    if (result == 0)
    {
        cout << "Нет положительного числа с четным индексом массива" << endl;
        return 0;
    }
    for (int i = 0; i < mass.size(); i += 2)
    {
        if (mass[i] > 0 && mass[i] < result) result = mass[i];
    }

    cout << "Наименьшее положительное с четным индексом массива: ";
    cout << result << endl;

    return 0;
}