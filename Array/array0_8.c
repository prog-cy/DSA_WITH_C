//Using pointer creating an array
#include<stdio.h>

int main()
{
    int *p, size, i;

    int a[10];

    p =a;

    printf("Enter the size of the array: ");
    scanf("%d",&size);

    for(i=0;i<size;i++)
    {
       scanf("%d",p+i);
    }

    printf("\nArray elements:\n");
    for(i=0;i<size;i++)
    {
        
        printf("%d ", *(p+i));
    }

    return 0;

}