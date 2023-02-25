#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Vvedite kolichestvo strok: "; cin >> n;
    cout << "Vvedite kolichestvo stolbcov: "; cin >> m;
    int** arr = new int* [n];                            //Создание исходного массива
    for (int i = 0; i < n; i++) arr[i] = new int[m];

    for (int i = 0; i < n; i++)                          //Заполнение исходного массива
        for (int j = 0; j < m; j++)
        {
            cout << "Vvedite arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }

    int max = arr[0][0];                                 //Определение элемента с мах значением
    int imax, jmax;
    imax = jmax = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] > max) { max = arr[i][j]; imax = i; jmax = j; }
 
    for (int i = 0; i < n; i++)                          //Вывод исходного массива
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    cout << "Znachenie max elementa: " << max << endl;   //Вывод значение мах элемента

    int** arr2 = new int* [n - 1];                       //Создание нового массива
    for (int i = 0; i < n - 1; i++) arr2[i] = new int[m-1];
        
    for (int i = 0, k = 0; i < n; i++, k++)              //Заполнение нового массива
    {
        if (i == imax) k--;
        for (int j = 0, l = 0; j < m; j++, l++)
        {
            if (j == jmax) l--;
            if (i != imax && j != jmax) arr2[k][l] = arr[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++)                      //Вывод конечного массива
    {
        for (int j = 0; j < m - 1; j++)
            cout << arr2[i][j] << "\t";
        cout << endl;
    }

    for (int i = 0; i < n; i++) delete[] arr[i];         //Чистка
    delete[] arr;
    arr = nullptr;
    for (int i = 0; i < n - 1; i++) delete[] arr2[i];
    delete[] arr2;
    arr2 = nullptr;

    return 0;
}