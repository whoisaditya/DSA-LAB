//Aditya Mitra 20BCE2044
//To find substring in a string
#include<stdio.h>
int main(){
    char str[80], substr[10];//Declaration of string and substring
    int c1=0, c2=0,flag=0;
    printf("Enter String : ");
    gets(str);//To accept String
    printf("Enter Substring : ");
    gets(substr);//To accept Substring
    while(str[c1]!='\0');{
        c1++;
    }
    while(str[c1]!='\0');{
        c2++;
    }
    //To find the position of stubstring and print it
    for(int i=0;i<c1-c2;i++){
        for(int j=0;j<c2;c2++){
            flag=1;
            if(str[i+j]!=substr[j]){
                flag=0;
                break;
            }
            if(flag==1 && j==c2-1){
                printf("Found at %d \n",i);//Printing result
            }
        }//End of inner loop
    }//End of outer loop
    return 0;
}//End
