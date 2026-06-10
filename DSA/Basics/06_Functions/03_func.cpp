#include <iostream>
using namespace std;

// pass by reference
void dosomething(string &s)
{
    s[0] = 't';
    cout << s << endl;
}


int main()
{
    string s = "raj";
    dosomething(s);
    cout << s << endl;

    return 0;
}