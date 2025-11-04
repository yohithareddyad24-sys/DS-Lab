#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char data)
{
    if(top==MAX-1)
    {
        printf("Overflow Occured");
        return;
    }
    top++;
    stack[top]=data;
}
char pop()
{
    if(top==-1)
    {
        printf("Empty stack!\n");
        return ' ';
    }
    char data=stack[top];
    top--;
    return data;
}
int is_matching_pair(char char1,char char2)
{
    if (char1=='(' && char2==')')
    {
        return 1;
    }
    else if(char1=='[' && char2==']')
    {
        return 1;
    }
    else if(char1=='{' && char2=='}')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isBalanced(char* text)
{
    int i;
    for(i-0;i<strlen(text);i++)
    {
        if(text[i]=='(' || text[i]=='[' || text[i]=='{')
            {
                push(text[i]);
            }
            else if (!is_matching_pair(pop(),text[i]))
            {
                return 0;
            }
    }
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void main()
{
    char text[MAX];
    printf("Input an expression in parentheses:");
    scanf("%s",text);
    if (isBalanced(text))
    {
        printf("The expression is balanced\n");
    }
    else
    {
        printf("The expression is not Balanced\n");
    }
}

