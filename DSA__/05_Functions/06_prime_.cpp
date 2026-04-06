#include <iostream>
using namespace std;

void prime(int n)
{
    bool isprime = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            isprime = false;
            break;
        }
    }
    if (isprime)
    {
        cout << n << " is a prime number." << endl;
    }
    else
    {
        cout << n << " is not prime." << endl;
    }
}

int main()
{
    int n{};
    cout << "Enter a number to check whether a number is prime or not " << endl;
    cin >> n;
    prime(n);

    return 0;
}