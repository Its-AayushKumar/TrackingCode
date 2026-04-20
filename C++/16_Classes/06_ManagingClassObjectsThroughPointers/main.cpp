#include <iostream>
#include "cylinder.h"

int main()
{
    Cylinder cylinder1(10, 10);

    cylinder1.vol();

    // Managing a stack object through pointers
    Cylinder *p_cylinder1 = &cylinder1;

    // std::cout<<"Volume :"<<p_cylinder1.vol()<<std::endl;  // p_cylinder1 is an pointer not an object so we cannot use that in this way

    std::cout << "volume:" << (*p_cylinder1).vol() << std::endl; // Here we are dereferencing the pointer to get actual object

    std::cout << "Volume:" << p_cylinder1->vol()
     << std::endl; // Doing the same thing but in a better way

    // Create a cylinder heap object through the new operator

    Cylinder *p_cylinder2 = new Cylinder(100, 2); // Heap

    std::cout << "Volume(Cylinder2):" << p_cylinder2->vol() << std::endl;
    std::cout<<"base_rad(cylinder2):"<<p_cylinder2->get_base_radius()<<std::endl;

    delete p_cylinder2;
    return 0;
}
