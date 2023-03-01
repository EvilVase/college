#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

struct Element
{

	char data;
	Element* Next;

};


class List
{
	Element* Head;
	Element* Tail;
	int count;
public:
	List();
	~List();
	void Add(char _data);
	void Del();
	void DelAll();
	void Print();
	int GetCount();

};
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	List l1;
	char s[] = "Hello, World!!!!\n";
	int size = strlen(s);
	for (int i = 0; i < size; i++)
	l1.Add(s[i]);
	l1.Print();
	cout << "*****************************************" << endl;
	l1.Del();
	l1.Del();
	l1.Del();
	cout << "*****************************************" << endl;
	l1.Print();

}

List::List()
{
	Head = Tail = NULL;
	count = 0;
}

List::~List()
{
	DelAll();
}

void List::Add(char _data)
{
	Element* tmp = new Element;
	tmp->data = _data;
	tmp->Next = NULL;
	if (Head != NULL)
	{
		Tail->Next = tmp;
		Tail = tmp;
	}
	else
	{
		Head = Tail = tmp;
	}
	count++;
}

void List::Del()
{
	Element* tmp = Head;
	Head = Head->Next;
	delete tmp;
	count--;
}

void List::DelAll()
{
	while (Head!=0)
	{
		Del();
	}

}

void List::Print()
{
	Element * tmp = Head;
	while (tmp!=0)
	{
		cout << tmp->data << " ";
		tmp = tmp->Next;
	}
	cout << "\n\n";
}

int List::GetCount()
{
	return count;
}
