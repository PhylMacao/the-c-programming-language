/* Write a function expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2. Allow for
 * letters of either case and digits, and be prepared to handle cases like a-b-c
 * and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
*/

#include <stdio.h>
#include <ctype.h>

/* I tried to write these, but they are actually built in
int islower(char c);
int isupper(char c);
int isdigit(char c);
*/
void expand(char s1[], char s2[]);

int main()
{
    char output[1000];

    expand("The abc: a-z\n", output);
    printf(output);
    expand("The same but with upper characters: A-Z\n", output);
    printf(output);
    expand("Numbers: 0-9\n", output);
    printf(output);
    expand("Reverse: 9-0\n", output);
    printf(output);
    expand("Multiple -: a-c-g\n", output);
    printf(output);
    expand("Invalid1: 0-a\n", output);
    printf(output);
    expand("Invalid2: a-Z\n", output);
    printf(output);
    expand("Invalid3: 0-Z\n", output);
    printf(output);
    expand("Invalid4: 0-\n", output);
    printf(output);
    expand("Invalid5: -a\n", output);
    printf(output);
    expand("Additional -: -0-a-\n", output);
    printf(output);
    return 0;
}

/*
int islower(char c)
{
    if (97 <= c && c <= 122)
        return 1;
    else
        return 0;
    
}

int isupper(char c)
{
    if (65 <= c && c <= 90)
        return 1;
    else
        return 0;
}

int isdigit(char c)
{
    if (48 <= c && c <= 57)
        return 1;
    else
        return 0;
}
*/
void expand(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        // we just have to copy until we hit a -
        if (s1[i] != '-') {
            s2[j++] = s1[i];
            continue;
        }
        //check if there is a valid character before and after the -
        int diff = s1[i + 1] - s1[i - 1];
        int dir = (diff > 0) - (diff < 0);

        if ((isdigit(s1[i - 1]) && isdigit(s1[i + 1])) ||
            (islower(s1[i - 1]) && islower(s1[i + 1])) ||
            (isupper(s1[i - 1]) && isupper(s1[i + 1]))) {
            for (char o = s1[i - 1] + dir; o != s1[i + 1]; o += dir) {
                s2[j++] = o;
            }
        }
        else {
            s2[j++] = s1[i];
        }
    }
    s2[j++] = '\0';
}