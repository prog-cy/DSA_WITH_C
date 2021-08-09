//program to display n natural number in reverse order
#include<stdio.h>

void Rdisplay(int n)
{
    if (n == 0)
        return;
    else
    {
        printf("%d ", n);
        Rdisplay(n-1);
    }
    
}

int main(void)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    Rdisplay(n);

    return 0;
}