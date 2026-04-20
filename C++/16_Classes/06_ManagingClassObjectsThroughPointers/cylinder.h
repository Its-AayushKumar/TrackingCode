#ifndef CYLINDER_H // Used when a header file is included twice
#define CYLINDER_H

#include "constants.h"

class Cylinder
{
public:
    // Constructors
    Cylinder() = default;

    Cylinder(double rad_para, double height_para);

    // Function (methods)
    double vol();

    // Setters and Getters methods
    double get_base_radius();

    double get_height();

    void set_base_radius(double rad_param);

    void set_height(double height_param);

private:
    // Member variables
    double base_radius{1};
    double height{1};
};

#endif