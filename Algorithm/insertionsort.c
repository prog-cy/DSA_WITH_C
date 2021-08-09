// Program to sort an array using insertion sort
#include <stdio.h>
#include <rupesh.h>
#define MAX 20

void insertion_sort(int a[], int n);

int main(void)
{
    int arr[MAX], i, size;
    printf("Enter size of the array: ");
    size = inputInt();

    printf("\nEnter elements in the array\n");
    for (i = 0; i < size; i++)
        *(arr + i) = inputInt();

    insertion_sort(arr, size);

    printf("\nSorted list\n");
    for (i = 0; i < size; i++)
        printf("%d ", *(arr + i));

    return 0;
}

void insertion_sort(int a[], int n)
{
    int i, j, k;

    for (i = 1; i < n; i++)
    {
        k = a[i];
        for (j = i - 1; j >= 0 && k<a[j]; j--)
            a[j+1] = a[j];
        a[j+1] = k;
    }
}