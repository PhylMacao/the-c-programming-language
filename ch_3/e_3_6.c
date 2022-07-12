/* Write a version of itoa that accepts three arguments instead of two.
 * The thirdargument is a minimum field width; the converted number must be
 * padded with blanks on the left if necessary to make it wide enough.
*/

#include <stdio.h>

void reverse(char s[]);
void itoa(int n, char s[], int w);

int main()
{
    int n = -2147483648;
    char s[1000];
    
    itoa(n, s, 15);
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
void itoa(int n, char s[], int w)
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
    while (i < w)
    {
        s[i++] = ' ';
    }
    
    s[i] = '\0';

    reverse(s);
}