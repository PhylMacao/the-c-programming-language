/*
 * Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
*/
#include <stdio.h>

char lower(char c);

int main()
{
    for (char i = '0'; i <= 'Z'; i++)
    {
        printf("%c", lower(i));
    }
    
    return 0;
}

char lower(char c)
{
    return 'A' <= c && c <= 'Z' ? c - ('A' - 'a') : c;
}