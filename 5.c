#include<stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int n;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);
    int arr1[n],arr2[n];
    printf("Enter the array one elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter the array two elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr2[i]);
    }
    int arr[2*n];
    for(int i=0;i<2*n;i++)
    {
        if(i<n)
        {
            arr[i]=arr1[i];
        }
        else
        {
            arr[i]=arr2[i-n];
        }
    }
    for(int i=0;i<2*n-1;i++)
    {    
       for(int j=0;j<2*n-i-1;j++)  
        {
            if(arr[j]>arr[j+1])
            {
              swap(arr+j,arr+j+1);
            }
        }
    }
    printf("The new array is\n");
    for(int i=0;i<2*n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nThe median element is %d",arr[n-1]);
}
