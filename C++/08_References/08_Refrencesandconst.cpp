#include <iostream>

int main()
{

    // Non const reference
    std::cout << std::endl;
    int age{24};
    const int &ref_age{age};
    /*
        std::cout << "age :" << age << std::endl;
        std::cout << "ref_age :" << ref_age << std::endl;

        // Can modify original variable through reference

        std::cout << std::endl;
        std::cout << "Modify original variable through reference :" << std::endl;

        ref_age++; // Modify through refenence

        std::cout << "age:" << age << std::endl;
        std::cout << "ref_age :" << ref_age << std::endl;
        */
    // WE cannot change the value of a const reference

    // // Simulationg reference behaviour with pointers
    // const int *const p_age{&age};

    // *p_age = 45;

    return 0;
}