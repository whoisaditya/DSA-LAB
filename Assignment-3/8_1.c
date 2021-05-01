

// Aditya Mitra
// 20BCE2044
// Program to print the number of comparisons of different sorting algorithms

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bub, insert, selc, quick, mer;

void swap(int *x, int *y) // Function to swap integers
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void arr_gen(int arr[], int n) // Function to take the input
{
    int i;

    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 99999;
    }
}

void bub_sort(int arr[], int n) // Function to sort the array using buble sort
{
    int i, j, flag;

    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            bub++;

            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void insert_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key)
        {
            insert++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
            selc++;

            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        swap(arr + min_idx, arr + i); // Swap the found minimum element with the first element
    }
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

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        mer++;

        if (L[i] <= R[j])
        {

            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        mer++;

        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        mer++;

        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void merge_sort(int arr[], int l, int r)
{
    mer++;

    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void disp(int n) // Function to display the array
{
    int i;

    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", n, bub, insert, selc, quick, mer);
}

int main() // Main function to drive the program
{
    int n1, n2, n3, n4, n5, i;
    int arr1[1000], arr2[1500], arr3[2000], arr4[2500], arr5[3000];
    int arr1_1[1000], arr2_1[1500], arr3_1[2000], arr4_1[2500], arr5_1[3000];
    int arr1_2[1000], arr2_2[1500], arr3_2[2000], arr4_2[2500], arr5_2[3000];
    int arr1_3[1000], arr2_3[1500], arr3_3[2000], arr4_3[2500], arr5_3[3000];
    int arr1_4[1000], arr2_4[1500], arr3_4[2000], arr4_4[2500], arr5_4[3000];

    n1 = 1000;
    n2 = 1500;
    n3 = 2000;
    n4 = 2500;
    n5 = 3000;

    arr_gen(arr1, n1);
    arr_gen(arr2, n2);
    arr_gen(arr3, n3);
    arr_gen(arr4, n4);
    arr_gen(arr5, n5);

    for (i = 0; i < n1; i++)
    {
        arr1_1[i] = arr1[i];
        arr1_2[i] = arr1[i];
        arr1_3[i] = arr1[i];
        arr1_4[i] = arr1[i];
    }

    for (i = 0; i < n2; i++)
    {
        arr2_1[i] = arr2[i];
        arr2_2[i] = arr2[i];
        arr2_3[i] = arr2[i];
        arr2_4[i] = arr2[i];
    }

    for (i = 0; i < n3; i++)
    {
        arr3_1[i] = arr3[i];
        arr3_2[i] = arr3[i];
        arr3_3[i] = arr3[i];
        arr3_4[i] = arr3[i];
    }

    for (i = 0; i < n4; i++)
    {
        arr4_1[i] = arr4[i];
        arr4_2[i] = arr4[i];
        arr4_3[i] = arr4[i];
        arr4_4[i] = arr4[i];
    }

    for (i = 0; i < n5; i++)
    {
        arr5_1[i] = arr5[i];
        arr5_2[i] = arr5[i];
        arr5_3[i] = arr5[i];
        arr5_4[i] = arr5[i];
    }

    printf("\nInput Length | Bubble Sort | Insertion Sort | Selection Sort | Quick Sort | Merge Sort\n");

    // For arr legeth = 1000
    bub = 0;
    insert = 0;
    selc = 0;
    quick = 0;
    mer = 0;

    bub_sort(arr1, n1);
    insert_sort(arr1_1, n1);
    selection_sort(arr1_2, n1);
    quick_sort(arr1_3, 0, n1 - 1);
    merge_sort(arr1_4, 0, n1 - 1);
    disp(n1);

    // For arr legeth = 1500
    bub = 0;
    insert = 0;
    selc = 0;
    quick = 0;
    mer = 0;

    bub_sort(arr2, n2);
    insert_sort(arr2_1, n2);
    selection_sort(arr2_2, n2);
    quick_sort(arr2_3, 0, n2 - 1);
    merge_sort(arr2_4, 0, n2 - 1);
    disp(n2);

    // For arr length = 2000
    bub = 0;
    insert = 0;
    selc = 0;
    quick = 0;
    mer = 0;

    bub_sort(arr3, n3);
    insert_sort(arr3_1, n3);
    selection_sort(arr3_2, n3);
    quick_sort(arr3_3, 0, n3 - 1);
    merge_sort(arr3_4, 0, n3 - 1);
    disp(n3);

    // For arr length = 2500
    bub = 0;
    insert = 0;
    selc = 0;
    quick = 0;
    mer = 0;

    bub_sort(arr4, n4);
    insert_sort(arr4_1, n4);
    selection_sort(arr4_2, n4);
    quick_sort(arr4_3, 0, n4 - 1);
    merge_sort(arr4_4, 0, n4 - 1);
    disp(n4);

    // For arr length = 3000
    bub = 0;
    insert = 0;
    selc = 0;
    quick = 0;
    mer = 0;

    bub_sort(arr5, n5);
    insert_sort(arr5_1, n5);
    selection_sort(arr5_2, n5);
    quick_sort(arr5_3, 0, n5 - 1);
    merge_sort(arr5_4, 0, n5 - 1);
    disp(n5);

    return 0;
}