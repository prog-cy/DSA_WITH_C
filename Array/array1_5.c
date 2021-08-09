#include <stdio.h>

int main()
{
    int *p, i, size, count = 0;

    int arr[10];

    p = arr;

    printf("Enter the size:\n");
    scanf("%d", &size);

    if (size > 10)
        printf("Array overflow\n");
    else
    {
    for (i = 0; i < size; i++)
    {
        //arr[i] = *(p+i) = *p/p++.
        *p = ++count;
        p++;
    }

    p = arr;//here we have assigned address of array again because in above loop address is incremented so we have to assign again arr to p
    for (i = 0; i < size; i++)
        printf("%d ", *(p + i));
    }

    return 0;
}