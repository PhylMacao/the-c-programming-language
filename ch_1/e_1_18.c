/* Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely
 * blank lines */
#include <stdio.h>

#define MAXLINE 1000 /* max length of a line */

int get_clean_line(char line[], int max_length);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_clean_line(line, MAXLINE)) > 0)
		if (len > 1)
			printf("[len %i]: %s", len, line);

	return 0;
}

/* getline2: Read a line into s and return length after removing trailing blanks.
 *           Return -1 if there are no more lines */
int get_clean_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == EOF && i == 0)
		return -1;
	if (c == '\n')
		--i;
	while (s[i] == '\t' || s[i] == ' ') {
		--i;
	}
	++i;
	s[i] = '\n';
	++i;
	s[i] = '\0';
	return i;
}
