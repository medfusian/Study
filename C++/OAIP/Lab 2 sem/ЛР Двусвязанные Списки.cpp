#include <iostream>

using namespace std;

struct node {
    char inf;
    node* next;
    node* prev;
}*tmp = nullptr, *Head = nullptr, *Tail = nullptr;

void show(node* tm, node* Head)
{
	tm = Head;
	while (tm != nullptr) {
		cout << tm->inf << " ";
		tm = tm->next;
	}
	cout << "\n";
}

void fill_list(int *n)
{
    char sim;
    for (int i = 0; i < *n; i++) {
        tmp = new node;
        cout << "Vvedite znach " << i + 1 << "-go elementa: "; cin >> sim;
        tmp->inf = sim;
        tmp->next = nullptr;
        if (Head != nullptr) {
            tmp->prev = Tail;
            Tail->next = tmp;
            Tail = tmp;
        }
        else {
            tmp->prev = nullptr;
            Head = Tail = tmp;
        }
    }
	show(tmp, Head);
}

void delete_list(node *tm, node* Head, node* Tail)
{
	node* t; tm = Head;
	while (tm != nullptr) {
		t = tm;
		tm = tm->next;
		delete t;
	}
	Head = Tail = nullptr;
}

void preob()
{
	node* tms, * Tails, * Heads;
	node* tmb, * Tailb, * Headb;
	tms = Heads = Tails = tmb = Headb = Tailb = nullptr;
	tmp = Head;
	while (tmp != nullptr) {
		if (tmp->inf > 96 && tmp->inf < 123)
		{
			tms = new node;
			tms->inf = tmp->inf;
			tms->next = nullptr;
			if (Heads != nullptr) {
				tms->prev = Tails;
				Tails->next = tms;
				Tails = tms;
			}
			else {
				tms->prev = nullptr;
				Heads = Tails = tms;
			}
		}
		else if (tmp->inf > 64 && tmp->inf < 91)
		{
			tmb = new node;
			tmb->inf = tmp->inf;
			tmb->next = nullptr;
			if (Headb != nullptr) {
				tmb->prev = Tailb;
				Tailb->next = tmb;
				Tailb = tmb;
			}
			else {
				tmb->prev = nullptr;
				Headb = Tailb = tmb;
			}
		}
		tmp = tmp->next;
	}
	show(tms, Heads);
	show(tmb, Headb);
	delete_list(tms, Heads, Tails);
	delete_list(tmb, Headb, Tailb);
}

int main()
{
    int n;
    cout << "Vvedite kolichestvo elementov: "; cin >> n;
    fill_list(&n);
	preob();
	delete_list(tmp, Head, Tail);
    return 0;
}