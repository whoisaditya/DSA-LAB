// Aditya Mitra 20BCE2044
//Program to combine two arrays and find median.
#include<stdio.h>
void swap(int *x,int *y){ //a method for swapping the elements
    int temp=*x;//Temporary Variable
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
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);//Inout for array 1
    }
    printf("Enter the array two elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr2[i]); //Input for array 2
    }
    int arr[2*n]; //The new array to store the other arrays
    //Storing the values in the new array
    for(int i=0;i<2*n;i++){
        if(i<n){
            arr[i]=arr1[i];
        }
        else{
            arr[i]=arr2[i-n];
        }
    }
    //Performing Bubble sort
    for(int i=0;i<2*n-1;i++){    
       for(int j=0;j<2*n-i-1;j++){
            if(arr[j]>arr[j+1]){
              swap(arr+j,arr+j+1);
            }
        }
    }
    //Printing the result
    printf("The new array is\n");
    for(int i=0;i<2*n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nThe median element is %d",arr[n-1]);
}