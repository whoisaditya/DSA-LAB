// Aditya Mitra 20BCE2044
// To implement Circular Queue
#include <stdio.h>
#include<stdlib.h>

#define max 20
int queue[max]; // array declaration
int front = -1;
int rear = -1;
// Function to insert an element in a circular queue
void enqueue(int element)
{
    if (front == -1 && rear == -1) // Condition to check queue is empty
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % max == front) // Condition to check queue is full
    {
        printf("\nSQueue is overflow");
    }
    else
    {
        rear = (rear + 1) % max; // Rear is incremented
        queue[rear] = element;   // Assigning a value to the queue at the rear position.
    }
}

// Function to delete the element from the queue
int dequeue()
{
    if ((front == -1) && (rear == -1)) // Condition to check queue is empty
    {
        printf("\nQueue is underflow");
    }
    else if (front == rear)
    {
        printf("\nThe dequeued element is %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nThe dequeued element is %d", queue[front]);
        front = (front + 1) % max;
    }
}
// Function to display the elements of a queue
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\nElements in a Queue are : ");
        while (i <= rear)
        {
            printf("%d,", queue[i]);
            i = (i + 1) % max;
        }
    }
}
int main()
{
    int option, x; // Variables declaration

    while (1) // While loop
    {
        printf("\n1: Insert an element");
        printf("\n2: Delete an element");
        printf("\n3: Display the element");
        printf("\n4: Exit");
        printf("\nEnter option : ");
        scanf("%d", &option);

        switch (option)
        {

        case 1:
            printf("Enter the element which is to be inserted : ");
            scanf("%d", &x);
            enqueue(x);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;
        
        case 4:
            exit(0);
        }
    }
    return 0;
}