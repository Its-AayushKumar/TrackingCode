#include<iostream>
using namespace std;

int countDigit(int n)
{
    int count = 0;
    while (n > 0)
    {
     
        n = n / 10;
        count += 1;
    }
    cout<<count;
return 0;
}
int main()
{
    countDigit(43);
   
    return 0;
}