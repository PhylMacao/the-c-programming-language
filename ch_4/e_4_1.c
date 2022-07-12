/* Write the function strindex(s,t) which returns the position of the rightmost
 * occurrence of t in s, or -1 if there is none.
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline41(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
    /*char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0)
    {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }*/

    printf("%d\n", strindex("I stopped dreaming a long long time ago", "long"));
	return 0;
}

int getline41(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;   
}

/* Searching backwards would be a better option, but this requires minimal
 * changes.
*/
/*
int strindex(char s[], char t[])
{
    int i, j, k, pos;

    pos = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
        {
            pos = i;
        }
    }
    return pos;
}
*/
/* The bachwards searching function:*/
int strindex(char s[], char t[])
{
	for (int i = strlen(s) - 1, j; i >= 0; i--)
	{
		for (j = 0; s[i + j] == t[j] && t[j]; j++);
		if (!t[j])
			return i;
	}
	return -1;
}
