#include <iostream>

int main()
{
    /*
    // Capture lists
    double a{10};
    double b{20};

    auto func = [a, b]() // Value is going inside by capture list not by parameters
    {
        std::cout << "a+b :" << a + b << std::endl;
    };
    func();
*/

    /*
        // Capturing by value
        int c{93};

        auto func = [c]()
        {
            std::cout << "Inner value:" << c << "&Inner :" << &c << std::endl;
        };

        for (size_t i{}; i < 5; ++i)
        {
            std::cout << "Outer value:" << c << "&outer :" << &c << std::endl;
            func();
            ++c;
        } // Inner value and outer value are two different things in the functions it makes a copy of the value
    */

    // Capturing by reference
    int c{45};

    auto func = [&c]() // Now what we have inside lamda function is no longer a copy it is a true reference to the outer value
    {
        std::cout << "Inner value:" << c << " &Inner :" << &c << std::endl;
    };

    for (size_t i{}; i < 5; ++i)
    {
        std::cout << "Outer value:" << c << " &outer :" << &c << std::endl;
        func();
        ++c;
    }
    return 0;
}