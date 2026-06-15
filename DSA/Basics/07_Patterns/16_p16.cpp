// 5
// A 
// B B 
// C C C 
// D D D D 
// E E E E E 
// F F F F F F 

#include <iostream>
using namespace std;

void pattern(int n)
{

    for (int i = 0; i <= n; i++)
    {
        char cha = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << cha << " ";
        }
        
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    pattern(n);
    return 0;
}