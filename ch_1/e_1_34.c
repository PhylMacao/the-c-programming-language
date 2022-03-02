/* Write a program to check a C program for rudimentary syntax errors like
 * unmatched parentheses, brackets and braces. Don't forget about quotes, both
 * single and double, escape sequences, and comments. (This program is hard if
 * you do it in full generality) -> I will simplify it for the sake of progress.
 */
#include <stdio.h>

#define MAXLINE 1000
#define IN 1
#define OUT 0

int get_input(char line[], int max);
int check(char s[]);

int main()
{
	int len;
	char s[MAXLINE];

	while ((len = get_input(s, MAXLINE)) > 0)
		check(s);

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

int check(char s[])
{
	int com, str, squote;
	com = str = squote = OUT;
	int pars, bras, curlys;
	pars = bras = curlys = 0;
	int start = 0;
	int line = 1;
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '\n') {
			++line;
		} else if (com) {
			if (s[i-1] == '*' && s[i] == '/')
				com = OUT;
		} else if (str) {
			if (s[i] == '"')
				str = OUT;
		} else if (squote) {
			if (s[i] == '\'')
				squote = OUT;
		}else {
			if (s[i - 1] == '/' && s[i] == '*') {
				com = IN;
				start = line;
			} else if (s[i] == '"') {
				str = IN;
				start = line;
			} else if (s[i] == '\'') {
				squote = IN;
				start = line;
				if (s[i+2] != '\'' || s[i+3] != '\'') {
					printf("Unmatced ' character on line %d!\n", start);
					return 1;
				}
			} else if (s[i] == '(') {
				++pars;
			} else if (s[i] == ')') {
				--pars;
			} else if (s[i] == '[') {
				++bras;
			} else if (s[i] == ']') {
				--bras;
			} else if (s[i] == '{') {
				++curlys;
			} else if (s[i] == '}') {
				--curlys;
			}
		}
	}
	if (pars) {
		printf("Unmatched parentheses!\n");
		return 1;
	}
	if (bras) {
		printf("Unmatched brackets!\n");
		return 1;
	}
	if (curlys) {
		printf("Unmatched curly braces!\n");
		return 1;
	}
	if (com) {
		printf("Unfinished comment on line %d!\n", start);
		return 1;
	}
	if (str) {
		printf("Unfinished string on line %d!\n", start);
		return 1;
	}
	return 0;
}
