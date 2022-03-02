/* Verify that the expression
getchar() != EOF
is 1 or 0 */
#include <stdio.h>

main()
{
    int c;
    c = getchar() != EOF;
    printf("%i\n", c);
}