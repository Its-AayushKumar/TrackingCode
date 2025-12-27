#include <stdio.h>

int main()
{
    // char str[] = {'A', 'a', 'y', 'u', 's', 'h', '\0'};

    // '\0' is the null character to tell the string ends here

    char str[] = "Aayush"; // Here no need to put null character, compiler adds '\0' automatically

    // %s is important because it tells printf that 'str' is a STRING.
    // Without %s (i.e., printf(str)), printf treats the string as a format,
    // which can lead to unexpected output or undefined behavior.
    printf("%s", str);

    return 0;
}
