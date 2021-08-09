//Program to check that array's element stores in contiguous memory

#include<stdio.h>

int main()
{
    int n = 30 ,arr[n];//it is also a way to declare an array
    int size,i;

    printf("Enter the size of the array: ");
    scanf("%d",&size);

    printf("\nEnter the elements in the array:\n");
    for(i=0;i<size;i++)
        scanf("%d", &arr[i]);

    printf("Array Elements with their address:\n");

    for(i=0;i<size;i++)
    {
        printf("Address of %d = %p\n",arr[i], &arr[i]);
    }

    for (i = 0; i < size; i++)
    {
        printf("Address of %d = %lu\n", arr[i], &arr[i]);
    }

    for (i = 0; i < size; i++)
    {
        printf("Address of %d = %u\n", arr[i], &arr[i]);
    }

    return 0;


}