//performing all operations in 2-D array
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r, c, i, j, count=0;

    printf("Enter the row and column of a matrix: ");
    scanf("%d%d",&r,&c);

    int *arr = (int *)calloc(r*c, sizeof(int));//creating 2-D array in 1-D array

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            *(arr+i*c+j) = ++count;
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",*(arr+i*c+j));
        
        printf("\n");
    }

    return 0;
}