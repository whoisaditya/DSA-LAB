
// Aditya Mitra
// 20BCE2044
// Program to print the number of comparisons of different sorting algorithms 

#include <stdio.h>

int quick;

void input(int arr[], int n) // Function to take the input
{
    int i;

    printf("\nEnter the array\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void swap(int *x, int *y) // Function to swap integers
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}


/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot, i, j;

    i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far
    pivot = arr[high]; // pivot

    for (j = low; j < high; j++)
    {
        quick++;

        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(arr + i, arr + j);
        }
    }
    swap(arr + i + 1, arr + high);

    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quick_sort(int arr[], int low, int high)
{
    quick++;

    if (low < high)
    {

        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
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

int main() // Main function to drive the program
{
    int n, i;
    int arr[20];

    quick = 0;

    printf("Input the length of array : ");
    scanf("%d", &n);

    input(arr, n);

    quick_sort(arr, 0, n - 1);

    disp(arr, n);
    printf("\n");
    printf("No. of comparisons: %d\n", quick);

    return 0;
}