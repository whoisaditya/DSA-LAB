//Aditya Mitra 20BCE2044
//To rotate array elements by d
#include<stdio.h>
int main(){
    int n,d,c=0;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);//To store the no. of array elements
    printf("Enter the number of elements to be rotated\n");
    scanf("%d",&d);//To store the no. of elements by which the array needs to be rotated
    int arr[n];
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);//To accept array
    }
    int temp[n];
    //To store elements up till index d in temp
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    //To shit the elements by d
    for(int i=0;i<n-d;i++){
        arr[i]=arr[i+d];
    }
    //To replace the older elements of arr with temp in their new positions
    for(int i=n-d;i<n;i++){
        arr[i]=temp[c++];
    }    
    printf("The rotated array is\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;   
}
