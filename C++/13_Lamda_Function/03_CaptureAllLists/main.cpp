#include <iostream>

int main()
{

    /*
    // Capture everthing by value
    int c{45};

    auto func = [=]()
    {
        std::cout << "Inner value :" << c << std::endl;
    };
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "Outer value :" << c << std::endl;
        func();
        ++c;
    }
        */

    // Capturing all reference
    int c{89};
    int d{5};

    auto func = [&]()
    {
        std::cout << "Inner value:" << c << std::endl;
        std::cout << "Inner value(d):" << d << std::endl;
    };

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "Outer value :" << c << std::endl;
        func();
        ++c;
    }

    return 0;
}