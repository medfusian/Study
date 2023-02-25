#include <iostream>
#include <fstream>
#include <cstdio>
#include <io.h>

using namespace std;
FILE* fl;

class TextFile
{

	int length;		//размер файла
	char* buff;		//буфер для текста
	char name[256]; //имя файла

public:

	TextFile(const char* nameFile)
	{
		for (int i = 0; i < strlen(nameFile); i++)
		{
			name[i] = nameFile[i];
		}
		name[strlen(nameFile)] = '\0';

		length = 0;
		buff = nullptr;
	}

	TextFile(const TextFile& obj)
	{
		if (this->buff != nullptr)
		{
			delete[] this->buff;
		}
		
		this->length = obj.length;

		for (int i = 0; i < strlen(obj.name); i++)
		{
			this->name[i] = obj.name[i];
		}
		this->name[strlen(obj.name)] = '\0';

		this->buff = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->buff[i] = obj.buff[i];
		}
		this->buff[length] = '\0';
	}

	TextFile()
	{
		length = 0;
		buff = nullptr;

		char nameFile[8] = "default";
		for (int i = 0; i < 8; i++)
		{
			name[i] = nameFile[i];
		}
	}

	~TextFile()
	{
		delete[] buff;
	}

	bool Open(const char* r)
	{

		if (fopen_s(&fl, name, r)) {

			cout << "Error" << endl;
			return false;
		}

		else {

			if (r != "w") {
				length = _filelength(_fileno(fl));

				buff = new char[length];

				fread(buff, 1, length, fl);

				buff[length] = '\0';

			}
			return true;
		}
	}

	void AddText(const char* str)
	{

		char* result = new char[length + strlen(str) + 1];

		for (int i = 0; i < length; i++)
		{
			result[i] = buff[i];
		}

		for (int j = 0; j < strlen(str); j++)
		{
			result[length + j] = str[j];
		}

		result[length + strlen(str)] = '\0';

		length += strlen(str);

		buff = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			buff[i] = result[i];
		}
		buff[length] = '\0';

		delete[] result;
	}

	void PasteText(const char* str, int index)
	{

		int razmer = strlen(str);

		length += razmer;

		char* result = new char[length + 1];

		for (int i = 0; i < index; i++)
		{
			result[i] = buff[i];
		}

		for (int i = index; i < index + razmer; i++)
		{
			result[i] = str[i - index];
		}

		for (int i = index + razmer; i < length; i++)
		{
			result[i] = buff[i - razmer];
		}

		buff = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			buff[i] = result[i];
		}
		buff[length] = '\0';

		delete[] result;
	}

	void Save()
	{
		fclose(fl);
		if (!Open("w")) return;
		fputs(buff, fl);
		fclose(fl);
	}

	void Print()
	{
		if (!Open("r")) return;
		cout << buff;
		fclose(fl);
	}

};

int main()
{
	setlocale(LC_ALL, "ru");

	char nameFile[256];
	cout << "Введите название файла: " << endl;
	cin >> nameFile;

	TextFile firstFile(nameFile);

	firstFile.Open("a+");
	firstFile.AddText("Hello");
	firstFile.AddText(" World ");

	firstFile.PasteText(" Punkt ", 2);

	TextFile secondFile(firstFile);

	secondFile.Save();
	secondFile.Print();
	secondFile.PasteText("Punkt", 2);

	return 0;
}