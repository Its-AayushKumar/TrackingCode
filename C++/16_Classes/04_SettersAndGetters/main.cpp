#include <iostream>
const double PI{3.1415926535897932384626433832795};

class Cylinder
{
public:
    // Constructors
    Cylinder() = default;

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

    // Setters and Getters methods
    double get_base_radius()
    {
        return base_radius;
    }
    double get_height()
    {
        return height;
    }

    void set_base_radius(double rad_param)
    {
        base_radius = rad_param;
    }
    void set_height(double height_param)
    {
        height = height_param;
    }

private:
    // Member variables
    double base_radius{1};
    double height{1};
};

int main()
{
    Cylinder cylinder1(10, 10);
    std::cout << "base_radius :" << cylinder1.get_base_radius() << std::endl;
    std::cout << "Volume :" << cylinder1.vol() << std::endl;

    // Modify our object
    cylinder1.set_base_radius(100);
    cylinder1.set_height(100);
    std::cout << "Volume :" << cylinder1.vol() << std::endl;

    return 0;
}

// Since the base_radius is in provate we cannot directly access them so
// we have created a getter function to access that
// Getter will return a copy