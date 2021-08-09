// Program to sort an array using bubble
#include<stdio.h>
#define MAX 20

void bubble_sort(int arr[], int n) ;
int main(void)
{
    int a[MAX], size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("\nEnter data in the array\n");
    for(int i = 0; i<size; i++)
        scanf("%d", a+i);

    bubble_sort(a, size);

    printf("sorted list is\n");
    for(int i = 0; i<size; i++)
        printf("%d ", a[i]);

    return 0;
}

// Function to sort an array
void bubble_sort(int arr[], int n)
{
    int i, j, t;
    int flag;

    for(i = 0; i<n-1; i++)
    {
        flag = 0;
        for(j = 0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                t   =  arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}