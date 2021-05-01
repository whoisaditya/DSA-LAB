// Aditya Mitra
// 20BCE2044
// Prigram to implement Selection Sort

#include <stdio.h>

void swap(int *x, int *y) // Function to swap integers
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void input(int arr[], int n) // Function to take the input
{
    int i;

    printf("\nEnter the array\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void disp(int arr[], int n) // Function to display the array
{
    int i;

    printf("\nThe sorted array : ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void selection_sort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
       
        swap(arr + min_idx, arr + i);  // Swap the found minimum element with the first element
    }
}

int main() // Main function to drive the program
{
    int n;
    int arr[20];

    printf("Input the length of array : ");
    scanf("%d", &n);

    input(arr, n);

    selection_sort(arr, n);

    disp(arr, n);

    return 0;
}