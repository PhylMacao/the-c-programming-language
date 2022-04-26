/*
 * Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n positions.
*/
#include <stdio.h>

unsigned rightrot(unsigned x, unsigned n);

int main()
{
    printf("%d\n", 2 >> 1);
    for (int i = 0; i < 32; i++)
    {
        printf("%d\n", rightrot(2, i));
    }
    
    return 0;
}

unsigned rightrot(unsigned x, unsigned n)
{
    /*
     * At this point the book does not have sizeof(), so
     * a, implement it somehow
     * b, get the solution below
     * I chose b.
    */
    while (n-- > 0)
    {
        if (x & 1)
            x = x >> 1 | ~(~0U >> 1);
        else
            x = x >> 1;
    }
    return x;
}