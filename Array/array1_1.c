//Declaring a 2-D array
#include<stdio.h>

int main()
{
    int i,j;

    int a[2][3] = {1,2,3,4,5,6};//first method to declare a 2-D array and initializing the element. 

    int b[2][2] ={{1,2},{3,4}};//second method to declare a 2-D array and initializing the element.

    int c[2][2];//Third method to declare a 2-D array.
    //storing the value in 2-D array

    c[0][0] = 1;
    c[0][1] = 4;
    c[1][0] = 5;
    c[1][1] = 6;

    //To print all the elements we will use two loops
    printf("\nFirst array elements:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    printf("\nSecond array elements:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

    printf("\nThird array elements:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    return 0;
}