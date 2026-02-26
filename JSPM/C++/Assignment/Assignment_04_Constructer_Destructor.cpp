#include <iostream>
using namespace std;

class car
{
public:
    string brand;
    int year;

    car()
    {
        brand = "Tata";
        year = 2006;
        cout << "Inside default constructer." << endl;
    }
    car(string name, int year1)
    {
        brand = name;
        year = year1;
        cout << "Inside parameterized constructer." << endl;
    }
    car(string name, int year2, int year3)
    {
        brand = name;
        year = year3;
        cout << "Inside copy constructer." << endl;
    }
    void display()
    {
        cout << "Brand:" << brand << endl;
        cout << "Year:" << year << endl;
    }
    ~car()
    {
        cout << "Object Destructed !!" << brand << endl;
    }
};

int main()
{
    car cobj1;
    cobj1.display();
    car cobj2("bmw", 93393);
    cobj2.display();
    return 0;
}