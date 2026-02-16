#include <iostream>
int max(int a, int b);
// Function declaration , prototype
// Signature doesn't include return type

int main()
{
    int x{5};
    int y{2};

    int result = max(x, y);
    std::cout << "max :" << result << std::endl;
    return 0;
}

// Function definition
int max(int a, int b)
{
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
}