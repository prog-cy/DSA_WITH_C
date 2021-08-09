//checking bound of an array 

#include<stdio.h>

int main()
{
    int a[6], size, i;

    printf("Enter the size of array: ");

    scanf("%d",&size);

    printf("\n");
    //here we are checking the boundation of an array
    if(size>6)
        printf("Array is overflow");

    else
    {
        for(i=0;i<size;i++)
            scanf("%d", a+i);//here a+i is depicted the address &a[i] = a+i

        for(i=0;i<size;i++)
            printf("%d ",*(a+i));//*(a+i) is printing the value at address a[i]= *(a+i)
    }

    printf("\n\n");

    return 0;
    
}