#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int dequeue[MAX];
int left=-1,right=-1;
void insert_right(void);
void insert_left(void);
void delete_right(void);
void delete_left(void);
void display(void);
int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Insert at right");
        printf("\n2.Insert at left");
        printf("\n3.Delete from right");
        printf("\n4.Delete from left");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;
        case 3:
            delete_right();
            break;
        case 4:
            delete_left();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice!");
        }
    }
    return 0;
}
void insert_right()
{
    int val;
    printf("Enter the value to be added");
    scanf("%d",&val);
    if((left==0&& right==MAX-1) || (left==right+1))
    {
        printf("\n Overflow");
    }
    if(left==-1)
    {
        left=0;
        right=0;
    }
    else
    {
        if(right==MAX-1)
            right=0;
        else
            right=right+1;
    }
    dequeue[right]=val;
}
void insert_left()
{
    int val;
    printf("\n Enter the value to be added");
    scanf("%d",&val);
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("\n Overflow");
    }
    if(left==-1)
    {
        left=0;
        right=0;
    }
    else
    {
        if(left==0)
            left=MAX-1;
        else
            left=left-1;
    }
    dequeue[left]=val;
}
void delete_right()
{
    if(left==-1)
    {
        printf("\n Underflow");
        return;
    }
    printf("\n The deleted element is %d\n",dequeue[right]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(right==0)
            right=MAX-1;
        else
            right=right+1;
    }
}
void delete_left()
{
    if(left==-1)
    {
        printf("\n Underflow");
        return;
    }
    printf("\n The deleted element is %d\n",dequeue[left]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(left==MAX-1)
            left=0;
        else
            left=left+1;
    }
}
void display()
{
    int i;
    if (left == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nDequeue elements: ");
    i = left;
    while (1)
    {
        printf("%d ", dequeue[i]);
        if (i == right)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
