#include <iostream>

// Pass by value
double mul(double x, double y)
{
    return x * y;
}

// Pass by address
double mult(double *x, double *y)
{
    return (*x) * (*y);
}

// Pass by reference
double multi(double &x, double &y)
{
    return x * y;
}

// inline function
inline double cube(double a)
{
    return a * a * a;
}

// Default argument subtraction
double subtraction(double a = 0, double b = 0, double c = 0, double d = 0)
{
    return a - b - c - d;
}

int main()
{
    bool yes = true;
    int choice{};
    double num1{}, num2{}, num3{}, num4{};

    while (yes)
    {
        std::cout << "\n===== Calculator Menu =====\n";
        std::cout << "1. Cube\n";
        std::cout << "2. Multiplication (Pass by value)\n";
        std::cout << "3. Multiplication (Pass by address)\n";
        std::cout << "4. Multiplication (Pass by reference)\n";
        std::cout << "5. Subtraction (Default arguments)\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter a number: ";
            std::cin >> num1;
            std::cout << "Cube of number is: " << cube(num1) << std::endl;
            break;

        case 2:
            std::cout << "Enter number 1: ";
            std::cin >> num1;
            std::cout << "Enter number 2: ";
            std::cin >> num2;

            std::cout << "Product (Pass by value): " << mul(num1, num2) << std::endl;
            break;

        case 3:
            std::cout << "Enter number 1: ";
            std::cin >> num1;
            std::cout << "Enter number 2: ";
            std::cin >> num2;

            std::cout << "Product (Pass by address): " << mult(&num1, &num2) << std::endl;
            break;

        case 4:
            std::cout << "Enter number 1: ";
            std::cin >> num1;
            std::cout << "Enter number 2: ";
            std::cin >> num2;

            std::cout << "Product (Pass by reference): " << multi(num1, num2) << std::endl;
            break;

        case 5:
            std::cout << "Enter 4 numbers for subtraction:\n";
            std::cout << "Enter number 1: ";
            std::cin >> num1;
            std::cout << "Enter number 2: ";
            std::cin >> num2;
            std::cout << "Enter number 3: ";
            std::cin >> num3;
            std::cout << "Enter number 4: ";
            std::cin >> num4;

            std::cout << "Result of subtraction: " << subtraction(num1, num2, num3, num4) << std::endl;
            break;

        case 6:
            std::cout << "Exiting program... Bye!\n";
            yes = false;
            break;

        default:
            std::cout << "Invalid choice! Please try again.\n";
            break;
        }
    }

    return 0;
}
