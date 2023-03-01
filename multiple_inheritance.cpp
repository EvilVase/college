#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <stack>
#include <string.h>



using namespace std;

////Protected позволяет наследнику работать с полями класса 
//
//class A
//{
//protected:
//	int a;
//	
//public:
//	char ch;
//	A() 
//	{ 
//		ch='A';
//		a = 0; 
//		cout << "construct A" << endl; 
//	}
//	A(int _a)
//	{
//		a = _a;
//		cout << "int a = " << a << endl;
//
//	}
//	~A() 
//	{
//		a = 0; cout << "destruct A" << endl; 
//	}
//	void f() 
//	{ 
//		cout << "A:: Fa()" << endl; 
//	}
//};
//
//class B: public A
//{
//protected:
//	int b;
//	
//public:
//	//char ch;
//	B() 
//	{ 
//		ch = 'B';
//		b = 0; 
//		cout << "construct B" << endl; 
//	}
//	B(int _a, int _b) : A(_a)
//	{
//		b = _b;
//		cout << "int b = " << b << endl;
//
//	}
//	~B() { b = 0; cout << "destruct B" << endl; }
//	void f() { cout << "B:: Fb()" << endl; }
//};
//class C : public B
//{
//protected:
//	int c;
//public:
//	//char ch;
//	C() 
//	{ 
//		//ch = 'C';
//		c = 0; 
//		cout << "construct C" << endl;
//	}
//	C(int _a, int _b, int _c) : B(_a, _b)
//	{
//		c = _c;
//		cout << a << " " << b << " " << c << endl;
//
//
//	}
//	~C() 
//	{
//		c = 0; cout << "destruct C" << endl; 
//	}
//	void f() 
//	{
//		cout << "C:: fc()" << endl;
//		cout << a << " " << b << endl;
//	}
//};
//
//int main()
//{
//	//C c(1, 2, 3);
//	//c.fa();
//	//c.fb();
//	//c.fc();
//	C cc;
//	cc.f();
//}
//

#include <iostream>
#include <string.h>
using namespace std;
//РљР»Р°СЃСЃ "СЂРѕРіР°"
class Roga
{
protected:
	char color[25];
	int wes;
public:
	Roga()
	{
		strcpy(color, "Dirty");
		wes = 20;
	}
	Roga(const char* c, int w)
	{
		strcpy(color, c);
		wes = w;
	}
};
//РљР»Р°СЃСЃ "РєРѕРїС‹С‚Р°"
class Kopyta
{
protected:
	char forma[25];
	int razmer;
public:
	Kopyta()
	{
		strcpy(forma, "Big");
		razmer = 10;
	}
	Kopyta(const char* c, int w)
	{
		strcpy(forma, c);
		razmer = w;
	}
};

class Los :public Roga, public Kopyta
{
public:
	char name[255];
	Los(const char* c)
	{
		strcpy(name, c);
	}

	void Input()
	{


	}
	void DisplayInfo()
	{
		cout << "Name " << name << "\n";
		cout << "Forma " << forma << "\n";
		cout << "Color " << color << "\n";
		cout << "Wes rogov " << wes << "\n";
		cout << "Razmer kopyt " << razmer << "\n";
	}
};
void main()
{

	Los l("Pupsik");
	l.DisplayInfo();
}