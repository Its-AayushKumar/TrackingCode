#include <iostream>
#include "compare.h" // Preprocessor
#include "operations.h"

int main()
{
    int maximum = max(465, 43);
    std::cout << "max :" << maximum << std::endl;
    int minimum = min(234, 453);
    std::cout << "min :" << minimum << std::endl;

    int x{4};
    int y{5};

    int result = incr_mult(x, y);
    std::cout << "result:" << result << std::endl;

    return 0;
}
