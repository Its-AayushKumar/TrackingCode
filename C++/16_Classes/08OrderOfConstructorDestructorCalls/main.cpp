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
    std::cout << "Dog constructor called for " << name << std::endl;
}

Dog::~Dog()
{
    delete p_age;
    std::cout << "Dog destructor called for " << name << std::endl;
}

int main()
{
    Dog dog1("Dog1", "Shepherd", 2);
    Dog dog2("Dog2", "Shepherd", 3);
    Dog dog3("Dog3", "Shepherd", 9);
    Dog dog4("Dog4", "Shepherd", 28);

    return 0;
}