#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int queue[MAX];
int rear=-1;
int front=-1;
void insert();
void delete_element();
void display();
void main()
{
    int choice;
    while(1)
    {
        printf("**Operations:**\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete_element();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice enter from the above");
        }
    }
}
void insert()
{
    int item;
    if(rear>MAX-1)
    {
        printf("Overflow occured! Insertion not possible\n");
    }
    else
    {
        printf("Enter the number to insert:");
        scanf("%d",&item);
        if(front==-1)
            front=0;
        rear=rear+1;
        queue[rear]=item;
        printf("%d inserted into the queue\n",item);
    }
}
void delete_element()
{
    if(front==-1||front>rear)
        printf("Underflow occured! Deletion not possible");
    else
    {
        printf("%d deleted from the queue",queue[front]);
        front=front+1;
    }
}
void display()
{
    int i;
    if (front=-1||front>rear)
        printf("Queue is empty");
    else
    {
        printf("Queue elements are:");
        for(i=front;i<=rear;i++)
        {
            printf("%d",queue[i]);
        }
    }
    printf("\n");
}
