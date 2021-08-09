// Program to reverse a positive integer using recursive function
#include <stdio.h>

void Rposnum(int n)
{
    if (n / 10 == 0)
    {
        printf("%d", n);
        return;
    }

    printf("%d", n % 10);
    Rposnum(n / 10);
}

int main(void)
{
    int n;
    printf("Enter positive number: ");
    scanf("%d", &n);

    printf("Number in revers oreder: ");
    Rposnum(n);

    return 0;
}