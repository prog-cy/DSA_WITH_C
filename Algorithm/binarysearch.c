// Program to search element in a list using binary search algo
#include <stdio.h>
#include <rupesh.h>
#define MAX 20

int Binary_search(int arr[], int s, int data);
int main(void)
{
    int arr[MAX], size, index;
    int data;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("\nEnter elements in the array in ascending order\n");
    for (int i = 0; i < size; i++)
        scanf("%d", arr + i);

    printf("\nEnter data that you want to search: ");
    scanf("%d", &data);

    index = Binary_search(arr, size, data);

    if (index == -1)
        printf("%d is not in the list\n", data);
    else
        printf("%d is at position %d\n", data, index+1);

    return 0;
}

// Function for Binary search 
int Binary_search(int arr[], int s, int data)
{
    int i, mid;

    int l = 0, r = s-1;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (arr[mid] < data)
            l = mid + 1;
        else if (arr[mid] > data)
            r = mid - 1;
        else
            return mid;
    }

    return -1;
}