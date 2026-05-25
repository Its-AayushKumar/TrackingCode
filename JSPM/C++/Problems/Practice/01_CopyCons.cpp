#include <iostream>
using namespace std;

class test
{

    int a, b;

public:
    test()
    {
        a = 10;
        b = 20;
    }

    test(test &obj)
    {
        a = obj.a;
        b = obj.b;
    }

    void display()
    {
        cout << "a :" << a << endl;
        cout << "b :" << b << endl;
    }
};

int main()
{
    test tobj1;
    test tobj2(tobj1);
    tobj1.display();
    tobj2.display();
    test tobj3;
    tobj3 = tobj1;
    tobj3.display();
    return 0;
}