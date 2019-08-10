//implementation of stack using singly linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *NEXT;
}*TOP=0;
typedef struct node node;
void push(int);
void pop();
void display();
void search(int);
int count=0;
int main()
{
    int ch;
    while(1)
    {
        printf("\n\nEnter choice\n1>PUSH\n2>POP\n3>Display\n4>Search\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter data _> ");
                    scanf("%d",&ch);
                    push(ch);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: if(!TOP)
                        printf("\nStack is empty\n");
                    else
                    {
                        printf("\nEnter data to search _> ");
                        scanf("%d",&ch);
                        search(ch);
                    }
                    break;
            default:return 0;
        }
    }
}
void push(int data)
{
    node *NEW_NODE;
    NEW_NODE=(node *)malloc(sizeof(node));
    NEW_NODE->data=data;
    if(!TOP)
        NEW_NODE->NEXT=0;
    else
        NEW_NODE->NEXT=TOP;

    TOP=NEW_NODE;
    count++;
    printf("\nPushed data\n");
}
void pop()
{
    node *TEMP;
    if(!TOP)
        printf("\nCannot pop, stack is empty\n");
    else
    {
        TEMP=TOP;
        printf("\n%d was popped\n",TOP->data);
        TOP=TOP->NEXT;
        free(TEMP);
        count--;
    }
}
void display()
{
    node *TEMP;
    if(!TOP)
        printf("\nStack is empty\n");
    else
    {
        printf("\nTOP");
        for(TEMP=TOP ; TEMP!=NULL ; TEMP=TEMP->NEXT)
            printf("\n[%d]",TEMP->data);
    }
}
void search(int x)
{
    int flag=0,i;
    node *TEMP;
    for(TEMP=TOP,i=0 ; TEMP!=NULL ; TEMP=TEMP->NEXT,i++ )
    {
        if(TEMP->data==x)
        {
            flag=1;
            break;
        }
    }
    if(flag)
        printf("\nElement present at position %d\n",count-i-1);
    else
        printf("\nElement not present\n");
}
