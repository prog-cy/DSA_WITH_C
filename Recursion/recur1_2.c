// Program to find gcd of a number
#include<stdio.h>

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a%b);
    
}

int main(void)
{
    int n1, n2;
    printf("Enter numbers for which you want to calculate gcd: ");
    scanf("%d%d", &n1, &n2);

    int res = GCD(n1, n2);

    printf("GCD of %d and %d is %d", n1, n2, res);

    return 0;

}