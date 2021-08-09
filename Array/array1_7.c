#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r, c, i, j, count=0;

    printf("Enter the row and column: ");
    scanf("%d%d",&r,&c);

    int **arr = (int **)malloc(r*sizeof(int*));
    for(i=0;i<r;i++)
        arr[i] = (int *)calloc(c, sizeof(int));

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            *(*(arr+i)+j) = ++count;//arr[i][j] = *(*(arr+i)+j) and  &arr[i][j] = (*(arr+i)+j)
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d %p %p %p %p\n",*(*(arr+i)+j), *(arr+i)+j, ((*arr+i)+j), arr+i+j, *(arr+i));
        }
    }

    return 0;
}