#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char str[200];
    cout << "Vvedite stroky: ";
    gets_s(str, 200);
    int r = strlen(str), i, min, j, k, mink;
    i = mink = 0; k = 1; min = r;
    while (i < r)
    {
        j = 0;
        while (str[i] != ' ' && i != r) { j++; i++; }
        if (j < min && j != 0) { min = j; mink = k; }
        if (j != 0) k++;
        i++;
    }
    cout << "Porad nom sl: " << mink << "\tKolvo simv: " << min;
    return 0;
}