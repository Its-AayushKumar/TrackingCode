#include <iostream>
using namespace std;

int main()
{
    int n{4};

    // top
    for (int i = 0; i < n; i++)
    {
        // Spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << "*";

        if (i != 0)
        {
            // spaces
            for (int j = 0; j < 2 * i - 1; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }

    // bottom
    for (int i = 0; i < n - 1; i++)
    {
        // spaces
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        cout << "*";
        if (i != n - 2)
        {
            // spaces
            for (int j = 0; j < 2 * (n - i) - 5; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

/*
    *
   * *
  *   *
 *     *
  *   *  i = 0.
   * *   i = 1
    *    i = 2 = (n-2)
// top
    lines = n-1
    left side
        spaces = n - i -1
    right side
        spaces = 2i-1
// bottom
    lines = n - 2
    left side
        spaces = i+1;
    right side
        spaces = 2*(n-2-i) -1;

*/