//Inrting element at front of the array
#include<stdio.h>

int main()
{
    int arr[10], size, i , num;

    printf("Enter the size of the array:\n");
    scanf("%d", &size);

    if(size>10)
        printf("Array overflow");
    else
    {
        printf("Enter elements in the array:\n");
        for(i=0;i<size;i++)
            scanf("%d",arr+i);
        
        printf("Before insertion\n");
        for(i=0;i<size;i++)
            printf("%d ", *(arr+i));

        printf("\nEnter the number:");
        scanf("%d",&num);

        for(i=size-1;i>=0;i--)
            arr[i+1] = arr[i];
            
        arr[0] = num;
        size++;

        printf("\nAfter insertion:\n");
        for(i=0;i<size;i++)
            printf("%d ", *(arr+i));
    }

    return 0;
    
}
