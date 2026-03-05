#include <iostream>
#include <string>

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}
int main()
{
    int a{10};
    int b{20};
    double c{23.3};
    double d{32.4};
    std::string e{"Hello"};
    std::string f{"World"};

    auto max = maximum(c, d);

    // Explicit tempalte arguments

    auto max1 = maximum<double>(a, d); // Now we can pass different type of varibles it will convert into double

    std::cout << "max1 :" << max1 << std::endl;
    return 0;
}
// We cannot put different type of variables together complier will give error .
// To make this work we have to use Explicit template arguments