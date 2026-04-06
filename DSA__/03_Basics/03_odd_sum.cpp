#include <iostream>
using namespace std;
int main()
{
    int n{10};

    // Method 1 --->

    int odd_sum{};
    // cout << "Enter the value of n " << endl;
    // cin >> n;
    // for (int i = 1; i <= n; i += 2)
    // {
    //     odd_sum += i;
    // }
    // cout << "sum is :" << odd_sum;

    // Method 2 --->

    // print odd numbers
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            cout << i << " " << endl;
            odd_sum += i;
        }
    }
    cout << "odd_sum :" << odd_sum;

    return 0;
}