#include <iostream>

int main()
{
    int num[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    // Read beyond bounds : will read garbage or crash your program
    std::cout << "num[12] : " << num[12] << std::endl;

    // Write beyond bounds. The compiler allows it. But you don't own
    // the memory at index 12, so other programs may modify it and your
    // program may read bogus data at a later time. Or you can even
    // corrupt data used by other parts of your ptogram

    num[999999] = 1233244;
    std::cout << "num[12]:" << num[12] << std::endl;
    std::cout << "Program ending ......";
    return 0;
}