#include <iostream>

int main()
{
    int n1, n2, ans;
    char op;
    std::cout << "Enter number 1 :" << std::endl;
    std::cin >> n1;

    std::cout << "Enter number 2 :" << std::endl;
    std::cin >> n2;

    std::cout << "Enter operator (+,-,*,/)" << std::endl;
    std::cin >> op;

    switch (op)
    {
    case '+':
        ans = n1 + n2;
        break;

    case '-':
        ans = n1 - n2;
        break;

    case '*':
        ans = n1 * n2;
        break;

    case '/':
        ans = n1 / n2;
        break;

    default:
        std::cout << "Invalid operator " << std::endl;
        break;
    }
    std::cout << "Answer :" << ans << std::endl;

    return 0;
}