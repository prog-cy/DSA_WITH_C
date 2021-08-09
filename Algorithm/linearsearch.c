// Program to search a element in an array using linear search algo
#include <stdio.h>
#include <rupesh.h>
#define MAX 20

int Linear_search(int arr[], int data, int size);

int main(void)
{
    int arr[MAX], size, index;
    int data;
    printf("Size of the array: ");
    scanf("%d", &size);

    printf("\nEnter element in the array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", arr + i);
    }

    printf("\nEnter data that you want to search: ");
    scanf("%d", &data);

    index = Linear_search(arr, data, size);
    if (index >= 0)
        printf("position of %d is %d\n", data, index + 1);
    if (index == -1)
        printf("%d is not in the given array\n", data);

    return 0;
}

// Function to search element sequentially
int Linear_search(int arr[], int data, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == data)
        {
            return i;
            break;
        }
    }

    if (i == size)
        return -1;
}