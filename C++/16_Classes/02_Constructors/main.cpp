#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder
{
public:
    // Constructors
    Cylinder()
    {
        base_radius = 2.0;
        height = 3.0;
    }

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
    Cylinder cylinder1; // Object
    std::cout << "volume:" << cylinder1.vol() << std::endl;

    Cylinder cylinder2(10, 4);

    std::cout << "Volume:" << cylinder2.vol() << std::endl;

    return 0;
}

/*If you don't define any constructor, C++ automatically provides a default constructor that does nothing — your member variables will be initialized by whatever values you gave them inline.*/