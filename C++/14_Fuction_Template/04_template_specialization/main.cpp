#include <iostream>

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    /*
    int a{10};
    int b{23};
    double c{43.4};
    double d{23.4};
    std::string e{"Hello"};
    std::string f{"World"};

    auto max_int = maximum(a, b);    // int type deducted
    auto max_double = maximum(c, d); // double type deducted
    auto max_str = maximum(e, f);    // string type deducted

    std::cout << "max_int :" << max_int << std::endl;
    std::cout << "max_double :" << max_double << std::endl;
    std::cout << "max_str :" << max_str << std::endl;
    */

    //
    const char *g{"wild"};
    const char *h{"anumal"};

    // This won't do what you would expect : BEWARE !
    const char *result = maximum(g, h);
    std::cout << "max(const char*):" << result << std::endl;

    return 0;
}