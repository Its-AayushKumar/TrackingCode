#include <iostream>
#include <string> // Here it works with out this but in some compiler it does'nt so better to include
int main()
{

    // Taking input from user
    int age1;
    std::string full_name;

    std::cout << "Please type your full name and age :" << std::endl;

    std::getline(std::cin, full_name);

    std::cin >> age1;

    std::cout << "Hello " << full_name
              << " you are " << age1 << " years old " << std::endl;

    return 0;
}
