#include <iostream>
using namespace std;

int main()
{
    int n = 232342424;
    bool isprime = true;

    for (int i = 2; i * i <= n; i++) // here we are doing i*i <= n so we do not get the repeated factors
    {
        if (n % i == 0)
        {
            isprime = false;
            break;
        }
    }

    if (isprime == true)
    {
        cout << "prime no." << endl;
    }
    else
    {
        cout << "non prime";
    }

    return 0;
}