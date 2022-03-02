/* write a program to print the value of EOF */
#include <stdio.h>

main()
{
    putchar(EOF); /* print an EOF character */
    int c = EOF;
    printf("\n%i\n", c); /* print EOF as an integer to get it's value */
}