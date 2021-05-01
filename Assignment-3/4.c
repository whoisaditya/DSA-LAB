// Aditya Mitra
// 20BCE2044
// Prigram to implement Insertion Sort

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

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insert_sort(int arr[], int n) // Function to sort the array using buble sort
{
    int i, key, j;

    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
 
        //Move elements of arr[0..i-1], that are
        //greater than key, to one position ahead
        // of their current position

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() // Main function to drive the program
{
    int n;
    int arr[20];

    printf("Input the length of array : ");
    scanf("%d", &n);

    input(arr, n);

    insert_sort(arr, n);

    disp(arr, n);

    return 0;
}