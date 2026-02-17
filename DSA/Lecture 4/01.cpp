#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    for (int i = 0; i < n; i++) // outer
    {
        for (int j = 0; j < n; j++) // Inner
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}