/* write a program to print a histogram of the freqencies of different characters in it's input. */
#include <stdio.h>

main() {
	int c;
	/* I will group whitespace, punctuation, alphanumeric and special characters into groups for clarity */
	/* I will also count capital ans lowercase characters the same */
	/* that means 26 characters + 4 grous */
	int hist[30];

	for (int i = 0; i < 29; i++) {
		hist[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (64 < c && c < 91) {
			++hist[c - 65];
		}
		else if (96 < c && c < 123) {
			++hist[c - 97];
		}
		else if (c == ' ' || c == '\t') {
			++hist[26];
		}
		else if (c == '.' || c == '!' || c == '?' || c == ';' || c == '\'' || c == '\"' || c == '(' || c == ')') {
			++hist[27];
		}
		else if (47 < c && c < 58) {
			++hist[28];
		}
		else {
			++hist[29];
		}
	}

	/* print a horizontal histogram for ease */
	for (int i = 0; i < 26; i++) {
		printf("[ %c]", i + 97);
		for (int o = 0; o < hist[i]; o++) {
			printf("-");
		}
		printf("\n");
	}
	printf("[ws]");
	for (int i = 0; i < hist[26]; i++) {
		printf("-");
	}
	printf("\n");

	printf("[pu]");
	for (int i = 0; i < hist[27]; i++) {
		printf("-");
	}
	printf("\n");
	printf("[an]");
	for (int i = 0; i < hist[28]; i++) {
		printf("-");
	}
	printf("\n");
	printf("[sp]");
	for (int i = 0; i < hist[29]; i++) {
		printf("-");
	}
	printf("\n");
}
