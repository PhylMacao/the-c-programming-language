/*
 * Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
 * others unchanged.
*/
#include<stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)   \
  (byte & 128 ? '1' : '0'),    \
      (byte & 64 ? '1' : '0'), \
      (byte & 32 ? '1' : '0'), \
      (byte & 16 ? '1' : '0'), \
      (byte & 8 ? '1' : '0'),  \
      (byte & 4 ? '1' : '0'),  \
      (byte & 2 ? '1' : '0'),  \
      (byte & 1 ? '1' : '0')

unsigned invert(unsigned x, unsigned p, unsigned n);

int main()
{
    unsigned int x = 0b11010111;

    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(invert(x, 1, 4)));
    
    return 0;
}

unsigned invert(unsigned x, unsigned p, unsigned n)
{
    /* NOTE: I still stand by that the indexing starts from the right from 0.
     * there are solutions on the internet using p+1-n because the book example
     * uses a right adjusted n-bit field. I choose to use left-adjusted because
     * it feels more natural. Always read the docs of the functions you use or
     * something like that.
    */
    return x ^ (~(~0u << n) << (p));
}