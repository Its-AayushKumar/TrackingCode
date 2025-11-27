#include <stdio.h>

int main()
{
    int principal = 123, rate = 5, years = 2;
    float simple_interest = (principal * rate * ((float)years)) / 100;  
    //float simple_interest = (principal * rate * years / 100.0 (This is also works same);  
    printf("The value of simple interest id %f", simple_interest);     
    return 0;
}

 //To get the result in float form one of the value should be float