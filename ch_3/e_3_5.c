/* Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16) formats
 * s as a hexadecimal integer in s.
*/

#include <stdio.h>

#define MAXLEN 1000

int absolute(int i);
int string_len(char s[]);
void reverse(char s[]);
void itob(int n, char s[], int b);

int main()
{
    char s[1000];
    for (int i = 0; i < 51; i++)
    {
        printf("d: %d; ", i);
        itob(i, s, 2);
        printf("b: %s; ", s);
        itob(i, s, 8);
        printf("b: %s; ", s);
        itob(i, s, 16);
        printf("h: %s;\n", s);
    }
    
    

    return 0;
}

int absolute(int i)
{
    return i < 0 ? -i : i;
}

int string_len(char s[])
{
    int i = 0;
    while (s[i] != '\0' && i < MAXLEN)
    {
        i++;
    }
    return i;
}

void reverse(char s[])
{
    int j = string_len(s) - 1;
    for (int i = 0; i < j; i++, j--)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b)
{
    int sign = n;
    int i = 0;

    do
    {
        char digit = absolute(n % b) + '0';
        s[i++] = (digit > '9') ? digit + 7 : digit;
    } while (n /= b);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}