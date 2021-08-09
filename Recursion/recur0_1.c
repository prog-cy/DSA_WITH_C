//Recursion
/*Recursion is a method in which a function calls itself again and again until base condition is not
 found. */

 // Program to find Factorial of a number using recursive function
 #include<stdio.h>

 long int fact(int n)
 {
     if (n == 0)
        return 1;
    else
    {
        return (n*fact(n-1));
    }
 }

 int main(void)
{
    long int res;
    int n;
    
    printf("Enter number for that factorialyou want to calculate:  ");
    scanf("%d", &n);
    res = fact(n);

    printf("Factorial of %d is %ld\n", n, res);
    return 0;
}
    
