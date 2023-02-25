#include <iostream>
#include <cstring>
using namespace std;

class String
{
	char* str;	//строка
	int length;	//длина строки
	
public:

	String()
	{
		str = nullptr;
	}
	String(char *str)
	{
		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';

	}
	~String()
	{
		delete[] this->str;
	}

	void Init(const char* inputStr)
	{
		length = strlen(inputStr);

		str = new char[100];
		strcpy_s(str, 6, inputStr);
	}

	void Concat(const char* inputStr)
	{
		length += strlen(inputStr);
		strcat_s(str, length, inputStr);
	}

	friend void Print(String &string)
	{
		cout << string.str << endl;
	}
};

int main()
{
	String firstString;

	const char* inputStr = "Privet";

	firstString.Init(inputStr);

	//inputStr = nullptr;

	firstString.Concat(inputStr);

	return 0;
}