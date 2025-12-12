#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *qptr;
    FILE *aptr;
    int line = 0, start = 0, i = 0, answered = 0, qlist[] = {1, 4, 8, 12, 16};
    char c, uans, d;
    qptr = fopen("questions.txt", "r");
    aptr = fopen("answers.txt", "r");
    c = fgetc(qptr);
    while (c != EOF)
    {
        if ((line >= start) && (line < (start + 4)))
        {
            printf("%c", c);
            if (line == start + 3)
            {

                answered++;
                start = qlist[answered];
                printf("Enter Your Selected Option(a/b/c/d) : ");
                scanf(" %c", &uans);
                d = fgetc(aptr);
                if (d == uans)
                {
                    printf("correct Answer !!");
                }
                else
                {
                    printf("Wrong!!");
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
    printf("\n%d", line);
    // fclose(qptr);
    // fclose(aptr);
    return 0;
}
