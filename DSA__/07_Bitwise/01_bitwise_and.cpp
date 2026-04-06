#include <iostream>
using namespace std;

int main()
{
    int a = 4, b = 8;
    cout << (a & b) << endl; // bitwise and
    cout << (a | b) << endl; // bitwise or

    // XOR
    // 0^0 = 0 , 1^1= 0 ,0^1=1,1^0=1
    cout << (a ^ b) << endl;

    // Left shift
    cout << (10 << 1) << endl;
    // 10 ---> 1010 when (10<<1) ---> 10100 (20)
    // a<<b then ans will be a*2^b

    // Right shift
    cout << (10 >> 1) << endl;
    // 10 ---> 1010 when (10>>1) ---> 0101 (5)
    // a>>b then ans will be a/2^b
    return 0;
}