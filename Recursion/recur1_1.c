// Program to display a fibbonacci series
#include<stdio.h>

int fibo(int n)
{
    if(n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        return (fibo(n-1) + fibo(n-2));
    }
    
}

int main()
{
    int term;
    printf("Enter total no. of term you want: ");
    scanf("%d", &term);
    printf("Fibonacci Series is\n");
    for(int i = 0; i<=term; i++)
        printf("%d ", fibo(i));

    return 0;
    
}

