//Aditya Mitra 20BCE2044
//To insert an element at position d
#include<stdio.h>
int main()
{
    int n,d,m;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);
    printf("Enter the index where the new element has to be inserted\n");
    scanf("%d",&d);
    printf("Enter the new element\n");
    scanf("%d",&m);
    int arr[n];
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int new[n+1];
    for(int i=0;i<n+1;i++)
    {
        if(i==d)
        {
            new[i]=m;       
        }
        else if(i<d)
        {
            new[i]=arr[i];
        }
        else
        {
            new[i]=arr[i-1];
        }
    }
    printf("The new array is\n");
    for(int i=0;i<n+1;i++)
    {
        printf("%d ",new[i]);
    }
}