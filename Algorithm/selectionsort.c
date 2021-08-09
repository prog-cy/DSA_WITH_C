// Program to sort a list using selection sort method
#include <stdio.h>
#include <rupesh.h>
#define MAX 20

void selection_sort(int a[], int n);
void desc_sort(int a[], int n);

int main(void)
{
    int arr[MAX], i, size;
    printf("Enter size of the array: ");
    size = inputInt();

    printf("\nEnter element in the arrray\n");
    for (i = 0; i < size; i++)
        *(arr + i) = inputInt();

    selection_sort(arr, size);
    printf("\nSorted list\n");
    for (i = 0; i < size; i++)
        printf("%d ", *(arr + i));
    
    desc_sort(arr, size);
    printf("\n\nList element in descending order\n");
    for (i = 0; i < size; i++)
        printf("%d ", *(arr + i));

    printf("\n\n");

    return 0;
}

// Function for selection sort
void selection_sort(int a[], int n)
{
    int i, j, min, t;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)// this is for finding min element from the list
        {
            if (a[min] > a[j])
                min = j;
        }

        if (i != min)// this is for swapping the min elemement with their appropriate index
        {
            t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
    }
}


// Function for sorting descending order
void desc_sort(int a[], int n)
{
    int l, r, i, j;

    i = 0, j = n-1;

    while(i<j)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++, j--;
    }
}