//Program to print the repated the elements with their frequencies.
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array one elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int rep[n],freq[n];
    for(int i=0;i<n;i++)
    {
        rep[i]=arr[i];
        freq[i]=0;
        for(int j=0;j<n;j++)
        {
            if(rep[i]==arr[j])
            {
                freq[i]++;
            }
        }
    }
    printf("The new array is\n");
    for(int i=0;i<2*n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("The repeated elements: \n");
    for(int i=0;i<n;i++)
    {
        int a=freq[i];
        int c=0;
        for(int j=0;j<n;j++)
        {
            if(freq[j]>1 & c==0)
            {
                printf("The number %d is repeated %d times\n",arr[i],freq[i]);
            }
            if(a==freq[j])
            {
                c++;
            }
        }
    }
}