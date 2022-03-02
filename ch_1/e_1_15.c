/* rewrite the temperature conversion progmram of Section 1.2 to use a function for conversion */
#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahr);

int main()
{
	float lower = 0;
	float upper = 300;
	float step = 20;

	printf(" C     F\n");
	for (float celsius = lower; celsius <= upper; celsius = celsius + step) {
		printf("%3.0f %6.1f\n", celsius, celsius_to_fahrenheit(celsius));
	}

	printf(" F     C\n");
	for (float fahr = lower; fahr <= upper; fahr = fahr + step) {
		printf("%3.0f %6.1f\n", fahr, fahrenheit_to_celsius(fahr));
	}
	return 0;
}

float celsius_to_fahrenheit(float celsius)
{
	float fahr = ((9.0/5.0) * celsius) + 32;
	return fahr;
}

float fahrenheit_to_celsius(float fahr)
{
	float celsius = (5.0/9.0) * (fahr - 32.0);
	return celsius;
}
