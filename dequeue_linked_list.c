//C program to implement dequeue using linked list (delete restricted)
#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *NEXT;
}*FRONT=0,*REAR=0;
typedef struct node node;
node * alloc_space(int);
void insert_at_front(int);
void insert_at_end(int);
void del_front();
void display();
int main()
{
    int ch;
    while(1)
    {
        printf("\n\nDEqueue\nEnter choice\n1>Insert at front\n2>Insert at end\n3>Remove element\n4>Display\n");
        printf("Enter any other value to exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the data_> ");
                    scanf("%d",&ch);
                    insert_at_front(ch);
                    break;
            case 2: printf("\nEnter the data_> ");
                    scanf("%d",&ch);
                    insert_at_end(ch);
                    break;
            case 3: del_front();
                    break;
            case 4: display();
                    break;
            default:return 0;
        }
    }
}
node * alloc_space(int data)    //function to allocate space for new node
{
    node *NODE;
    NODE=(node *)malloc(sizeof(node));
    NODE->data=data;
    return NODE;
}
void insert_at_front(int data)
{
    node *NEW_NODE;
    NEW_NODE=alloc_space(data);
    if(!FRONT)  //inserting first node
    {
        NEW_NODE->NEXT=0;
        REAR=NEW_NODE;
    }
    else
        NEW_NODE->NEXT=FRONT;
    FRONT=NEW_NODE;
    printf("\n%d was inserted at front of queue\nUpdated queue is:",data);
    display();
}
void insert_at_end(int data)
{
    node *NEW_NODE;
    NEW_NODE=alloc_space(data);
    if(!FRONT)  //inserting first node
        FRONT=NEW_NODE;
    else
        REAR->NEXT=NEW_NODE;
    NEW_NODE->NEXT=0;
    REAR=NEW_NODE;
    printf("\n%d was inserted at end of queue\nUpdated queue is:",data);
    display();
}
void del_front()
{
    node *TMP;
    if(!FRONT)  //checking for underflow
    {
        printf("\nQueue is empty");
        return;
    }
    TMP=FRONT;
    printf("\n%d is removed from front of queue\nUpdated queue is:",FRONT->data);
    FRONT=FRONT->NEXT;
    free(TMP);
    if(!FRONT)  //checking if queue is empty
        REAR=0; //resetting rear pointer
    display();
}
void display()
{
    node *ITR;
    if(!FRONT)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nFRONT ->");
    for(ITR=FRONT ; ITR ; ITR=ITR->NEXT)
        printf(" %d ->",ITR->data);
    printf(" REAR\n");
}
