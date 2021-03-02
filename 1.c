#include<stdio.h>
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int n;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n/2;i++)
    {
        swap(arr+i,arr+n-i-1);
    }
    printf("The reversed array is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

