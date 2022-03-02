/* write a program that counts blanks, tabs and newlines */
#include <stdio.h>

main()
{
    int c; /* our ints are bigger than in the '80s */
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;
    while ((c = getchar()) != EOF) 
    {
        if (c == ' ')
            blanks++;
        if (c == '\t')
            tabs++;
        if (c == '\n')
            newlines++;
    }
    printf("\nblanks: %d\ntabs: %d\nnewlines: %d\n", blanks, tabs, newlines);
}