//Deleting element from specific position in an array
#include<stdio.h>

int main()
{
    int a[20], size, i, pos;

    printf("Enter the size of an array:");
    scanf("%d",&size);//taking the sizeof an array from the user
    //checking the bound of an array
    if(size>20)
        printf("Array is overflow");
        
    else
    {
        printf("\nEnter the elements in the array:\n");
        for(i=0;i<size;i++)
        {
            scanf("%d",a+i);
        }

        printf("\nElements in the array before deletion:\n");
        for(i=0;i<size;i++)
            printf("%d ",a[i]);

        printf("\nEnter the position from where you want to delete the element: ");
        scanf("%d", &pos);

        //logic for deleting an element at specific position
        if(pos<=0||pos>size)
            printf("invalid position");
        else
        {
            for(i=pos-1;i<size;i++)
                a[i] = a[i+1];
        }

        size--;

        for(i=0;i<size;i++)
            printf("%d ", a[i]);
    }
    
    return 0;

}