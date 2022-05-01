/* 
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
*/
#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int main()
{
    printf("%u\n", setbits(255, 1, 7, 0));
    return 0;
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    /*
     * The example uses right adjusted n-bit field,
     * I choose to return left adjusted because it
     * feels more natural and it isn't explicityly
     * stated in the exercise.
     * counting from the right, we need to do
     *    ...p...0
     * xxxx000xxxx
     * 0000yyy0000
     * xxxxyyyxxxx
    */
    x = x & ~(~(~0u << n) << (p));
    y = y & (~(~0u << n) << (p));
    return x | y;
}