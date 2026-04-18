#include <iostream>
#include <concepts>

// This syntax constrains the auto parameters you pass in
// to comply with the std::integral concept
std::integral auto add(std::integral auto a, std::integral auto b)
{
    return a + b;
}
int main()
{
    std::cout << add('a', 'b'); // In integral we can use char , int , bool
    add(4, 5);
    return 0;
}