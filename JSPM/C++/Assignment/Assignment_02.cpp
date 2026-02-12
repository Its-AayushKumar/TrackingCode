#include <iostream>
void odd_even(int a)
{
    if (a % 2 == 0)
    {
        std::cout << "The number " << a << "is even." << std::endl;
        return;
    }
    else
    {
        std::cout << "The number" << a << "is odd." << std::endl;
        return;
    }
}
void prime(int a)
{
    if (a <= 1)
    {
        std::cout << "The number is not prime" << std::endl;
        return;
    }
    else
    {
        for (size_t i = 2; i < a / 2; ++i)
        {
            if (a % i == 0)
            {
                std::cout << "The number is not prime " << std::endl;
            }
            else
            {
                std::cout << "The number is prime " << std::endl;
            }
        }
    }
}
void pnz(int a)
{
    if (a < 0)
    {
        std::cout << "The number is negative." << std::endl;
    }
    else if (a > 0)
    {
        std::cout << "The number is positive." << std::endl;
    }
    else
    {
        std::cout << "The number is zero." << std::endl;
    }
}

int fibo(int a)
{
    if (a == 0)
    {
        return 0;
    }
    else if (a == 1)
    {
        return 1;
    }
    else
    {
        return fibo(a - 1) + fibo(a - 2);
    }
}
int main()
{
    int a, op;
    std::cout << "Enter the operation you want to perform -->(1,2,3,4)" << std::endl;
    std::cout << "1.To check odd or even." << std::endl;
    std::cout << "2.To check prime number." << std::endl;
    std::cout << "3.To print Fibonacci series." << std::endl;
    std::cout << "4.To check number is positive,negative or zero." << std::endl;

    std::cout << "Enter operation you want to perform:" << std::endl;
    std::cin >> op;
    std::cout << "Enter a number :" << std::endl;
    std::cin >> a;

    switch (op)
    {
    case 1:
        odd_even(a);
        break;
    case 2:
        prime(a);
        break;
    case 3:
        fibo(a);
        break;
    case 4:
        pnz(a);
    default:
        std::cout << "Invalid input !!" << std::endl;
        break;
    }

    return 0;
}