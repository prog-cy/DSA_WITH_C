//Traversing the array elements means accessing the elements one by one
#include <stdio.h>

int main()
{
    int arr[20], size, i;

    printf("Enter the size of an array: ");
    scanf("%d", &size);

    if (size > 20)
    {
        printf("Array is overflow");
    }

    else
    {
        printf("\nEnter the array elements:\n");
        for (i = 0; i < size; i++)
        {
            scanf("%d", arr + i);
        }

        for (i = 0; i < size; i++)
        {
            printf("%d ", *(arr + i));
        }
    }

    return 0;
}