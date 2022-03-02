/* Write a program to "fold" long input lines into two or more shorter lines
 * after le last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intellingent with very long
 * lines, and if there are no blanks or tabs before the specified column. */
#include <stdio.h>

#define MAXLINE 1000
#define FOLD_LEN 10 /* fold lines longer that 80 characters */

int getline22(char line[], int max_length);
void fold_line(char line[]);

int main()
{
	int len;
	char line[MAXLINE];

	while((len = getline22(line, MAXLINE)) > 0) {
		fold_line(line);
		printf(line);
	}

	return 0;
}

/* getline22: read a line of input into a correctly formatted string and store
 *            it in s. Return the length of the string. The maximum length of a
 *            line must be provided as lim. */
int getline22(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	if (c == EOF)
		ungetc(c, stdin);
	return i;
}

/* fold_line: folds the line to fit the character limit. It does not
 *            differentiate between tabs and spaces for now. If there are no
 *            blanks on the line it adds a - character and a newline at the
 *            limit. */
void fold_line(char s[])
{
	int last_blank = 0;
	int last_newline = -1;
	
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == ' ' || s[i] == '\t')
			last_blank = i;
		if (s[i] == '\n')
			last_newline = i;
		if (i - last_newline >= FOLD_LEN) {
			/* First I check if there is a handy blank/newline at the limit.
			 * I do not differentiate between spaces and tabs for now. */
			if (s[i + 1] == ' ' || s[i + 1] == '\t' || s[i + 1] == '\n') {
				s[i + 1] = '\n';
				last_newline = i + 1;
			}
			/* If there is a blank on the line we fold there */
			else if (last_blank > 0 && i - last_blank < FOLD_LEN) {
				s[last_blank] = '\n';
				last_newline = last_blank;
			}
			else {
				int o = i;
				while (s[o] != '\0')
					++o;
				/* if the line is too long we'll lose characters, sadly.
				 * One possible solution for this would be to return the
				 * truncated characters */
				if (o == MAXLINE - 1)
					--o;
				if (o < MAXLINE - 2)
					++o;
				if (o < MAXLINE - 2)
					++o;
				while (o > i) {
					s[o] = s[o - 2];
					--o;
				}
				s[i] = '-';
				++i;
				s[i] = '\n';
				last_newline = i;
			}
		}
	}
}
