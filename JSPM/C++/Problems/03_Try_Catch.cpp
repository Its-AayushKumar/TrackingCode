#include <iostream>
using namespace std;

int main()
{
    int age{};
    cout << "Enter age:";
    cin >> age;

    try
    {
        if (age > 18)
        {
            cout << "Access granted!!";
        }
        else
        {
            throw age;
        }
    }
    catch (int a)
    {
        cout << "Access denied!!  ^_~ ";
        cout << "The age is" << a << " ->Below 18";
    }

    return 0;
}