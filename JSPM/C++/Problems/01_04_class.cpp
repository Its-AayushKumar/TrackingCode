#include <iostream>
using namespace std;

class sum
{

public:
    int a, b;
    void setdata()
    {
        a = 10;
        b = 20;
    }
    void display()
    {
        int sum;
        sum = a + b;
        cout << sum << endl;
    }
};

int main()
{
    sum sobj;
    sobj.setdata();
    sobj.display();

    cout << "a" << sobj.a << endl;
    cout << "b" << sobj.b << endl;

    return 0;
}