//array and pointer
#include <stdio.h>

int main()
{
    int a[20], i, size;

    int *p; //pointer to integer

    printf("Enter the size of an array: ");
    scanf("%d", &size);

    p = a; //'a' array name always contains the address of the first element

    if (size > 20)
        printf("Array is overflow");

    else
    {
        printf("\nEnter the array elements:\n");
        for (i = 0; i < size; i++)
        {
            scanf("%d", p);
            p++;
        }

        p = a;
        /*Here we  are again assigning the address of array to pointer because  increment  operator increases the value of the pointer p  in above loop and we have to set the value of the pointer at initial address of the array again*/

        printf("\nArray elements:\n");
        for (i = 0; i < size; i++)
        {
            printf("%d ", *p);
            p++;
        }
    }

    return 0;
}