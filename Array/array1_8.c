//array and double pointer
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[10] , size, i, count=0;

    int *p, **ptr;

    printf("Enter the size: ");
    scanf("%d",&size);

    p = a;

    ptr = &p;

    for(i=0; i<size; i++)
    {
        scanf("%d",(*ptr+i));
    }

    for(i=0; i<size; i++)
    {
        printf("%d %d %p %p\n",*(p+i),*(*ptr+i), p+i, *ptr+i);
    }

    return 0;
}