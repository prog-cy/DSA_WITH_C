//Sorting an array in descending order
#include<stdio.h>

int main()
{
    int a[20], size , i, j ,t;

    printf("Enter the size  of the arrray: ");
    scanf("%d",&size);

    printf("\nEnter the array elements:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\nArray Elements:\n");
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
    
    printf("\n\nSorted array in descending order\n");

    //logic for sorting an array elements in descending order
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(a[i]<a[j])
            {
                t = a[i];
                a[i]= a[j];
                a[j] = t;
            }
        }
    }

    for(i=0;i<size;i++)
        printf("%d ",a[i]);
    
    return 0;
}