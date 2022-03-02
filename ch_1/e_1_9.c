/* write a program to copy its input to its output,
replacing each string of one or more blanks by a single blank */
#include <stdio.h>

main()
{
    int c, pc;
    
    pc = 'a';
    while ((c = getchar()) != EOF)
    {
        if(c != ' ' || pc != ' ')
            putchar(c);
        pc = c;
    }
}