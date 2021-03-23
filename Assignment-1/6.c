// Aditya Mitra 20BCE2044
//Program to print the repated the elements with their frequencies.
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of array elements\n");
    scanf("%d", &n);
    int arr[n], freq[n];
    printf("Enter the array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int ctr = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                ctr++;
                freq[j] = -1;
            }
        }
        if (freq[i] != -1)
        {
            freq[i] = ctr;
        }
    }
    printf("\nThe frequency of all elements of array : \n");
    for (int i = 0; i < n; i++)
    {
        if (freq[i] != -1)
        {
            printf("%d occurs %d times\n", arr[i], freq[i]);
        }
    }
    return 0;
}