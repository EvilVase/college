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
	Element* Prev;

};


class List
{
	Element* Head;
	Element* Tail;
	int count;
public:
	List();
	~List();
	void AddHead(char _data);
	void AddTail(char _data);
	void Insert(int pos=0);
	void Del(int pos=0);
	void DelAll();
	void Print();
	int GetCount();
	// перегруженные опретаоры: == != > <
};
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	List l1;
	int size = 10;
	char s[] = "ABCDEFGHIJ";

	cout << s << "\n\n";
	cout << "*****************************************" << endl;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			l1.AddHead(s[i]);
		else l1.AddTail(s[i]);
	}

	l1.Print();
	cout << "*****************************************" << endl;
	l1.Del(5);
	l1.Print();
	cout << "*****************************************" << endl;
	l1.Insert();
	l1.Print();
	cout << "*****************************************" << endl;




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

void List::AddHead(char _data)
{
	Element* tmp = new Element;
	tmp->Prev = 0;
	tmp->data = _data;
	tmp->Next = Head;
	if (Head != 0)
		Head->Prev = tmp;
	if (count == 0) Head = Tail = tmp;
	else Head = tmp;
	count++;
}

void List::AddTail(char _data)
{
	Element* tmp = new Element;
	tmp->Next = 0;
	tmp->data = _data;
	tmp->Prev = Tail;
	if (Tail != 0)
		Tail->Next = tmp;
	if (count == 0)
		Head = Tail = tmp;
	else
		Tail = tmp;
	count++;
}

void List::Insert(int pos)
{
	char _data = (char)(rand() % 23 + 65);
	if (pos == 0)
	{
		cout << "Input position" << endl;
		cin >> pos;
	}
	if (pos<1 || pos>count + 1)
	{
		cout << "Error" << endl;
		return;
	}
	if (pos == count + 1)
	{
		AddTail(_data);
		return;
	}
	else if (pos == 1)
	{
		AddHead(_data);
		return;
	}
	int i = 1;
	Element* Ins = Head;
	while (i < pos)
	{
		Ins = Ins->Next;
		i++;
	}
	Element* PrevIns = Ins->Prev;
	Element* tmp = new Element;
	tmp->data = _data;
	if (PrevIns != 0 && count != 1)
		PrevIns->Next = tmp; //
	tmp->Next = Ins; // крест
	tmp->Prev = PrevIns; // на крест
	Ins->Prev = tmp; //
	count++;
}

void List::Del(int pos)
{
	if (pos == 0)
	{
		cout << "Input position" << endl;
		cin >> pos;
	}
	if (pos<1 || pos>count + 1)
	{
		cout << "Error" << endl;
		return;
	}
	int i = 1;
	Element* Del = Head;
	while (i < pos)
	{
		Del = Del->Next;
		i++;
	}
	Element* PrevDel = Del->Prev;
	Element* AfterDel = Del->Next;
	if (PrevDel != 0 && count != 1)
		PrevDel->Next = AfterDel;
	if (AfterDel != 0 && count != 1)
		AfterDel->Prev = PrevDel;
	if (pos == 1)
		Head = AfterDel;
	if (pos == count)
		Tail = PrevDel;
	delete Del;
	count--;
}

void List::DelAll()
{
	while (count != 0)
	{
		Del(1);
	}
}

void List::Print()
{
	Element* tmp = Head;
	while (tmp != 0)
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
