#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{

    int age;
    char name[50],regno[20];
    struct node *next;
}node;

node *top=NULL;

void push(){

    node *newnode;
    char name1[50],regno1[20];
    newnode=(node *)malloc(sizeof(node));

    getchar();

    printf("Enter Registration Number : ");
    fgets(regno1,20,stdin);
    regno1[strlen(regno1)-1]=0;
    strcpy(newnode ->regno,regno1);

    printf("Enter Name : ");
    fgets(name1,50,stdin);
    name1[strlen(name1)-1]=0;
    strcpy(newnode ->name,name1);

    printf("Enter Age : ");
    scanf("%d",&(newnode->age));
    newnode->next=top;

    top=newnode;

}
void pop(){

    node *pointer;
    pointer=top;

    top=top->next;

    printf("Details of the node that has been popped : \n");
    printf("Registration Number : %s\n",pointer->regno);
    printf("Name : %s\n",pointer->name);
    printf("Age : %d\n\n",pointer->age);

    free(pointer);
}
int main(){
    int option;

    while(1){
        printf("\n1) Enter Student informantion\n");
        printf("2) Deleting latest details\n");
        printf("3) Exit\n\n");
        printf("Your option : ");
        scanf("%d",&option);

        switch(option){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                exit(0);

        }
    }
}