// Program to calculate the prime factorization of a given number
#include<stdio.h>

int PFact(int n)
{
    int i = 2;
    if (n == 1)
        return 1;
    while (n%i != 0)
        i++;
    printf("%d x ", i);
    return i*PFact(n/i);  
    
}


int main(void)
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    printf("\b\b = %d\n\n", PFact(num));

    return 0;
}