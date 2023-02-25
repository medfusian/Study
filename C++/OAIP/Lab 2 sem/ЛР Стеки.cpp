#include <iostream>

using namespace std;

struct node {
	int info;
	node* next;
} *t;

node* instack(node* p, int inf)
{
	node* t = new node;
	t->info = inf;
	t->next = p;
	return t;
}

void view(node* p)
{
	node* t = p;
	while (t != nullptr) {
		cout << t->info << "   ";
		t = t->next;
	}
}

node* outstack(node* p, int* out)
{
	node* t = p;
	*out = p->info;
	cout << p->info << endl;
	p = p->next;
	delete t;
	return p;
}

void delete_all(node** p)
{
	node* t;
	while (*p != nullptr) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

int main() {
	int n, inf;
	cout << "Vvedite kolichestvo chisel: "; cin >> n; cout << endl;
	int* a = new int[n];
	cout << "Vvedite chisla: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> inf;
		a[i] = inf;
		t = instack(t, inf);
	}
	view(t);
	if (t != nullptr)
		delete_all(&t);
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0 && a[i] < 10)
		{
			t = instack(t, a[i]);
		}
	}
	cout << endl;
	cout << "Noviy steck:" << endl;
	view(t);
	delete[]a;
	delete_all(&t);
	return 0;
}