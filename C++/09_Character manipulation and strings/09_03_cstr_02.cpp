#include <iostream>
#include <cstring>

int main()
{
    // std::strcmp - signature : int strcmp(const char *lhs, const char *rhs);
    // Returns negative value if lhs appeares before rhs in lexicographical order,
    //  Zero if lhs and rhs compare equal .
    // and Positive value if lhs appears after rhs in lexicographical order.
    std::cout<<std::endl;
    std::cout<<"std::strcmp :"<<std::endl;
    const char * string_data1{"Alabama"};
    const char * string_data2{"blabama"};

    char string_data3[]{"Alabama"};
    char string_data4[]{"Blabama"};

    // Print out the comparison 
    std::cout<<"std::strcmp("<<string_data1<<","<<strin


    return 0;
}