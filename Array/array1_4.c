//array operation
#include<stdio.h>

int main()
{
    int size,i;

    int arr[10];

    int *p = arr;

    printf("Enter the size: ");
    scanf("%d",&size);

    for(i=0;i<size;i++)
    {
        scanf("%d",arr+i);//&arr[i] = arr+i.
    }

    for(i=0;i<size;i++)
    {
        printf("%d %d %d %p\n", *arr+i, *(arr+i), *p ,arr+i);//arr[i] = *(arr+i) = *p/p++ != *arr+i 
        p++;
    }

    return 0;
}