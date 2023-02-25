#include <iostream>
#include <stdarg.h>
using namespace std;

void MyPrintf(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    while (*format)
        switch (*format++)
        {
        case 'c': { char c = va_arg(ap, char);
            cout << c << " "; break; }
        case 's': { char* s = va_arg(ap, char*);
            cout << s << " "; break; }
        case 'd': { int d = va_arg(ap, int);
            cout << d << " "; break; }
        case 'f': { double f = va_arg(ap, double);
            cout << f << " "; break; }
        }
    va_end(ap);
}

int main()
{   
    MyPrintf("%d %c %f %s %f", 14, 's', 3.13, "print xaxa", 45.4); cout << endl;
    printf("%d %c %f %s %f", 14, 's', 3.13, "print xaxa", 45.4);
    return 0;
}