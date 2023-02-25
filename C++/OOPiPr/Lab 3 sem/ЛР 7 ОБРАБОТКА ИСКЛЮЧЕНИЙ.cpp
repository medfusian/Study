#include <iostream>
#include <string>
using namespace std;


class MathException : public exception
{
protected:
	string op_name; //имя операции
	long val1; //значение левого операнда операции
	long val2; //значение правого операнда операции
public:
	MathException();
	MathException(string name_op, long v1, long v2) : op_name(name_op), val1(v1), val2(v2) {}
	virtual string Message() = 0;
};
//переполнение сверху
class OverflowException : MathException
{
public:
	OverflowException(string name_op, long v1, long v2) : MathException(name_op, v1, v2)
	{
		op_name = name_op;
		val1 = v1;
		val2 = v2;
	}
	string Message()
	{
		string out = "Значение " + op_name + " больше 100";
		return out;
	}
};
//переполнение сверху
class UnderflowException : public MathException
{
public:
	UnderflowException(string name_op, long v1, long v2) : MathException(name_op, v1, v2)
	{
		op_name = name_op;
		val1 = v1;
		val2 = v2;
	}
	string Message()
	{
		string out = "Значение " + op_name + " меньше 0";
		return out;
	}
};
//деление на 0
class ZdivideException : public MathException {
public:
	ZdivideException(string name_op, long v1, long v2) : MathException(name_op, v1, v2)
	{
		op_name = name_op;
		val1 = v1;
		val2 = v2;
	}
	string Message()
	{
		return "Деление на ноль";
	}
};


class Math
{
public:
	long Add(long a, long b); //сложение (a + b)
	long Sub(long a, long b); //вычитание (a - b)
	long Mul(long a, long b); //умножение (a * b)
	long Div(long a, long b); //деление (a / b)
	long Mod(long a, long b); //остаток от деления (a % b)
};

long Math::Add(long a, long b)
{
	if (a + b > 100) throw OverflowException("Sum", a, b);
	return a + b;
}
long Math::Sub(long a, long b)
{
	long result = a - b;
	if (result < 0) throw UnderflowException("Sub", a, b);
	return a - b;
}
long Math::Mul(long a, long b)
{
	long result = a * b;
	if (result > 100) throw OverflowException("Multy", a, b);
	return result;
}
long Math::Div(long a, long b)
{
	if (b == 0) throw ZdivideException("Divide", a, b);
	if (a / b > 100) throw OverflowException("Divide", a, b);
	return a / b;
}
long Math::Mod(long a, long b)
{
	if (b == 0) throw ZdivideException("Divide", a, b);
	return a % b;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Math a;

	try
	{
		cout << "Значение суммы: "<< a.Add(4, 8) << endl;
		cout << a.Add(56, 73);
	}
	catch (OverflowException& ex)
	{
		cout << ex.Message() << endl << endl;
	}

	try
	{
		cout << "Значение разности: " << a.Sub(13, 7) << endl;
		cout << a.Sub(2, 7);
	}
	catch (UnderflowException& ex)
	{
		cout << ex.Message() << endl << endl;
	}

	try
	{
		cout << "Значение произведения: " << a.Mul(6, 8) << endl;
		cout << a.Mul(62, 4);
	}
	catch (OverflowException& ex)
	{
		cout << ex.Message() << endl << endl;
	}

	try
	{
		cout << "Значение деления: " << a.Div(69, 3) << endl;
		cout << a.Div(204, 2);
	}
	catch (OverflowException& ex)
	{
		cout << ex.Message() << endl << endl;
	}
	catch (ZdivideException& ex)
	{
		cout << ex.Message() << endl << endl;
	}

	try
	{
		cout << "Значение остатка от деления:" << a.Mod(15, 7) << endl;
		cout << a.Mod(15, 0);
	}
	catch (ZdivideException& ex)
	{
		cout << ex.Message() << endl << endl;
	}

	return 0;
}	