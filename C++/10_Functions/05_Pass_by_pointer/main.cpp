#include <iostream>

void say_age(int *age); // Declatation

int main()
{
    int age{23}; // Local
    std::cout << "age(before) :" << age << " &age " << &age << std::endl;
    say_age(&age); // Argument
    std::cout << "age (after call):" << age << "&age :" << &age << std::endl;

    return 0;
}

void say_age(int *age)
{ // Parameter
    ++(*age);
    std::cout << "Hello , you are " << *age << " years old! &age :" << &age << std::endl;
}