#include <iostream>
#include <string>
using namespace std;


template <class T>
struct ListItem
{
	T data;				//указатель на данные
	ListItem<T>* next;	//указатель на следующий элемент
};

template <class T>
class List
{
	ListItem<T>* list;

public:
	List()
	{
		list = nullptr;
	}

	~List()
	{
		delete list;
	}

	void ToList(T value)
	{
		ListItem<T>* temp;

		if (list == nullptr)
		{
			list = new ListItem<T>;
			list->data = value;
			list->next = nullptr;
		}
		else
		{
			temp = list;

			while (temp->next != nullptr)
				temp = temp->next;

			temp->next = new ListItem<T>;
			temp->next->data = value;
			temp->next->next = nullptr;
		}
	}

	void showList()
	{
		ListItem<T>* temp;

		temp = list;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	int count;

	cout << "Введите количество чисел: ";
	cin >> count;

	List<int> list1;

	int number;

	for (int i = 0; i < count; i++)
	{
		cout << "Введите число: ";
		cin >> number;

		list1.ToList(number);
	}

	cout << "\nВывод списка: " << endl;
	list1.showList();

	cout << "------------------------------\n\n";

	cout << "Введите количество символов: ";
	cin >> count;
	
	List<char> list2;

	char symbol;

	for (int i = 0; i < count; i++)
	{
		cout << "Введите символ: ";
		cin >> symbol;

		list2.ToList(symbol);
	}

	cout << "\nВывод списка: " << endl;
	list2.showList();

	cout << "------------------------------\n";

	return 0;
}