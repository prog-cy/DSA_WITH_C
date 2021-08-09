//Program to display n natural number using recursive function
#include<stdio.h>

void display(int n)
{
    if(n == 0)
        return;
    else
    {
        display(n-1);
        printf("%d ", n);
    }
    
}

int main(void)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    display(n);

    return 0;
}