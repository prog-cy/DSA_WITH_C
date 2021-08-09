//program to display and summation of series
#include<stdio.h>

int rseries(int n)
{
    if (n == 0)
        return 0;
    else
    {
        int sum = n + rseries(n-1);
        printf("%d + ", n);
        return sum;
    }
    
}

int main(void)
{
    int res, n;
    printf("Enter n: ");
    scanf("%d", &n);

    res = rseries(n);
    printf("\b\b= %d\n\n\n", res);

    return 0;
}