// program to calculate exponent of a given number by a positive integer

#include<stdio.h>

float power(int a, int n)
{
    if (n == 0)
        return 1;
    else
    {
        return (a * power(a, n-1));
    }
    
}

int main(void)
{
    int a, n;
    float p;
    printf("Enter a and n: ");
    scanf("%d%d", &a , &n);

    p = power(a, n);

    printf("%d raised to power %d is %.0f\n", a, n, p);

    return 0;
}

