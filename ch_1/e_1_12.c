/* write a program that prints its input one word per line */
#include <stdio.h>

main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        /* this won't test for double blanks
        but it's simpler and that isn't part
        of this exercise */
        if (c == ' ' || c == '\t')
            putchar('\n');
        else
            putchar(c);
    }
}