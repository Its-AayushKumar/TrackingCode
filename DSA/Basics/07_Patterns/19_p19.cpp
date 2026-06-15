// 5
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********

#include <iostream>
using namespace std;

void pattern(int n)
{
    int spc = 0;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < spc; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        spc += 2;
        cout << endl;
    }

    spc = 8;
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < spc; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        spc -= 2;
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    pattern(n);
    return 0;
}