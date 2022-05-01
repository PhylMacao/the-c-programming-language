/*
 * Our binary search makes two tests inside the loop, when one would suffice (at
 * the price of more tests outside.) Write a version with only one test inside
 * the loop and measure the difference in run-time.
*/
#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int v[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", binsearch(i, v, 5));
    }
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return v[high] == x ? high : -1;
}