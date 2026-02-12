#include <iostream>

int main()
{
    /*
    int *p_number{new int{67}}; // Points to some address1 , let's call that address
    // Should delete and reset here
    int number{55}; // Stack variable

    p_number = &number;
    // Now p_number points to address2 , but address1 is still in
    // our program . But our program has lost access to that
    // Memory has been leaked .
*/
    /*
        // Double allocation
        int *p_number1{new int{55}};
        // Use the pointer
        // Should delete and reset here .

        p_number1 = new int{44}; // Memory with int{55} leaked.
        delete p_number1;
        p_number1 = nullptr;

        */
    std::cout << "Program ending well" << std::endl;
    return 0;
}