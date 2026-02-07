#include <iostream>

int main()
{
    bool red_light{true};
    bool green_light{false};
    if (red_light == true)
    {
        std::cout << "Stop!" << std::endl;
    }
    else
    {
        std::cout << "go through!" << std::endl;
    }

    if (green_light)
    {
        std::cout << "The light is green!" << std::endl;
    }
    else
    {
        std::cout << "The light is not green!" << std::endl;
    }

    // sizeof --> to check the size of boolean
    std::cout << "sizeof(bool) : " << sizeof(bool) << " byte " << std::endl;

    // Printing out a bool
    // 1--> true
    // 0--> false
    std::cout << std::endl;
    std::cout << "red_light :" << red_light << std::endl;
    std::cout << "green_light :" << green_light << std::endl;

    std::cout << std::boolalpha;
    std::cout << "red_light :" << red_light << std::endl;
    std::cout << "green_light :" << green_light << std::endl;
    return 0;
}
// boolalpha --> Instead of getting 0/1 as the output if we want true or false we use boolalpha