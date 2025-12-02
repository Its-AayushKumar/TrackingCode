#include <stdio.h>

int main()
{
    int phy, chem, maths;
    float total;
    printf("Enter physics marks:\n");
    scanf("%d", &phy);

    printf("Enter chemistry marks:\n");
    scanf("%d", &chem);

    printf("Enter maths marks:\n");
    scanf("%d", &maths);

    total = (phy + maths + chem) / 3;
    if ((total < 40) || phy < 33 || maths < 33 || chem < 33)
    {
        printf("Your total percentage is %f and you are fail \n", total);
    }
    else
    {
        printf("Your total percentage is %f and you are pass \n", total);
    }

    return 0;
}