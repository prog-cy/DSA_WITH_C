// Program to sort a given set of data using shell sort
#include<stdio.h>
#include<rupesh.h>
#define MAX 100

int main(void)
{
    int arr[MAX], size, gap, data;
    printf("Enter size of the array: ");
    size = inputInt();

    data = size;

    for(int i = 0; i<size; i++)
    {
        *(arr + i) = data;
        data--;
    }
    
    printf("\nData before sorting\n");
    for(int i = 0; i<size; i++)
        printf("%d ", *(arr+i));
    
    printf("\n\nEnter gap(odd): ");
    gap = inputInt();

    while(gap>=1)
    {
        for (int i = gap; i<size; i++)
        {
            int k = arr[i], j;
            for(j = i-gap; j>=0 && k<arr[j]; j = j-gap)
                    arr[j+gap] = arr[j];
            arr[j+gap] = k;
        }

        gap = gap-2;
    }

    printf("\nSorted list\n");
    for(int i = 0; i<size; i++)
        printf("%d ", *(arr+i));

    return 0;
}


