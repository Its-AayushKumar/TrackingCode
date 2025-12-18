#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int gen()
{
    int number;
    int max, min;
    max = 99;
    min = 0;
    // number = rand();
    number = (rand() % (max - min + 1)) + min;
    printf("Random Number : %d\n", number);
    return number;
}
int main()
{
    srand(time(0));
    FILE *qptr;
    FILE *aptr;
    char c, uans, d;
    int line = 0, aline = 0, answered = 0, qlist[10], temp;
    for (int i = 0; i < 10; ++i)
    {
        temp = gen();
        for (int j = 0; j < i; j++)
        {
            if ((gen - qlist[j]) == 0)
            {
                temp = gen();
            }
        }
        qlist[i] = temp;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("Value of Qlist[%d] is : %d\n", i, qlist[i]);
    }
    int start = qlist[0] * 4;
    printf("The value of start : %d \n", start);
    while (answered < 10)
    {
        printf("answer : %d\n", answered);
        qptr = fopen("questions.txt", "r");
        aptr = fopen("answers.txt", "r");
        c = fgetc(qptr);
        line = 0;

        while (c != EOF)
        {
            if ((line >= start) && (line < (start + 4)))
            {
                printf("%c", c);
                if (line == start + 3)
                {
                    answered++;
                    start = qlist[answered] * 4;
                    printf("\n");
                    printf("Enter Your Selected Option(a/b/c/d) : ");
                    scanf(" %c", &uans);
                    for (aline = 0; aline <= (qlist[answered - 1] + 2);)
                    {
                        d = fgetc(aptr);
                        if (d == '\n')
                        {
                            aline++;
                            // printf("aline : %d qlist[answered-1] : %d\n", aline, qlist[answered - 1]);
                        }

                        if (aline == (qlist[answered - 1]))
                        {
                            d = getc(aptr);
                            printf("\n%c", d);
                            d = getc(aptr);
                            printf("%c", d);
                            d = getc(aptr);
                            printf("%c", d);
                            d = getc(aptr);
                            printf("%c", d);
                            d = getc(aptr);
                            printf("%c\n", d);
                            break;
                        }
                    }
                    fclose(aptr);
                    aptr = fopen("answers.txt", "r");

                    if (d == uans)
                    {
                        printf("Correct Answer !!");
                    }
                    else
                    {
                        printf("Wrong!!  :: ");
                        printf("Correct answer is %c ", d);
                    }
                    // fclose(aptr);
                }
            }

            c = fgetc(qptr);
            if (c == '\n')
            {
                line++;
            }
        }
    }
    return 0;
}