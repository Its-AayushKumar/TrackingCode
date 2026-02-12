#include <iostream>

int main()
{
    /*
    // Bad
    // Writing into uninitialized pointer through dereference
    int *p_num1;  // Contains junk address :could be anything
    *p_num1 = 44; // Writing into junk address Bad
    std::cout << std::endl;
    std::cout << "Writing into uninitialized pointer through dereference " << std::endl;
    std::cout << "p_num1 :" << p_num1 << std::endl; // Reading from junk address
    std::cout << "p_num1 :" << *p_num1 << std::endl;


    // Initializing pointer to null
    // int * p_num3{nullptr}; // Also works
    int *p_num3 { }; // Initialized with pointer equivalent of zero : nullptr
    std::cout << "Writing into nullptr memory "<< std::endl;
    // *p_num3 = 33; // Writing into a pointer pointer pointing no where : BAD , CRASH
    std::cout<<"Done writing"<< std::endl;

    std::cout<<std::endl;
    std::cout<<"Reading and writing through nullptr :"<< std::endl;
    // std::cout<<"p_num3"<< p_num3<<std::endl;
    std::cout<<"*p_num3"<< *p_num3<<std::endl;// Reading from nullptr , BAD , CRASH
*/

    // Dynamic heap memory
    int *p_num4{nullptr};
    p_num4 = new int; // Dynamically allocate space for a single int on the heap
                      // This memory belongs to our program from now on. The system
                      // can't use it for anything else, untill we return it.
                      // After this line executes, we will have a valid memory location
                      // allocated. The size of the allocated memory will be such that it
                      // can store the type pointed to by the pointer
                      /*
                          *p_num4 = 77;
                          std::cout << std::endl;
                          std::cout << "Dynamically allocating memory:" << std::endl;
                          std::cout << "*p_num4:" << *p_num4 << std::endl;
                          std::cout << "p_num4:" << p_num4 << std::endl;
                  
                          // Return memory to the OS
                          delete p_num4;
                          p_num4 = nullptr;
                         */

    // It is also possible to initialize the pointer with a valid
    // address up on declaration. Not with a nullptr
    int *p_number5{new int};     // Memory location contains junk value
    int *p_number6{new int(22)}; // use direct initialization
    int *p_number7{new int{23}}; // use uniform initialization

    std::cout << std::endl;
    std::cout << "Initialize with valid memory address at declaration : " << std::endl;
    std::cout << "p_number5 : " << p_number5 << std::endl;
    std::cout << "*p_number5 : " << *p_number5 << std::endl; // Junk value

    std::cout << "p_number6 : " << p_number6 << std::endl;
    std::cout << "*p_number6 : " << *p_number6 << std::endl;

    std::cout << "p_number7 : " << p_number7 << std::endl;
    std::cout << "*p_number7 : " << *p_number7 << std::endl;

    // Remember to release the memory
    delete p_number5;
    p_number5 = nullptr;

    delete p_number6;
    p_number6 = nullptr;

    delete p_number7;
    p_number7 = nullptr;

    // Can reuse pointers
    p_number5 = new int(81);
    std::cout << "*p_number : " << *p_number5 << std::endl;

    delete p_number5;
    p_number5 = nullptr;

    // Calling delete twice on a pointer : BAD!
    p_number5 = new int(99);
    std::cout << "*p_number5 : " << *p_number5 << std::endl;

    delete p_number5;
    delete p_number5; // The program will be killed by operating sytem fram here

    std::cout << "Program is ending well !!" << std::endl;
    return 0;
}