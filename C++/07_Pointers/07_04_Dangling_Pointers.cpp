#include <iostream>

int main()
{
    /*
     // Case 1 : Uninitialized pointer
     int *p_number; // Dangling uinitialized pointer

     std::cout << std::endl;
     std::cout << "Case 1 : Uninitialized pointer :" << std::endl;
     std::cout << "p_number :" << p_number << std::endl;
     std::cout << "*p_number :" << *p_number << std::endl; // Crash
 */

    /*
       // Case 2 : Deleted pointer
       // Program may crash or it will have undefined behaviour
       std::cout << std::endl;
       std::cout << "Case 2 : Deleted pointer" << std::endl;
       int *p_num1{new int{34}};

       std::cout << "p_num1(before delete) : " << *p_num1 << std::endl;

       delete p_num1;
       std::cout << "p_num1(after delete) : " << *p_num1 << std::endl;
   */
    /*
        // Case 3 : Multiple pointers pointing to same address
        std::cout << std::endl;
        std::cout << "//Case 3 : Multiple pointers pointing to same address" << std::endl;

        int *p_num2{new int{55}};
        int *p_num3{p_num2};

        std::cout << "p_num2 -" << p_num2 << "-" << *p_num2 << std::endl;
        std::cout << "p_num3 -" << p_num3 << "-" << *p_num3 << std::endl;

        // Deleting p_num2
        delete p_num2;

        // Now p_num3 points to deleted memory . Dereferencing it will lead to
        // Undefined behaviour : Crash / Garbage or whatever
        std::cout << "p_num3(after deleting p_num2)- " << p_num3 << "-" << *p_num3 << std::endl;
         */

    // Solution 1 : Initialize your pointer immediately upon declaration
    std::cout << std::endl;
    std::cout << "Solution 1 :" << std::endl;
    int *p_num5{nullptr};
    int *p_num6{new int{34}};

    // check for nullptr before use

    if (p_num6 != nullptr)
    {
        std::cout << "*p_num6 : " << *p_num6 << std::endl;
    }
    else
    {
        std::cout << "Invalid address" << std::endl;
    }

    // Solution 2 :
    // Right after you call delete on a pointer , remember to reset
    // the pointer to nullptr to make it CLEAR it doesn't point anywhere
    std::cout << std::endl;
    std::cout << "Solution 2 :" << std::endl;
    int *p_num7{new int{90}};

    // Use the pointer however you want
    std::cout << "p_num7 -" << p_num7 << "-" << *p_num7 << std::endl;

    delete p_num7;
    p_num7 = nullptr; // Reset the pointer

    // Check for nullptr before use
    if (p_num7 != nullptr)
    {
        std::cout << "*p_num7 -" << *p_num7 << std::endl;
    }
    else
    {
        std::cout << "Invalid memory access !! " << std::endl;
    }

    // Solution 3 :
    // For multiple pointers pointing to the same address , make sure there is
    // one clear pointer (master pointer) that owns the memory (responsible for releasing when neccesary)
    // other pointer should only be able to dereference when the master pointer is valid

    std::cout << std::endl;
    std::cout << "Solution 3:" << std::endl;
    int *p_num8{new int{382}}; // Let say p_num is the master pointer
    int *p_num9{p_num8};

    // Dereference the pointer and use them
    std::cout << "p_num8 - " << p_num8 << "-" << *p_num8 << std::endl;

    if (!(p_num8 == nullptr))
    { // Only use slave pointer when master pointer is valid
        std::cout << "p_num9 - " << p_num9 << "-" << *p_num9 << std::endl;
    }
    delete p_num8; // Master release the memory
    p_num8 = nullptr;

    if (!(p_num8 == nullptr))
    { // Only use slave pointer when master pointer is valid
        std::cout << "p_num9 - " << p_num9 << "-" << *p_num9 << std::endl;
    }

    std::cout << "Program is running well!!" << std::endl;
    return 0;
}