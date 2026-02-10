
#include <iostream>

int main()
{

    // Print I love C++ 10 times
    /*
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    */

    const int COUNT{10}; // if here COUNT{0} is there then also the do while  loop runs 1 time
    size_t i{0};         // Iterator declaration

    do
    {
        std::cout << i << " : I love C++" << std::endl;
        ++i; // Incrementation
    } while (i < COUNT);

    std::cout << "Loop done!" << std::endl;

    return 0;
}
