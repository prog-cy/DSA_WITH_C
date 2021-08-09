//program to calculate sum of digits of a given positive integer using recursive function
#include <stdio.h>

int sumofdigits(int n)
{
    if (n / 10 == 0)
        return n;
    else
    {
        return (n % 10 + sumofdigits(n / 10));
    }
}

int main(void)
{
    int res, n;
    printf("Enter positive integer: ");
    scanf("%d", &n);

    res = sumofdigits(n);
    printf("Sum of digits of number %d is %d", n, res);

    return 0;
}