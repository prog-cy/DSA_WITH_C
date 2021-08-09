// Program to calculate sum of first n natural number using recursive function

#include<stdio.h>

int sumofnumber(int n)
{
    int sum;
    if (n == 0)
        return 0;
    else
    {
        sum = n + sumofnumber(n-1);
        return sum;
    }
    
}

int main(void)
{
    int res, n;

    printf("Enter n: ");

    scanf("%d", &n);
    
    res = sumofnumber(n);
    printf("Sum of first %d integers is %d", n, res);

    return 0;
}