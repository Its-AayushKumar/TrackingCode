#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder
{
public:
    double vol()
    {
        return PI * base_radius * base_radius * height;
    }

    // Member variables
    // private: // This will be now only accessible in the class
public:
    double base_radius{};
    double height{};
};

int main()
{
    Cylinder cylinder1;
    std::cout << "Volume:" << cylinder1.vol() << std::endl;
    // std::cout << "base_radius :" << cylinder1.base_radius << std::endl;
    // std::cout << "height :" << cylinder1.height << std::endl;

    // Change the member variables
    cylinder1.base_radius = 10;
    cylinder1.height = 3;
    std::cout << "Volume:" << cylinder1.vol() << std::endl;

        return 0;
}