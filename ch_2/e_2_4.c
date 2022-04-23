/* Write an alternative version of squeeze(s1,s2) that deletes each character in
 * s1 that matches any character in the string s2.
*/
#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_length);
void sqeeze(char s1[], char s2[]);

int main()
{
    char line[MAXLINE];
    char line2[MAXLINE];

    printf("Please enter a line. (leave the line blank to exit)\n");
    while (get_line(line, MAXLINE) > 0)
    {
        printf("Please enter the characters you want to remove.\n");
		get_line(line2, MAXLINE);
        sqeeze(line, line2);
        printf("Result:\n%s\n\n", line);
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

/* sqeeze: deletes each character in s1 that matches any character in s2 */
void sqeeze(char s[], char s2[])
{
    char c;
    for (int o = 0; o < (c = s2[o]) != '\0'; o++)
    {
        int i, j;
        for (i = j = 0; s[i] != '\0'; i++)
            if (s[i] != c)
                s[j++] = s[i];
        s[j] = '\0';
    }
}