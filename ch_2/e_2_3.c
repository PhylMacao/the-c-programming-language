/* Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 through 9, a through f, and A through F.
*/
#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_length);
int htoi(char s[]);

int main()
{
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0)
    {
		printf("%s\n", line);
        printf("%i\n", htoi(line));
    }
    
    return 0;
}

/* htoi: convert a string of hexadecimal digits into it's equivalent integer
 *       and returns it. If the given string is invalid it prints a message and
 *       returns 0;
*/
int htoi(char s[])
{
    int value = 0;
	int i = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		i = 2;
	}
	while (s[i] != '\0')
	{
		value *= 16;
		if (s[i] >= '0' && s[i] <= '9')
		{
			value += s[i] - 48;
		}
		else if (s[i] >= 'A' && s[i] <= 'F')
		{
			value += s[i] - 65 + 10;
		}
		else if (s[i] >= 'a' && s[i] <= 'f')
		{
			value += s[i] - 97 + 10;
		}
		else {
			printf("Invalid input, return 0.\n");
			return 0;
		}
		
		i++;
	}
	return value;
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