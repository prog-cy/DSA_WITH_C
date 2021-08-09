//Declaring array 
#include<stdio.h>

int main()
{
    int a[5];//first way to declare an 1-D array
    //and storing the element in the array
    a[0] = 2;
    a[1] = 5;
    a[2] = 6;
    a[3] = 7;
    a[4] = 8;

    int b[] = {1,2,3,4,5};//second way to declare an 1-D array

    int c[5] = {2,3,4,5,6};//Third way to declare an 1-D array

    int d[5] = {};//This array will print 0 ;


    for (int i= 0;i<5;i++)
        printf("%d %d %d %d\n",a[i] ,b[i],c[i],d[i]);

    return 0;

}