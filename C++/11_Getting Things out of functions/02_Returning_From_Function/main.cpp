#include <iostream>
int sum(int a, int b)
{
    int result = a + b;
    std::cout << "In : &result(int):" << &result << std::endl;
    return result; // This result is local to this function
}
int main()
{
    int a{23};
    int b{17};
    int result = sum(a, b); // this result is different from the the above result
    std::cout << "Out :&result(int):" << &result << std::endl;
    std::cout << "Sum : " << result << std::endl;
    return 0;
}
// we are copying the function variable value to the main result we can clearly see that by the address
// In modern compilers, return by value is commonly optimized out by
// the compiler when possible and the function is modified behind your back to return by reference,
// avoiding unnecessary copies !