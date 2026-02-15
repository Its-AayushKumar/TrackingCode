#include <iostream>

int main()
{
    /*
    // Check if character is alphanumeric
    std::cout << std::endl;
    std::cout << "std::isalnum :" << std::endl;

    std::cout << "C is alphanumeric :" << std::isalnum('C') << std::endl;
    std::cout << "^ is alphanumeric :" << std::isalnum('^') << std::endl;

    // Can use this as a test condition
    char input_char{'*'};
    if (std::isalnum(input_char))
    {
        std::cout << input_char << "is alphanumeric . " << std::endl;
    }
    else
    {
        std::cout << input_char << "is not alphanumeric . " << std::endl;
    }
    */
    /*
        // Check if character is alphabetic
        std::cout << std::endl;
        std::cout << "std::isalpha :" << std::endl;
        std::cout << "C is alphabetic :" << std::isalpha('p') << std::endl; // 1
        std::cout << "7 is alphabetic :" << std::isalpha('7') << std::endl; // 0
        std::cout << "^ is alphabetic :" << std::isalpha('^') << std::endl; // 0
                                                                            //  its not compalsary that it will give give always 1 when it is true it can print other number other than 0
    */

    /*
    //     Check if a character is blank
    std::cout << std::endl;
    std::cout << "std::isblank :" << std::endl;
    char message[]{"Hello there. How are you doing? The sun is shining."};
    std::cout << "message :" << message << std::endl;

    // Find and print blank index
    size_t blank_count{};
    for (size_t i{0}; i < std::size(message); ++i)
    {
        if (std::isblank(message[i]))
        {
            std::cout << "Found a blank character at index :[" << i << "]" << std::endl;
            ++blank_count;
        }
    }
    std::cout << "In total we found " << blank_count << " blank characters." << std::endl;
*/
    /*
        // Check if character is lowercase or uppercase
        std::cout << "std::islower and std::isupper :" << std::endl;
        char thought[]{"The C++ programing Lsnguage is one of the most used on the planet"};
        size_t lowercase_count{};
        size_t uppercase{};

        // Print original string for ease of camparison on the terminal
        std::cout << "Original string :" << thought << std::endl;

        for (auto character : thought)
        {
            if (std::islower(character))
            {
                std::cout << " " << character;
                ++lowercase_count;
            }
            if (std::isupper(character))
            {
                ++uppercase;
            }
        }
        std::cout << std::endl;
        std::cout << " Fount " << lowercase_count << "lowercase character and  " << uppercase << "uppercase character. " << std::endl;
    */

    /*
    // Check if a character is a digit
    std::cout << std::endl;
    std::cout << "std::isdigit :" << std::endl;

    char statement[]{"Mr Hamilton owns 221 cows .That's a lot of cows! The kid excalimed"};

    size_t digit_count{};

    for (auto character : statement)
    {
        if (std::isdigit(character))
        {
            std::cout << "Found digit" << character << std::endl;
            ++digit_count;
        }
    }
    std::cout << "Found " << digit_count << " digits in the statement string" << std::endl;
    */

    // Turning a character to lowercase using std::tolower function
    std::cout << std::endl;
    std::cout << "std::tolower and std::toupper :" << std::endl;
    char original_str[]{"Home . The feeling of belinging"};
    char dest_str[std::size(original_str)];

    // Turn this to uppercase . Change the array in place
    for (size_t i{}; i < std::size(original_str); ++i)
    {
        dest_str[i] = std::toupper(original_str[i]);
    }
    std::cout << "Original string :" << original_str << std::endl;
    std::cout << "Uppercase string :" << dest_str << std::endl;

    // Turn this to lowercase . Change the array in place
    for (size_t i{}; i < std::tolower(original_str[i]); ++i)
    {
        dest_str[i] = std::tolower(original_str[i]);
    }
    std::cout << "Lowercase string :" << dest_str << std::endl;
    return 0;
}