/* Write the function any(s1,s2), which returns the first location in a string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no
 * characters from s2. (The standard library function strpbrk does the same job
 * but　returns a pointer to the location.)
*/
#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_length);
int any(char s1[], char s2[]);

int main()
{
    char line[MAXLINE];
    char line2[MAXLINE];

    printf("Please enter a line. (leave the line blank to exit)\n");
    while (get_line(line, MAXLINE) > 0) {
        printf("Please enter the characters you want to find.\n");
        get_line(line2, MAXLINE);
        printf("first occurence: %i\n\n", any(line, line2));
        printf("Please enter a line. (leave the line blank to exit)\n");
    }

    return 0;
}

/* get_line: read a line of input into a correctly formatted string and store
 *            it in s. Return the length of the string. The maximum length of a
 *            line must be provided as lim.
*/
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	// if (c == '\n') {
	// 	s[i] = c;
	// 	++i;
	// }
	s[i] = '\0';

	if (c == EOF)
		ungetc(c, stdin);
	return i;
}

/* any: returns the first location in s2 where any of the characters given in s2
 *      occurs. Returns -1 if it doesn't find any occurences.
*/

int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (int o = 0; o < s2[o] != '\0'; o++)
        {
            if (s1[i] == s2[o])
            {
                return i;
            }
        }
        
    }
    return -1;
}