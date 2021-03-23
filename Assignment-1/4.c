//Aditya Mitra 20BCE2044
//To insert an element at position d
#include<stdio.h>
int main(){
    int n,d,m;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);//To store the number of array elements
    printf("Enter the index where the new element has to be inserted\n");
    scanf("%d",&d);//To store the index of new elements\
    printf("Enter the new element\n");
    scanf("%d",&m);//To store the new element
    int arr[n];
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);//To take input of array 
    }
    int new[n+1];//The new array
    //Storing the elements in the new array
    for(int i=0;i<n+1;i++){
        if(i==d){
            new[i]=m;       
        }
        else if(i<d){
            new[i]=arr[i];
        }
        else{
            new[i]=arr[i-1];
        }
    }
    printf("The new array is\n");
    for(int i=0;i<n+1;i++){
        printf("%d ",new[i]);
    }
}//End