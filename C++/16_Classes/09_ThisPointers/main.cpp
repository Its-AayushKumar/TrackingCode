#include <iostream>
#include <string_view>

class Dog
{
public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int p_age_param);
    ~Dog();

private:
    std::string name;
    std::string breed;
    int *p_age{nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Dog constructor called for " << name << "at" << this << std::endl;
}

Dog::~Dog()
{
    delete p_age;
    std::cout << "Dog destructor called for " << name << this << std::endl;
}

int main()
{
    Dog dog1("Fluffy", "Shepherd", 2); // constructor

    std::cout << "Done!" << std::endl;

    return 0;
}