// Aditya Mitra
// 20BCE2044
// Program to search for a particular student using their regno as key

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char fname[50];
    char lname[50];
    int regno;
    float cgpa;
};

void swap(struct student *x, struct student *y) // Function to swap integers
{
    struct student temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

void bub_sort(struct student arr[], int n) // Function to sort the array using buble sort
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].regno > arr[j + 1].regno)
            {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

// A recursive binary search function. It returns
int binary_search(struct student arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle

        if (arr[mid].regno == x)
        {
            return mid;
        }

        // If element is smaller than mid, then

        if (arr[mid].regno > x)
        {
            return binary_search(arr, l, mid - 1, x);
        }

        // Else the element can only be present

        return binary_search(arr, mid + 1, r, x);
    }

    // When element not present in array
    return -1;
}

void input(struct student stu[], int n)
{
    int i;
    printf("Enter details : \n");
    for (i = 0; i < n; i++)
    {

        printf("First Name : ");
        scanf("%s", &stu[i].fname);

        printf("Last Name : ");
        scanf("%s", &stu[i].lname);

        printf("Reg No. : ");
        scanf("%d", &stu[i].regno);

        printf("CGPA : ");
        scanf("%f", &stu[i].cgpa);

        printf("\n");
    }
    
}

void display(struct student stu[], int result)
{
    if (result != -1)
    {
        printf("\nFound at index %d\n%s %s\n%d\n%f", result, stu[result].fname, stu[result].lname, stu[result].regno, stu[result].cgpa);
    }
    else
    {
        printf("Not Present");
    }
}

int main()
{
    struct student stu[10];
    int n, result, x;

    // Input
    printf("Enter no. of students: ");
    scanf("%d", &n);

    input(stu, n);

    printf("\nEnter regno for particular student : ");
    scanf("%d", &x);

    // Searching
    result = binary_search(stu, 0, n - 1, x);

    // Printing Result
    display(stu,result);

    return 0;
}
