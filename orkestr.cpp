#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <cctype>
#include <algorithm>
#include <vector>


using namespace std;

class instrumenti 
{
public:
    string Title;
    instrumenti (string t)
    {
        Title = t;
    }
    virtual void speak() = 0;
};
class Strun : public instrumenti
{
public:
    Strun(string Title) : instrumenti(Title) {};
    virtual void speak()
    {
        cout << Title << " say " << "\'kwa-kwa\'\n";
    }
};

class Duhovie : public instrumenti
{
public:
    Duhovie(string Title) : instrumenti(Title) {};
    virtual void speak() 
    {
        cout << Title << " say " << "\'myau-myau\'\n";
    }
};





//струнные 
class Balalaika : public Strun
{
public:
    Balalaika(string Title) : Strun(Title) {};
    virtual void speak()
    {
    cout<<Title<<" играет "<<"\'rrr-rrr\'\n";
    }
};

class Bassguitara : public Strun
{
public:
    Bassguitara(string Title) : Strun(Title) {};
    virtual void speak()
    {
        cout << Title << " say " << "\'rrr-rrr\'\n";
    }

};

class Skripka : public Strun
{
public:
    Skripka(string Title) : Strun(Title) {};
    virtual void speak()
    {
        cout << Title << " say " << "\'rrr-rrr\'\n";
    }

};

//Духовые
class Sopilka : public Duhovie
{
public:
    Sopilka(string Title) : Duhovie(Title) {};
    virtual void speak()
    {
        cout << Title << " играет " << "\'rrr-rrr\'\n";
    }
};

class Saxofon : public Duhovie
{
public:
    Saxofon(string Title) : Duhovie(Title) {};
    virtual void speak()
    {
        cout << Title << " играет " << "\'rrr-rrr\'\n";
    }
};

class Truba : public Duhovie
{
public:
    Truba(string Title) : Duhovie(Title) {};
    virtual void speak()
    {
        cout << Title << " igraet " << "\'rrr-rrr\'\n";
    }
};

class Orkestr : public instrumenti, Strun, Duhovie, Balalaika, Bassguitara, Skripka, Sopilka, Saxofon, Truba
{
public:
   int name;
   int obj;
   int timer;

    ~Orkestr;
    int GetName;
    int GetTimer;
    int Orkestr;
    virtual void Speak()
    {

    }


};











void main()
{

    instrumenti* instrumenti[3] =
    { 
        new Strun ("Bob"),
        new Duhovie("Murka"),
        new Balalaika("Balalaika igraet") 
    };
    for (int k = 0; k < 4; k++)
    {
        instrumenti[k]->speak();
        
    }
    
}