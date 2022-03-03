/* Write a program to determine the ranges of char, short, int and long
 * variables, both signed and unsigned, by printing approppriate values from
 * headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("       MIN       MAX TYPE\n");
	printf("%11d %11d char\n", CHAR_MIN, CHAR_MAX);
	printf("%11d %11d signed char\n", SCHAR_MIN, SCHAR_MAX);
	printf("%11d %11d int\n", INT_MIN, INT_MAX);
	printf("%11u %11u unsigned int\n", 0, UINT_MAX);
	printf("%11d %11d short\n", SHRT_MIN, SHRT_MAX);
	printf("%11u %11u unsigned short\n", 0, USHRT_MAX);
	printf("%11ld %11ld long\n", LONG_MIN, LONG_MAX);
	printf("%11u %11lu unsigned long\n", 0, ULONG_MAX);
	printf("\n");
	printf("%f %f float\n", FLT_MIN, FLT_MAX);
	printf("%f %f double\n", DBL_MIN, DBL_MAX);

	/* the computational part isn't hard but makes little sense after having
	 * everything printed out so I skip it. */
	return 0;
}
