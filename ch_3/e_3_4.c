/* In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to
 * -(2wordsize-1). Explain why not. Modify it to print that value correctly,
 * regardless of the machine on which it runs.
 * 
 * Explanation: In two's complement the range of negative numbers is one greater
 * than the range of the positives.
*/

#include <stdio.h>

void reverse(char s[]);
void itoa(int n, char s[]);

int main()
{
    int n = -2147483648;
    char s[1000];
    
    itoa(n, s);
    printf("%s\n", s);

    return 0;
}

/* I got this reverse from the interwebs for convenience */
void reverse(char s[]) {
    int c, i, j;
    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* Using the absolute function is kind of cheating and not at the same time.
 * It is the easiest to write and I'm not competing for anything here.
 * The book did not teach is as far as I remember but I could easily write
 * a simple version of it.
*/
void itoa(int n, char s[])
{
    int sign = n;
    int i = 0;

    do
    {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}