//Inserting element at end of the array
#include<stdio.h>

int main()
{
    int arr[10], size, num, i;

    printf("Enter the size of the array: \n");
    scanf("%d",&size);

    if(size>10)
        printf("Array is overflow");
    else
    {
        printf("Enter the array elements:\n");
        for(i=0;i<size;i++)
            scanf("%d", arr+i);
        
        printf("Before insertion:\n");
        for(i=0;i<size;i++)
            printf("%d ", *(arr+i));

        printf("\nEnter the number: ");
        scanf("%d", &num);

        //logic for inserting at end of the array
        arr[size] = arr[size-1];
        arr[size-1] = num;
        size++;

        printf("\nAfter Insertion:\n");
        for(i=0;i<size;i++)
            printf("%d ",*(arr+i));
        
        printf("\n");

    }

    return 0;
    
}