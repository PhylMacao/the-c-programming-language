/* Revise the main routine of the longest-line program so it will correctly print the length of arbitrary
 * long input lines, and as much as possible of the text */
#include <stdio.h>
#define MAXLINE 1000 /*maximum input line length */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	int carry;	/* counter for MAXLINE overflow */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	carry = 0;
	while ((len = getline2(line, MAXLINE)) > 0) {
		/* idea: carry the number of full lines except the '\0' character
		 * and add it to max at the end of the line */
		if (len + (carry*(MAXLINE-1)) > max) {
			max = len + (carry*(MAXLINE-1));
			copy(longest, line);
		}
		if (longest[len - 1] != '\n')
			++carry;
		else
			carry = 0;
	}
	if (max > 0) /* there was a line */
		printf("\n\n%s\nLength of the longest line: %i\n", longest, max);
	return 0;
}

/* getline2: read a line into s, return length */
int getline2(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
