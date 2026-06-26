#include <iostream>
using namespace std;

int reverse(int x)
{
    long int rev = 0;

    while (x != 0)
    {
        int digit = x % 10;

        // Positive overflow
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
            return 0;

        // Negative overflow
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
            return 0;

        rev = rev * 10 + digit;
        x /= 10;
    }
    return rev;
}
int main()
{
    int rev = reverse(1534236469);
    cout << rev;
    return 0;
}