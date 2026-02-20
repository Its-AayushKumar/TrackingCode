#include <iostream>
using namespace std;

// Sum 2 number
int sum(int a, int b)// Parameters
{
    int s = a + b;
    return s;
}
int main()
{
    cout << sum(10, 5) << endl; // arguments
    return 0;
}