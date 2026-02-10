#include <iostream>

int main()
{
    // Declare an array of ints
    // int scores[10]; // Junk data

    // Read data
    /*
    std::cout << "Scores[0] : " << scores[0] << std::endl;
    std::cout << "Scores[1] : " << scores[1] << std::endl;
    */

    // Read with a loop

    // for (size_t i{0}; i < 10; ++i)
    // {
    //     std::cout << "scores[" << i << "] :" << scores[i] << std::endl;
    // }

    // Write data into an array

    // scores[0] = 23;
    // scores[1] = 24;
    // scores[2] = 25;
    // scores[3] = 26;

    // Print the data out
    // for (size_t i{0}; i < 10; ++i)
    // {
    //     std::cout << "scores[" << i << "] :" << scores[i] << std::endl;
    // }

    /*
        // Writing data in loops
        for (size_t i{}; i < 10; ++i)
        {
            scores[i] = i * 10;
        }

        // Print the data out
        for (size_t i{0}; i < 10; ++i)
        {
            std::cout << "scores[" << i << "] :" << scores[i] << std::endl;
        }
            */
    /*
        // Declare and initialize at the same time
        std::cout << std::endl;
        std::cout << "Declare and intialize at the same time :" << std::endl;

        double salaries[5]{12.5, 34.4, 53.5, 56.6, 56.6};

        for (size_t i{0}; i < 5; ++i)
        {
            std::cout << "salary[" << i << "] :" << salaries[i] << std::endl;
        }
    */

    // If we don't initailize all the elements , those are intaialized to 0
    /*
    int families[5]{12, 3, 5};
    for (size_t i{0}; i < 5; ++i)
    {
        std::cout << "family[" << i << "] :" << families[i] << std::endl;
    }
    */

    /*
    // Omit the size of the array at declaration
    int class_sizes[]{12, 34, 45, 56, 67, 78, 67};

    // Will print this with a range based on the loop

    for (auto value : class_sizes)
    {
        std::cout << "value :" << value << std::endl;
    }
    */

    // // Read only arrays
    // const int birds[]{12, 34, 45, 56, 67, 78, 67};
    // birds[2]= 8; // This will give error

    int scores[]{2, 3, 4, 5, 6, 7, 8};
    int sum{0};
    for (int element : scores)
    {
        sum += element;
    }
    std::cout << "Score sum :" << sum << std::endl;

    return 0;
}