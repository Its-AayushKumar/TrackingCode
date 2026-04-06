#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;

    void setPersonDetails()
    {
        cout << "Enter name :" << endl;
        cin >> name;
    }
    void displayPersonDetails()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
    }
};

class Bank
{
protected:
    double balance;

    void deposit()
    {
        double dpt;
        cout << "Enter amount you want to deposit:" << endl;
        cin >> dpt;
        if (dpt > 0)
        {
            balance += dpt;
        }
        cout << "New balance :" << balance << endl;
    }

    void withdraw()
    {
        double wtd;
        cout << " Enter amount you want to withdraw:" << endl;
        cin >> wtd;
    }
};
int main()
{

    return 0;
}