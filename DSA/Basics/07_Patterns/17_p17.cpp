// 5
//      A
//     ABA
//    ABCBA
//   ABCDCBA
//  ABCDEDCBA
// ABCDEFEDCBA

#include <iostream>
using namespace std;

void pattern(int n)
{
    for (int i = 0; i <= n; i++)
    {
        // Space
        for (int j = 0; j <= n - 1 - i; j++)
        {
            cout << " ";
        }
        // Characters
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= (2 * i + 1); j++)
        {
            cout << ch;
            if (j <= breakpoint)
            {
                ch++;
            }
            else
                ch--;
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    pattern(n);
    return 0;
}