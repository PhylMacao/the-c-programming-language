/* Write a loop equivalent to the for loop above without using && or ||.
*/
#include <stdio.h>

#define MAXLINE 1000

int main()
{
    char line[MAXLINE];
    int c;

    int i = 0;
    while (i < MAXLINE - 1) {
        if((c = getchar()) == '\n') {
            break;
        }
        if(c == EOF) {
            break;
        }
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    printf("%s\n", line);

    return 0;
}