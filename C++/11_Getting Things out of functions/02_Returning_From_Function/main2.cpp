#include <iostream>
std::string add_strings(std::string str1, std::string str2)
{
    std::string result = str1 + str2;
    std::cout << "In :&result(std::string) :" << &result << std::endl;
    return result;
}

int main()
{
    std::string in_str1{"Hello"};
    std::string in_str2{" World!"};
    std::string result_str = add_strings(in_str1, in_str2);
    std::cout << "Out :&result_str(std:string) :" << &result_str << std::endl;
    std::cout << "result_str :" << result_str << std::endl;
    return 0;
}
// IMPORTANT CONCEPT: Return Value Optimization (RVO)
//
// When returning a local object by value, modern C++ (C++17+)
// does NOT create a temporary copy.
//
// Instead, the compiler constructs the local object directly
// in the memory location of the receiving variable in main().
//
// That is why &result (inside function) and
// &result_str (in main) may print the SAME address.
//
// This is safe and efficient.
// It is still return-by-value, NOT return-by-reference.