#include <iostream>
#include <cstring>

int main()
{
    /*

     // std::strcmp - signature : int strcmp(const char *lhs, const char *rhs);
     // Returns negative value if lhs appeares before rhs in lexicographical order,
     //  Zero if lhs and rhs compare equal .
     // and Positive value if lhs appears after rhs in lexicographical order.
     std::cout << std::endl;
     std::cout << "std::strcmp :" << std::endl;
     const char *string_data1{"Alabama"};
     const char *string_data2{"blabama"};

     char string_data3[]{"Alabama"};
     char string_data4[]{"Blabama"};

     // Print out the comparison
     std::cout << "std::strcmp(" << string_data1 << "," << string_data2 << "):" << std::strcmp(string_data1, string_data2) << std::endl;

     std::cout << "std::strcmp(" << string_data3 << "," << string_data4 << ") :" << std::strcmp(string_data3, string_data4) << std::endl;

     */

    // -----------------------------------------------------------------------
    // std::strncmp : int strncmp (const char *lhs , const char*rhs , std::size_t count);
    //  Compares n characters in the strings
    //  Returns : Nagative value if lhs appear before rhs in the lexicographical order .
    //  zero if lhs and rhs compare equal, or if count is zero
    //  Positive value if lhs appears after rhs in lexicographical order

    // Print out comaparision

    /*
     const char *string_data1{"Alabama"};
     const char *string_data2{"Blabama"};
     size_t n{3};

     std::cout << std::endl;
     std::cout << "std::strncmp :" << std::endl;
     std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") :" << std::strncmp(string_data1, string_data2, n) << std::endl;

     string_data1 = "aaaia";
     string_data2 = "aaance";

     std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") :" << std::strncmp(string_data1, string_data2, n) << std::endl;

     n = 5;

     std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") :" << std::strncmp(string_data1, string_data2, n) << std::endl;
     */

    //  --------------------------------------------------------------
    /*
    // Find the first occerence of a character
    std::cout << std::endl;
    std::cout << "std::strchr :" << std::endl;

    // We use std::strchr to find all the characters one by one

    const char const *str{"Try not. Do, or do not. There is no try."};
    // Can make this a const pointer to prevent users from making it point somewhere else
    char target = 'T';
    const char *result = str; // we are storing str in result because we donot want to change whatever is stored in str
    size_t iteration{};

    while ((result = std::strchr(result, target)) != nullptr)
    {
        std::cout << "Found '" << target << "' starting at '" << result << "'\n";

        // Increment result , otherwise we'll find target at the same location
        ++result;
        ++iteration;
    }
    std::cout << "Iterations :" << iteration << std::endl;
*/
    // A lesser version that will loop 25 times
    /*
    //Find the first occurrence of a character
    //CODE STOLEN FROM THE DOCS :
    std::cout << std::endl;
    std::cout << "std::strchr : " << std::endl;
    //doc : https://en.cppreference.com/w/cpp/string/byte/strchr

    //we use std::strchr to find all the characters one by one.

    const char* str{ "Try not. Do, or do not. There is no try." };
    char target = 'T';
    const char* result{ nullptr };
    size_t iterations{};


    while ((result = std::strchr(str, target)) != nullptr) {
        std::cout << "Found '" << target
            << "' starting at '" << result << "'\n";

        // Increment result, otherwise we'll find target at the same location
        ++str; // Making the pointer point to the next character
        ++iterations;
    }
    std::cout << "iterations : " << iterations << std::endl;
    */

    // Find last occurence
    // CODE STOLEN FROM THE DOCS :
    std::cout << std::endl;
    std::cout << "std::strrchr : " << std::endl;
    // doc : https://en.cppreference.com/w/cpp/string/byte/strrchr

    char input[] = "/home/user/hello.cpp";
    char *output = std::strrchr(input, '/');
    if (output)
        std::cout << output + 1 << std::endl; //+1 because we want to start printing past
                                              // the character found by std::strrchr.

    return 0;
}