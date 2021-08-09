// Program to sort an array using quick sort algo
#include<stdio.h>
#include<rupesh.h>
#define MAX 20

int partition(int a[], int l, int r);
void quick_sort(int a[], int l, int r);

int main(void)
{
    int arr[MAX], size, i, l, r;
    printf("Enter size of the array: ");
    size = inputInt();

    l = 0, r = size-1;

    printf("\nEnter elements in the array\n");
    for(i =0 ; i<size; i++)
        *(arr+i) = inputInt();

    quick_sort(arr, l, r);

    printf("\nSorted array\n");
    for(i = 0; i<size; i++)
        printf("%d ", *(arr+i));

    return 0;
}


int partition(int a[], int l, int r)
{
    int i = l, j = r;
    int pivot = a[i];

    while(i<j)
    {
        while((a[i]<=pivot))
            i++;
        while(a[j]>pivot)
            j--;
        
        if(i<j)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        
    }

    a[l] = a[j];
    a[j] = pivot;

    return j;

}

void quick_sort(int a[], int l, int r)
{
    int pivloc;

    if(l>=r)
        return;

    pivloc = partition(a, l, r);
    quick_sort(a, l, pivloc-1);// process left subarray
    quick_sort(a, pivloc+1, r);// process right subarray
    
}