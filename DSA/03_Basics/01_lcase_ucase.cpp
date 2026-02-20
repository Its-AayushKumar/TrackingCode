#include <iostream>
using namespace std;

int main()
{
    char ch;
    // Method 1 :
    cout << "Enter a character :";
    cin >> ch;
    //  if (ch >= 'a' && ch <= 'z')
    //  {
    //      cout << "lowercase" << endl;
    //  }
    //  else
    //  {
    //      cout << "uppercase";
    //  }

    // Method 2 : --> by using ASCII value
    if (ch >= 65 && ch <= 90) // here we are doing inplicit type of convertion
    {
        cout << "uppercase\n";
    }
    else
    {
        cout << "lowercase";
    }

    return 0;
}