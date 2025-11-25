#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};
struct Node *head = NULL;
void ins_at_pos(int data,int position)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;
    struct Node *temp=head;
    int i;
    if(position==1)
    {
        ptr->next=temp;
        head=ptr;
        return;
    }
    for(i=1;i<position-1;i++)
    {
        if(temp==NULL)
        {
            printf("Invalid position\n");
            free(ptr);
            return;
        }
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Invalid position\n");
        free(ptr);
        return;
    }
    ptr->next=temp->next;
    temp->next=ptr;
}
void display()
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void main()
{
    ins_at_pos(10,1);
    ins_at_pos(20,2);
    ins_at_pos(15,3);
    display();
}
