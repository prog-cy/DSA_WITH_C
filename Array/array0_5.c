//Inserting elements at specific position in an array
#include <stdio.h>

int main()
{
    int a[20], size, i, num, pos;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > 20)
        printf("Array is overflow");

    else
    {

        printf("\nEnter the array elements:\n");
        for (i = 0; i < size; i++)
        {
            scanf("%d", a + i);
        }

        printf("\nArray elements before inserting at specific position:\n");
        for (i = 0; i < size; i++)
            printf("%d ", a[i]);

        printf("\nInserting element at specific position:\n");

        printf("\nEnter the element that you want to enter: ");
        scanf("%d", &num);

        printf("\nEnter the position at which you want to enter the element:");
        scanf("%d", &pos);

        //logic  for inserting element at specific position
        if(pos<=0 || pos>size)
            printf("invalid position");

        else
        {
            for (i = size - 1; i >= pos - 1; i--)
            {
                a[i + 1] = a[i];
            }

            a[pos - 1] = num;
            size++;
        }
        
        printf("\nArray elements after inserting element at specific position:\n");
        for (i = 0; i < size; i++)
            printf("%d ", a[i]);
    }

    return 0;

    
}