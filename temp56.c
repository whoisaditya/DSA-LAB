

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct QNode
{
    char name[50];
    int empid;
    int vac;
    struct QNode *next;
};

void insert();
void delete ();
void display();
void create();

struct QNode queue_array[MAX];
int rear = -1;
int front = -1;

struct QNode queue_array1[MAX];
int f1 = -1;
int r1 = -1;

struct QNode queue_array2[MAX];
int f2 = -1;
int r2 = -1;

int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
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
        {
            create();
            display();
            break;
        }
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n");
        } /* End of switch */
    }     /* End of while */
    return 0;
} /* End of main() */

void insert()
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow \n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        scanf("%s%d%d", &queue_array[rear].name, &queue_array[rear].empid, &queue_array[rear].vac);

        rear++;
    }
} /* End of insert() */

void delete ()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %s\n%d\n%d\n", queue_array[front].name, queue_array[front].empid, queue_array[front].vac);
        front = front + 1;
    }
} /* End of delete() */

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = 0; i <= rear; i++)
        {
            printf("%s\n%d\n%d\n", queue_array[i].name, queue_array[i].empid, queue_array[i].vac);
        }



        for (i = 0; i <r1; i++)
        {
            printf("fuck me1\n");
            printf("%s\n%d\n%d\n", queue_array1[i].name, queue_array1[i].empid, queue_array1[i].vac);
        }



        for (i = 0; i <r2; i++)
        {
            printf("fuck me2\n");
            printf("%s\n%d\n%d", queue_array2[i].name, queue_array2[i].empid, queue_array2[i].vac);
        }

        printf("\n");
    }
} /* End of display() */

void create()
{
    r1=0;
    r2=0;

    for (int i = front; i <= rear; i++)
    {
        if (queue_array[i].vac == 1)
        {
            printf("fuck me3\n");
            strcpy(queue_array1[r1].name, queue_array[i].name);
            queue_array1[r1].empid = queue_array[i].empid;
            queue_array1[r1].vac = queue_array[i].vac;
            r1++;
        }
        if (queue_array[i].vac == 0)
        {
            printf("fuck me4\n");
            strcpy(queue_array1[r2].name, queue_array[i].name);
            queue_array2[r2].empid = queue_array[i].empid;
            queue_array2[r2].vac = queue_array[i].vac;
            r2++;
        }
    }
}
