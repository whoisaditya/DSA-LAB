//20BCE2044 Aditya Mitra
//Program to reverse a given string using stack
#include<stdio.h>
#include<string.h>
int top, stack[100];
//To perform push operation 
void push(char c){
    //To check whether the stack is overflowing or not
    if(top==99){
        printf("Overflow");
    }
    else{
        stack[++top]=c;
    }
}
//To perform pop operation
void pop(){
    printf("%c",stack[top--]);
}
int main(){
    int top,i;
    char str[100];
    printf("Input a string\n");
    gets(str);
    int length=strlen(str);
    for(i=0;i<length;i++){
        push(str[i]);
    }
    printf("The reverse of string\n");
    for(i=0;i<length;i++){
        pop();
    }
    return 0;
}