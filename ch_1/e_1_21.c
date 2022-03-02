/* Write a probram entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve
 * the same spacing. Use the same tab stop as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */
#include <stdio.h>

#define TABSTOP 4
#define MAXLINE 1000

int getline20(char line[], int max_length);
void entab(char line[]);
void printtabs(char line[]);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline20(line, MAXLINE)) > 0) {
		entab(line);
		printtabs(line);
	}
	return 0;
}

/* getline20: Read a line into s and return length.
 *            Return -1 if there are no more lines. */
int getline20(char s[], int lim)
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

/* entab: replace spaces with tabs where applicable */
void entab(char s[])
{
	int spaces = 0;
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == ' ')
			++spaces;
		else
			spaces = 0;
		if (spaces == TABSTOP) {
			i = i+1 - TABSTOP;
			s[i] = '\t';
			int o = i + 1;
			for (o = i + 1; s[o+TABSTOP-1] != '\0'; ++o)
				s[o] = s[o+TABSTOP-1];
			s[o] = s[o+TABSTOP-1];
			spaces = 0;
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
