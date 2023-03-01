#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <stack>
#include <string.h>
// using static System.Console;

//Writeline($"");

using namespace std;

class Human
{
protected:
	string FName;
	string LName;
	int age;
public:
	static int i;
	Human() { cout << "construct Human def i= "<< ++i << endl; }
	Human(string _fname, string _lname, int _age)
	{
		cout << "construct Human param" << endl;
		FName = _fname;
		LName = _lname;
		age = _age;
	}
	~Human()
	{
		cout << "destruct Human def" << i << endl;
	}
	void Print()
	{
		cout << FName << " " << LName << " " << age << endl;
	}
};

int Human::i = 0;
class Student: public Human
{
	double avg_ball;
	string Group;
public:
	static int j;
	Student() { cout << "construct Student def j=" << ++j << endl; }
	Student(string _fname, string _lname, int _age, double _avg_ball, string _group): Human (_fname, _lname, _age)
	{
		cout << "construct Student param" << endl;
		avg_ball = _avg_ball;
		Group = _group;
	}
	~Student()
	{
		cout << "destruct Student def" << --j << endl;
	}
	void Print()
	{
		Human::Print();
		cout << avg_ball << " " << Group << endl;
	}

};
int Student::j = 0;
void main()
{
	srand(time(NULL));
	/*Human h1("Alex", "Sharov", 100);
	h1.Print();
	cout << "------------------------------------------------" << endl;
	Human h2;
	h2.Print();
	cout << "------------------------------------------------" << endl;*/
	/*Student st1("Alex_st", "Sharov_st", 50, 9.9, "RPO_11_1");
	st1.Print();
	cout << "------------------------------------------------" << endl;*/
	/*Student st2;
	st2.Print();
	cout << "------------------------------------------------" << endl;*/
	Student st2;
	{Student st3; }
	Student st4;
	//st2.Print();
}