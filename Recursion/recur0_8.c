//Program for base conversion using recursive function
#include <stdio.h>

void Bconvert(long int n, int base)
{
    if (n == 0)
        return;
    else
    {
        Bconvert(n/base, base);
        if(n%base<10)
            printf("%d", n % base);
        else
        {
            printf("%c", (n%base - 10)+ 'A');
        }
        
    
    }
}

int main(void)
{
    long int n;
    int base;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Number which you want to convert: ");
    scanf("%ld", &n);

    printf("Notation of %ld in %d: ", n, base);
    Bconvert(n, base);

    return 0;
}