#include <iostream>

int main()
{
    /*
    Lamda function signature :
                             [Capture list](parameters)-> return type{
                             //fuction
                             body}*/
    /*
    auto func = []()
    {
        std::cout << "Hello World!" << std::endl;
    };

    func();

    */

    // Declare a lamda function and call it directly

    []()
    {
        std::cout << "Hello World!" << std::endl;
    }();

    // Lamda function that takes parameters
    // [](double a, double b)
    // { std::cout << "a+b:" << (a + b) << std::endl; }(10.0, 5.0);

    /*
     auto func1 = [](double a, double b)
     { std::cout << "a+b:" << (a + b) << std::endl; };

     func1(10, 20);
 */

    // // Lambda funstion that returns something
    // auto result = [](double a, double b)
    // {
    //     return a + b;
    // }(12, 34);
    // std::cout << "result :" << result << std::endl;

    // Explicitly specify the return type

    auto func3 = [](double a, double b) -> int
    {
        return a + b;
    };

    auto func4 = [](double a, double b)
    {
        return a + b;
    };

    double a{9.3};
    double b{3.1};

    auto result3 = func3(a, b);
    auto result4 = func4(a, b);

    std::cout << "sizeof(result3) :" << sizeof(result3) << std::endl;
    std::cout << "sizeof(result4) :" << sizeof(result4) << std::endl;

    std::cout << "Done" << std::endl;
    return 0;
}