// A C program to demonstrate linked list based implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A linked list (LL) node to store a queue entry
struct QNode
{
    char name[50];
    int empid;
    char vac;
    struct QNode *next;
};

// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct Queue
{
    struct QNode *front, *rear;
};

// A utility function to create a new linked list node.
struct QNode *newNode(char name1[50], int empid1, char vac1)
{
    struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));

    strcpy(temp->name, name1);
    temp->empid = empid1;
    temp->vac = vac1;

    temp->next = NULL;
    return temp;
}

// A utility function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key k to q
void enQueue(struct Queue *q, char name1[50], int empid1, char vac1)
{
    // Create a new LL node
    struct QNode *temp = newNode(name1, empid1, vac1);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a key from given queue q
void deQueue(struct Queue *q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
    struct QNode *temp = q->front;

    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}
/*
void Lists(struct Queue *q, struct Queue *q1, struct Queue *q2)
{
    struct Queue *temp;
    temp = q;
    while(temp->Qnode->next!=NULL)
    {
        if (temp->Qnode->vac =='Y')
        {
            enQueue(q1, Qnode->name, Qnode->empid, Qnode->vac);
        }
        if (Qnode->vac == 'N')
        {
            enQueue(q2, Qnode->name, temp->Qnode->empid, Qnode->vac);
        }
        temp=temp->next;
    }
}
*/
// Driver Program to test anove functions
int main()
{
    struct Queue *q = createQueue();
    struct Queue *q1 = createQueue();
    struct Queue *q2 = createQueue();
    int option;

    while (1)
    {
        printf("\n1) Enter informantion\n");
        printf("2) Deleting latest details\n");
        printf("3) Create other lists, display and Exit\n\n");
        printf("Your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            char name1[50];
            int empid1;
            char vac1;
            printf("Name: ");
            scanf("%s", &name1);
            printf("Employee Id: ");
            scanf("%d", &empid1);
            printf("Vacciniation Status: ");
            getchar(vac1);
            enQueue(q, name1, empid1, vac1);
            break;
        }

        case 2:
        {
            deQueue(q);
            break;
        }

        case 3:
        {
            //Lists(q, q1, q2);
            exit(0);
        }

            return 0;
        }
    }
}
