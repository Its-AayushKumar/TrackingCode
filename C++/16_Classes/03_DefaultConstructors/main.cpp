#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder
{
public:
    // Constructors
    Cylinder() = default; // This creates a default constructor

    Cylinder(double rad_para, double height_para)
    {
        base_radius = rad_para;
        height = height_para;
    }

    // Function (methods)
    double vol()
    {
        return PI * base_radius * base_radius * height;
    }

private:
    // Member variables
    double base_radius{1};
    double height{1};
};

int main()
{
    Cylinder cylinder1;
    std::cout << "Volume:" << cylinder1.vol() << std::endl;

    return 0;
}

// Constructors need to be public to show like this (accessible)