//Aditya Mitra 20BCE2044
//To rotate array elements by d

#include<stdio.h>
int main()
{
    int n,d,c=0;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);
    printf("Enter the number of elements to be rotated\n");
    scanf("%d",&d);
    int arr[n];
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int temp[n];
    for(int i=0;i<d;i++)
    {
        temp[i]=arr[i];
    }
    for(int i=0;i<n-d;i++)
    {
        arr[i]=arr[i+d];
    }
    for(int i=0;i<n-d;i++)
    {
        arr[i]=arr[i+d];
    }
    for(int i=n-d;i<n;i++)
    {
        arr[i]=temp[c++];
    }    
    printf("The rotated array is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
