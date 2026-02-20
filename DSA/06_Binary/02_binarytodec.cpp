// Binary to decimal
// Example ---> 101010 so here raise the power of 2 to the place like once than power 0 tens then power 1
// And multiply 1 or 0 and add the result
//  32+0+8+0+2 = 42

#include <iostream>
using namespace std;

int binToDecimal(int binNum)
{
    int ans = 0, pow = 1;

    while (binNum > 0)
    {
        int rem = binNum % 10;
        ans += rem * pow;
        binNum /= 10;
        pow *= 2;
    }
    return ans; // Decimal form
}
int main()
{
    cout << binToDecimal(1001) << endl;
    return 0;
}