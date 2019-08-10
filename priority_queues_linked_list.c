//C program to implement priority queues using linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
    int data,priority;
    struct node *NEXT;
}*FRONT=0,*REAR=0;
typedef struct node node;
void insert(int,int);
void del();
void display_queue();
int main()
{
    int ch,pr;
    while(1)
    {
        printf("\n\nPriority Queue\nEnter choice\n1>Insert element\n2>Remove element\n3>Display\nEnter any other value to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter data_> ");
                    scanf("%d",&ch);
                    printf("\nEnter priority of element_> ");
                    scanf("%d",&pr);
                    insert(ch,pr);
                    break;
            case 2: del();
                    break;
            case 3: display_queue();
                    break;
            default:return 0;
        }
    }
}
void insert(int data,int priority)
{
    node *ITR1,*ITR2,*NEW_NODE;
    NEW_NODE=(node *)malloc(sizeof(node));
    NEW_NODE->data=data;
    NEW_NODE->priority=priority;
    if(!FRONT)  //inserting first node
    {
        FRONT=REAR=NEW_NODE;
        NEW_NODE->NEXT=0;
    }
    else
    {
        for(ITR2=FRONT,ITR1=0; ITR2 ; ITR2=ITR2->NEXT)  //loop to find position of node according to priority
        {
            if(ITR2->priority < priority)   //checking if new node has higher priority than test node
                break;
            ITR1=ITR2;  //storing previous value of ITR2 to link the nodes in between the list
        }
        if(!ITR1)   //placing node at front
        {
            NEW_NODE->NEXT=FRONT;
            FRONT=NEW_NODE;
        }
        else if(!ITR2)  //placing node at end
        {
            REAR->NEXT=NEW_NODE;
            NEW_NODE->NEXT=0;
            REAR=NEW_NODE;
        }
        else    //placing node in between
        {
            ITR1->NEXT=NEW_NODE;
            NEW_NODE->NEXT=ITR2;
        }
    }
    printf("\nElement %d with priority %d was inserted into the queue\nUpdated queue is:",data,priority);
    display_queue();
}
void del()
{
    node *TMP;
    if(!FRONT)  //checking for underflow
    {
        printf("\nQueue is empty\n");
        return;
    }
    TMP=FRONT;
    printf("\n%d is removed from queue",FRONT->data);
    FRONT=FRONT->NEXT;
    free(TMP);
    if(!FRONT)  //checking if queue is empty
        REAR=0; //resetting rear pointer
    display_queue();
}
void display_queue()
{
    node *ITR;
    if(!FRONT)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nFRONT ->");
    for(ITR=FRONT ; ITR ; ITR=ITR->NEXT)
        printf(" [%d :: %d] ->",ITR->data,ITR->priority);
    printf(" REAR\n");
}
