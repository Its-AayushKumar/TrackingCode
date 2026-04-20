#include <iostream>
#include "constants.h"
#include "cylinder.h"

int main()
{
    Cylinder cylinder1(10, 10);
    std::cout << "Volume:" << cylinder1.vol() << std::endl;
    return 0;
}