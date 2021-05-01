// Aditya Mitra
// 20BCE2044
// Prigram to implement Bubble Sort

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

void bub_sort(int arr[], int n) // Function to sort the array using buble sort
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

void disp(int arr[], int n) // Function to display the array
{
    int i;

    printf("\nThe sorted array : ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main() // Main function to drive the program
{
    int n;
    int arr[20];

    printf("Input the length of array : ");
    scanf("%d", &n);

    input(arr, n);

    bub_sort(arr, n);

    disp(arr, n);

    return 0;
}