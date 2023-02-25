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
		
		this->length = obj.length;		// длина

		for (int i = 0; i < strlen(obj.name); i++)	// имя
		{
			this->name[i] = obj.name[i];
		}
		this->name[strlen(obj.name)] = '\0';

		this->buff = new char[length + 1];	// буфер

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
		if (buff != nullptr)
		{
			delete[] this->buff;
		}
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

				if (this->buff != nullptr)
				{
					delete[] this->buff;
				}

				this->buff = new char[length];

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
		cout << buff;
	}

	void PrintFile()
	{
		cout << buff << endl;
		cout << name << endl;
		cout << length << endl;
	}


	TextFile& operator=(const TextFile& obj)//копирование файла
	{
		this->length = obj.length;
		if (this->buff != nullptr) 
		{
			delete[] this->buff;
		}

		int n = strlen(obj.buff);
		this->buff = new char[n];
		strcpy(this->buff, obj.buff);

		memset(this->name, 0, sizeof(this->name));
		
		strcpy(this->name, obj.name);
		
		return *this;
	}

	TextFile& operator=(const char* str)//копирование текста
	{
		if (this->buff != nullptr)
		{
			delete[] this->buff;
		}

		this->buff = new char[strlen(str) + 1];

		for (int i = 0; i < strlen(str); i++)
		{
			this->buff[i] = str[i];
		}
		buff[strlen(str)] = '\0';

		strcpy(this->name, this->name);

		this->length = strlen(str);

		return *this;
	}
	
	TextFile& operator+=(const TextFile& obj)//добавить файл
	{
		strcat(this->buff, obj.buff);

		this->length += obj.length;
		
		return *this;
	}
	
	TextFile& operator+=(const char* str)//добавить текст
	{
		strcat(this->buff, str);
		return *this;

	}
	
	friend ostream& operator<<(ostream& os, TextFile& );//
	friend istream& operator>>(istream& is, TextFile& );//

};

ostream& operator<<(ostream& os, TextFile& obj) {
	
	if ((fl = fopen(obj.name, "r")) == NULL)
	{
		if ((fl = fopen(obj.name, "w+")) == NULL) {
			cout << "Ошибка при создании" << endl;
			exit(1);
		}
	}
	
	int i = 0;
	
	obj.length = _filelength(_fileno(fl)) / sizeof(char);
	
	rewind(fl);
	
	if (obj.buff != nullptr) 
	{
		memset(obj.name, 0, sizeof(obj.name));
	}
	
	obj.buff = new char[obj.length];
	memset(obj.buff, 0, sizeof(obj.buff));
	
	while ((obj.buff[i] = fgetc(fl)) != EOF) {
		if (obj.buff[i] == '\n') {
			obj.buff[i] = '\0';
			i++;
		}
		else i++;
	}
	
	obj.buff[i] = '\0';
	os << obj.buff << endl;
	fclose(fl);
	return os;
}

istream& operator>>(istream& is, TextFile& obj) {
	if ((fl = fopen(obj.name, "a")) == NULL)
	{
		cout << "Ошибка при открытии" << endl;
		exit(1);
	}
	
	//if (obj.buff != nullptr)
	//{
	//	memset(obj.buff, 0, sizeof(obj.name));
	//}

	if (obj.buff != nullptr)
	{
		delete[] obj.buff;
	}
	
	obj.buff = new char[20];
	is >> obj.buff;
	
	fprintf(fl, "%s", obj.buff);
	fclose(fl);
	return is;
}


int main()
{
	setlocale(LC_ALL, "ru");

	char nameFile[256];
	cout << "Введите название файла: " << endl;
	cin >> nameFile;

	TextFile firstFile(nameFile);

	firstFile.Open("a+");
	firstFile.AddText("Hello");
	//firstFile.AddText(" World ");

	//firstFile.PasteText(" Punkt ", 2);

	TextFile secondFile(firstFile);

	secondFile.AddText(" Second");
	secondFile.Save();
	secondFile.Print();

	cout << endl << "----------------" << endl;

	TextFile rezult = firstFile;
	rezult.PrintFile();

	cout << "-------------------" << endl;

	rezult = "string";

	rezult.PrintFile();

	cout << "................" << endl;

	firstFile += rezult;

	firstFile.PrintFile();

	cout << ".............." << endl;

	//cout << secondFile;
	cout << endl;
	cin >> secondFile;
	cout << secondFile;
	return 0;
}