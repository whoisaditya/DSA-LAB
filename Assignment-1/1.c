//Aditya Mitra 20BCE2044
//Program to reverse an array
#include<stdio.h>
void swap(int *x,int *y){ //a method for swapping the elements
    int temp=*x;//Temporary Variable
    *x=*y;
    *y=temp;
}
int main(){
    int n;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);//Tos tore the number of elements
    int arr[n];
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);//To accept the array
    }
    //To reverse the elements
    for(int i=0;i<n/2;i++){
        swap(arr+i,arr+n-i-1);//Swapping the elements
    }
    //To print the result
    printf("The reversed array is\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

