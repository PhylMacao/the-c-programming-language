/* Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
 * every n columns.  Should n be a variable or a symbolic character? */
#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 4

int getline21(char line[], int max_length);
void detab(char line[]);
void printtabs(char line[]);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline21(line, MAXLINE)) > 0) {
		detab(line);
		printtabs(line);
	}

	return 0;
}

/* getline21: Read a line into s and return length.
 *            Return -1 if there are no more lines. */
int getline21(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	if (c == EOF && i == 0)
		return -1;
	return i;
}

/* detab: remove tabs form a string */
void detab(char s[])
{
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '\t') {
			int o = i;
			while (s[o] != '\0')
				++o;
			o = o + TABSTOP - 1;
			while (o != i + TABSTOP - 1) {
				s[o] = s[o - TABSTOP + 1];
				--o;
			}
			for (int k = 0; k < TABSTOP; ++k)
				s[i + k] = ' ';
		}
	}
}

void printtabs(char s[])
{
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '\t')
			printf("\\t");
		else
			putchar(s[i]);
	}
}
