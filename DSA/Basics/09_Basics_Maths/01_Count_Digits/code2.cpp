#include <iostream>
#include <math.h>
using namespace std;

void count(int n)
{
    int cnt = int(log10(n) + 1);
    cout << cnt;
}
int main()
{
    count(243);

    return 0;
}