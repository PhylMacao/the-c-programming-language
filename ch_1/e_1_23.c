/* Write a program to remove all comments from a C program. Don't forget to
 * handle quoted string and character constants properly. C comments don't nest.
 */
#include <stdio.h>

#define MAXLINE 1000
#define IN 1
#define OUT 0

int get_input(char line[], int max);
void del(char s[], int start, int end);
void decomment(char source[]);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_input(line, MAXLINE)) > 0) {
		decomment(line);
		printf(line);
	}

	return 0;
}

int get_input(char line[], int max)
{
	int i, c;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF; ++i)
		line[i] = c;
	line[i] = '\0';
	return i;
}

/* del: delete a part of a string. start and end must be inside the string. */
void del(char s[], int start, int end)
{
	int gap = end - start;
	int i;
	for (i = start; s[i + gap] != '\0'; ++i)
		s[i] = s[i + gap];
	s[i] = s[i + gap];
}

void decomment(char s[])
{
	int com, str, com_start;
	com = str = OUT;
	for (int i = 1; s[i] != '\0'; ++i) {
		if (s[i-1] == '"' && !com)
			str = !str;
		else if (s[i-1] == '/' && s[i] == '*' && !com && !str) {
			com = IN;
			com_start = i - 1;
		}
		else if (s[i-1] == '*' && s[i] == '/' && com && !str) {
			del(s, com_start, i + 1);
			i = com_start;
			com = OUT;
		}
	}
}
