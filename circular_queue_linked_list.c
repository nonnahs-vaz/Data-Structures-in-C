//circular queue using circular linked list
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
void search();
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
    node *NEW_NODE;
    NEW_NODE=(node *)malloc(sizeof(node));
    printf("\nEnter the data_> ");
    scanf("%d",&NEW_NODE->data);
    if(!FRONT)
        FRONT=NEW_NODE;
    else
        REAR->NEXT=NEW_NODE;

    REAR=NEW_NODE;
    REAR->NEXT=FRONT;
    printf("\nElement inserted\n");
    display();
}
void del()
{
    node *TEMP;
    if(!FRONT)
        printf("\nQueue is empty\n");
    else
    {
        if(FRONT->NEXT==FRONT)
        {
            printf("\nElement %d is deleted\n",FRONT->data);
            free(FRONT);
            FRONT=REAR=0;
        }
        else
        {
            printf("\nElement %d is deleted\n",FRONT->data);
            TEMP=FRONT;
            FRONT=FRONT->NEXT;
            free(TEMP);
            REAR->NEXT=FRONT;
        }
        display();
    }
}
void display()
{
    node *ITR;
    if(!FRONT)
        printf("\nQueue is empty\n");
    else
    {
        printf("\nFRONT ->");
        for(ITR=FRONT ; ITR!=REAR ; ITR=ITR->NEXT)
            printf(" %d ->",ITR->data);
        printf(" %d ->",ITR->data);
        printf(" REAR\n");
    }
}

void search(int lmnt)
{
    node *ITR;
    int i=0;
    if(!FRONT)
        printf("\nQueue is empty\n");
    else
    {
        for(ITR=FRONT,i=0 ; ITR!=REAR ; ITR=ITR->NEXT,i++ )
        {
            if(ITR->data==lmnt)
                break;
        }
        if(ITR->data==lmnt)
            printf("\nElement found at position %d\n",i);
        else
            printf("\nElement not found\n");
    }
}




















