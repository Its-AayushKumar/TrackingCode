#include <iostream>
using namespace std;

// Functions are set of code which performs something for you
// Functions are used to modularise code
// Functions are used to increase readability
// Functions are used to use same code multiple times

// void -> which does not return anything
// return
// parameterized
// non parameterized

void printName(string name)
{
    cout << "Hello " << name << endl;
}


int main()
{
    printName("Panda");
    return 0;
}