#include <iostream>
using namespace std;

int main()
{

    int n{};
    cout << "Emter value of n :" << endl;
    cin >> n;
    int sum{};
    for (size_t i = 0; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            sum += i;
        }
    }
    cout << "sum of n numbers divisilble by 3 is :" << sum << endl;
    return 0;
}