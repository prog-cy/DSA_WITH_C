//find the sum of rows , columns and diagonal  of a matrix.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r = 3, c = 3, i, j;

    int *rsum = (int *)malloc(r * sizeof(int)); //1-D array to store row sum

    int *csum = (int *)malloc(c * sizeof(int)); //1-D array to strore column sum

    int dsum = 0;

    //creating 2-D array using array of pointer
    int *arr[r];
    for (i = 0; i < r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            scanf("%d", (*(arr + i) + j));
    }

    //logic for summation of  row elements.

    printf("%-10s%25s\n", "Matrix", "Sum of row elements");
    for (i = 0; i < r; i++)
    {
        rsum[i] = 0;
        for (j = 0; j < c; j++)
        {
            printf("%-3d ", *(*(arr + i) + j));
            rsum[i] = rsum[i] + arr[i][j];
        }

        printf("%10d\n", rsum[i]);
    }

    printf("\n");
    //logic for summation of column elements.
    for (i = 0; i < c; i++)
    {
        csum[i] = 0;
        for (j = 0; j < r; j++)
        {
            csum[i] = csum[i] + arr[j][i];
            if (i == j)
                dsum = dsum + arr[i][j];
        }

        printf("%-3d ", csum[i]);
    }

    printf("%10d", dsum);
    printf("\n");
    printf("sum of column and diagonal elements\n");

    return 0;
}