//C program to implement stack using array
#include<stdio.h>
#define SIZE 5
int stack[SIZE],TOP=-1;
void push(int);
void pop();
void display();
void search(int);
int main()
{
    int ch;
    while(1)
    {
        printf("\n\nEnter choice\n1>PUSH\n2>POP\n3>Display\n4>Search\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("\nEnter the data_> ");
                     scanf("%d",&ch);
                     push(ch);
                     break;
            case 2 : pop();
                     break;
            case 3 : display();
                     break;
            case 4 : printf("\nEnter the data to search_> ");
                     scanf("%d",&ch);
                     search(ch);
                     break;
            default: return 0;
        }
    }
}
void push(int data)
{
    if(TOP==SIZE-1)
        printf("\nOperation not possible since stack is full\n");
    else
    {
        TOP++;
        stack[TOP]=data;
        printf("\n%d was pushed onto stack\n",stack[TOP]);
    }

}
void pop()
{
    if(TOP==-1)
        printf("\nOperation not possible since stack is empty\n");
    else
    {
        printf("\n%d was popped from stack\n",stack[TOP]);
        TOP--;
    }
}
void display()
{
    int i;
    if(TOP==-1)
        printf("\nStack is empty\n");
    else
    {
        printf("\nData in stack is :\nTOP");
        for(i=TOP;i>=0;i--)
            printf("\n%d",stack[i]);
    }
}
void search(int x)
{
    int flag=0,i;
    for(i=TOP;i>=0;i--)
    {
        if(stack[i]==x)
        {
            flag=1;
            break;
        }
    }
    if(flag)
        printf("\nData found at position %d ",i);
    else
        printf("\nData not found");
}
