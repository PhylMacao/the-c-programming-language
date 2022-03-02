/* write a program to print a histogram of the lengths
of words in its input. */
#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

main()
{
    int c, len, state, hist_size;
    /* the longest word I could find is 45 letters. */
    hist_size = 45;
    int hist[hist_size];
    for (int i = 0; i < hist_size; i++) {
	    hist[i] = 0;
    }

    state = OUT;
    len = 0;
    while ((c = getchar()) != EOF) {
	len++;
	if (c == ' ' || c == '\n' || c == '\t') {
		state = OUT;
		hist[len - 2]++;
		len = 0;
	}
	else if (state == OUT) {
		state = IN;
	}
    }
    hist[len - 2]++;
    while (hist[hist_size-1] == 0)
	    hist_size--;

    /* vertical histogram */
    for (int i = 0; i < hist_size; i++) {
	    printf("[%2i]:", i+1);
	    for (int o = 0; o < hist[i]; o++) {
		    printf("-");
	    }
	    printf("\n");
	}

    /* horizontal histogram */
    int max = 0;
    for (int i = 0; i < hist_size; i++) {
	    if (hist[i] > max)
		    max = hist[i];
    }
    for (int i = 0; i < max; i++) {
	    for (int o = 0; o < hist_size; o++) {
		if (hist[o] >= max - i) {
			printf("  | ");
		} else
			printf("    ");
	    }
	    printf("\n");
    }
    for (int i = 0; i < hist_size; i++)
	    printf("[%2d]", i + 1);
    printf("\n");
}
