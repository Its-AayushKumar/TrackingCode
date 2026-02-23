#include <iostream>
using namespace std;

int main()
{
    int n{};
    cout << "Enter value for n" << endl;
    cin >> n;

    if (n <= 0)
    {
        cout << "n is not a power of 2" << endl;
        return 0; // stop program early
    }

    int temp = n; // preserve original value

    while (temp > 1 && temp % 2 == 0)
    {
        temp /= 2;
    }

    if (temp == 1)
        cout << n << " is a power of 2" << endl;
    else
        cout << n << " is not a power of 2" << endl;

    return 0;
}