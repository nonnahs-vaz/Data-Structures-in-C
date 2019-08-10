//C program to implement linear queue using singly linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *NEXT;
}*FRONT=0,*REAR=0;
typedef struct node node;
void insert();
void del();
void display();
void search(int);
int main()
{
    int ch;
    while(1)
    {
        printf("\n\nEnter choice\n1>Insert\n2>Remove\n3>Display\n4>Search\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: del();
                    break;
            case 3: display();
                    break;
            case 4: printf("\nEnter data to search _> ");
                    scanf("%d",&ch);
                    search(ch);
                    break;
            default:return 0;
        }
    }
}
void insert()
{
    node *NEW_NODE,*ITR;
    NEW_NODE=(node *)malloc(sizeof(node));
    printf("\nEnter data_> ");
    scanf("%d",&NEW_NODE->data);
    if(!FRONT)
        FRONT=NEW_NODE;
    else
        REAR->NEXT=NEW_NODE;
    REAR=NEW_NODE;
    NEW_NODE->NEXT=0;
    printf("\n%d was inserted into queue\n",NEW_NODE->data);
    display();
}
void del()
{
    node *TEMP;
    if(!FRONT)
        printf("\nQueue is empty\n");
    else
    {
        TEMP=FRONT;
        FRONT=FRONT->NEXT;
        printf("\n%d was removed from queue\n",FRONT->data);
        free(TEMP);
        if(!FRONT)
            REAR=0;
        display();
    }
}
void display()
{
    node *ITR;
    if(!FRONT)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nFRONT -> ");
    for(ITR=FRONT ; ITR ; ITR=ITR->NEXT)
        printf("[%d]-> ",ITR->data);

    printf("REAR\n");
}
void search(int data)
{
    node *ITR;
    int i;
    if(!FRONT)
    {
        printf("\nQueue is empty\n");
        return;
    }
    for(i=0,ITR=FRONT ; ITR ; i++,ITR=ITR->NEXT)
    {
        if(ITR->data==data)
            break;
    }
    if(ITR)
        printf("\nData found at position %d\n",i);
    else
        printf("\nData not found\n");
}
