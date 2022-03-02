/* Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time. */
#include <stdio.h>

#define MAXLINE 1000

int getline19(char line[], int len);
void reverse(char s[]);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline19(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

/* getline19: Read a line into s and return length.
 *            Return -1 if there are no more lines. */
int getline19(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == EOF && i == 0)
		return -1;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* reverse: reverse the string given. */
void reverse(char s[])
{
	int len;
	for (len = 0; len < MAXLINE && s[len] !='\0'; ++len) {}
	if (s[len] == '\0')
		len--;
	if (s[len] == '\n')
		len--;
	char temp;
	for (int i = 0; i <= (len-1) / 2; i++) {
		temp = s[i];
		s[i] = s[len - i];
		s[len - i] = temp;
	}
}
