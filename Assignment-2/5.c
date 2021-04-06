//20BCE2044 Aditya Mitra
//Program to store student detials(Queue Implementation)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char regno[10];
    char name[50];
    struct node *next;
};
struct node *front;
struct node *rear;
void insert();
void delete ();
void display();
void main()
{
    int choice;
    while (choice != 4)
    {
        printf("\nMain Menu\n");
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice??\n");
        }
    }
}
void insert()
{
    struct node *ptr;
    char regno1[10],name1[50];

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        getchar();

        printf("Enter Registration Number : ");
        fgets(regno1, 10, stdin);
        regno1[strlen(regno1) - 1] = 0;
        strcpy(ptr->regno, regno1);

        printf("Enter Name : ");
        fgets(name1, 50, stdin);
        name1[strlen(name1) - 1] = 0;
        strcpy(ptr->name, name1);

        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void delete ()
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nThe Queue:\n");
        while (ptr != NULL)
        {
            printf("\nName: %s\n", ptr->name);
            printf("\nRegistration No. : %s\n", ptr->regno);
            ptr = ptr->next;
        }
    }
}