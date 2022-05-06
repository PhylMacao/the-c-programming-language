/*
 * Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch . Write a function for the other direction as well, converting
 * escape sequences into the real characters.
*/
#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char line[MAXLINE];
    char line2[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        escape(line2, line);
        printf("escape()-d line: \n");
        printf(line2);
        printf("\nunescape()-d escape()-d line: \n");
        unescape(line, line2);
        printf(line);
    }

    return 0;
}

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

void escape(char s[], char t[])
{
    int pos = 0;
    for (int i = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\n':
            s[pos++] = '\\';
            s[pos++] = 'n';
            break;
        case '\t':
            s[pos++] = '\\';
            s[pos++] = 't';
            break;
        case '\v':
            s[pos++] =  '\\';
            s[pos++] =  'v';
            break;
        case '\b':
            s[pos++] =  '\\';
            s[pos++] =  'b';
            break;
        case '\r':
            s[pos++] =  '\\';
            s[pos++] =  'r';
            break;
        case '\f':
            s[pos++] =  '\\';
            s[pos++] =  'f';
            break;
        case '\a':
            s[pos++] =  '\\';
            s[pos++] =  'a';
            break;
        case '\\':
            s[pos++] =  '\\';
            s[pos++] =  '\\';
            break;
        case '\?':
            s[pos++] =  '\\';
            s[pos++] =  '\?';
            break;
        case '\'':
            s[pos++] =  '\\';
            s[pos++] =  '\'';
            break;
        case '\"':
            s[pos++] =  '\\';
            s[pos++] =  '\"';
            break;
        default:
            s[pos++] = t[i];
            break;
        }
    }
    s[pos] = '\0';
}

void unescape(char s[], char t[])
{
    int pos = 0;

    for (int i = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
        case '\\':
            switch (t[++i]) {
            case 'n':
                s[pos++] =  '\n';
                break;
            case 't':
                s[pos++] =  '\t';
                break;
            case 'v':
                s[pos++] =  '\v';
                break;
            case 'b':
                s[pos++] =  '\b';
                break;
            case 'r':
                s[pos++] =  '\r';
                break;
            case 'f':
                s[pos++] =  '\f';
                break;
            case 'a':
                s[pos++] =  '\a';
                break;
            case '\\':
                s[pos++] =  '\\';
                break;
            case '\?':
                s[pos++] =  '\?';
                break;
            case '\'':
                s[pos++] =  '\'';
                break;
            case '\"':
                s[pos++] =  '\"';
                break;
            default:
                s[pos++] = '\\';
                s[pos] = t[i];
                break;
            }
            break;
        default:
            s[pos++] =  t[i];
            break;
        }
    }
    s[pos] = '\0';
}