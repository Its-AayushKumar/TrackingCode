#include <iostream>
using namespace std;

int printPrime(int n)
{
    // bool isprime = true;
    for (int i = 2; i <= n; i++)
    {
        if (n % i != 0)
        {
            cout << i << endl;
        }
    }
    return printPrime(n);
}

int main()
{
    int n{};
    cout << "Enter a number :" << endl;
    cin >> n;
    cout << printPrime(n) << endl;

    return 0;
}