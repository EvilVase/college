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
	Element* next;
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
	void AddIndex(char _data, int idx);
	void DelIndex(int idx);
};


void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	List l1;
	char s[] = "Hello, World!!!";
	int size = strlen(s);
	
	for (size_t i = 0; i < size; i++)
	{
		l1.Add(s[i]);
	}
	l1.Print();
	cout << "\n******************************************\n";
	l1.AddIndex('#', 9);
	l1.AddIndex('#', 7);
	l1.AddIndex('#', 2);
	l1.Print();
	cout << "\n******************************************\n";
	l1.DelIndex(2);
	l1.DelIndex(7);
	l1.DelIndex(9);
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
	tmp->next = NULL;
	if (Head != NULL)
	{
		Tail->next = tmp;
		Tail = tmp;
	}
	else Head = Tail = tmp;
	count++;

}

void List::Del()
{
	Element* tmp = Head;
	Head = Head->next;
	delete tmp;
	count--;
}

void List::DelAll()
{
	while (Head != NULL)
	{
		Del();
	}
}

void List::Print()
{
	Element* tmp = Head;
	while (tmp != NULL)
	{
		cout << tmp->data;
		tmp = tmp->next;
	}
}

int List::GetCount()
{
	return count;
}

void List::AddIndex(char _data, int index)
{
	Element* data_tmp = new Element;
	data_tmp->data = _data;
	Element* tmp = Head;
	tmp->next = Head->next;

	if (Head != NULL)
	{
		for (int i = 1; i < index - 1; i++)
		{
			tmp = tmp->next;
		}
		data_tmp->next = tmp->next;
		tmp->next = data_tmp;
		count++;

	}

}

void List::DelIndex(int index)
{
	Element* tmp_first = Head;
	Element* tmp_second = Head;
	tmp_first->next = Head->next;
	tmp_second->next = Head->next;
	if (Head != NULL)
	{
		for (int i = 1; i < index; i++)
		{
			tmp_first = tmp_first->next;
			if (i != 1) tmp_second = tmp_second->next;
		}
		tmp_second->next = tmp_first->next;
		count--;
	}
}
