//C program on doubly linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *PREV,*NEXT;
}*START=0;
typedef struct node node;
void insert_at_beg();
void insert_at_end();
void insert_at_pos();
void del_from_beg();
void del_from_end();
void del_from_pos();
void display();
void reverse();
void search();
node * new_node();

int main()
{
    int choice;
    while(1)
     {
         printf("\nEnter a choice\n1>Add an node to list\n2>Remove a node\n3>Display data\n4>Reverse List\n5>Search data in list\n");
         printf("enter any other value to exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
            case 1:  printf("\nEnter choice\n1>Add at beginning\n2>Add at end\n3>Add at intermediate position\n");
                     scanf("%d",&choice);
                     switch(choice)
                     {
                        case 1 : insert_at_beg();
                                 break;
                        case 2 : insert_at_end();
                                 break;
                        case 3 : insert_at_pos();
                                 break;
                        default: printf("\nInvalid input\n");
                     }
                    break;
            case 2: printf("\nEnter choice\n1>Delete from beginning\n2>Delete from end\n3>Delete from intermediate position\n");
                    scanf("%d",&choice);
                    switch(choice)
                     {
                        case 1 : del_from_beg();
                                 break;
                        case 2 : del_from_end();
                                 break;
                        case 3 : del_from_pos();
                                 break;
                        default: printf("\nInvalid input\n");
                     }
                    break;
            case 3: display();
                    break;
            case 4: reverse();
                    break;
            case 5: search();
                    break;
            default:return 0;
        }
     }
}
node * new_node()
{
    static node *NEW_NODE;
    NEW_NODE=(node *)malloc(sizeof(node));
    printf("\nEnter data _> ");
    scanf("%d",&NEW_NODE->data);
    return NEW_NODE;
}
void insert_at_beg()
{
    node *NEW_NODE;
    NEW_NODE=new_node();
    if(!START)
        NEW_NODE->NEXT=0;
    else
    {
        NEW_NODE->NEXT=START;
        START->PREV=NEW_NODE;
    }
    START=NEW_NODE;
    NEW_NODE->PREV=0;
    printf("\n%d was inserted successfully\n",NEW_NODE->data);
}
void insert_at_end()
{
    node *TEMP,*NEW_NODE;
    NEW_NODE=new_node();
    if(!START)
    {
        START=NEW_NODE;
        NEW_NODE->PREV=0;
    }
    else
    {
        for(TEMP=START ; TEMP->NEXT!=0 ; TEMP=TEMP->NEXT);

        TEMP->NEXT=NEW_NODE;
        NEW_NODE->PREV=TEMP;
    }
    NEW_NODE->NEXT=0;
    printf("\n%d was inserted successfully\n",NEW_NODE->data);
}
void insert_at_pos()
{
    int i,pos,end;
    node *TEMP,*NEW_NODE;
    printf("\nEnter the position of element to insert at_> ");
    scanf("%d",&pos);
    if(START)
    {
        for(end=1 , TEMP=START ; TEMP->NEXT!=0 ; end++ , TEMP=TEMP->NEXT);
        if(pos>0 && pos<end)
        {
            NEW_NODE=new_node();
            for(TEMP=START , i=0 ; i<pos ; i++ , TEMP=TEMP->NEXT );

            TEMP->PREV->NEXT=NEW_NODE;
            NEW_NODE->PREV=TEMP->PREV;
            NEW_NODE->NEXT=TEMP;
            TEMP->PREV=NEW_NODE;
            printf("\n%d was inserted successfully\n",NEW_NODE->data);
        }
        else
            printf("\nAddition not possible\n");
    }
    else
        printf("\nAddition not possible\n");
}
void del_from_beg()
{
    if(!START)
        printf("\nList is empty\n");
    else if(START->NEXT==0)
    {
        free(START);
        START=0;
        printf("\nDeletion successful\n");
    }
    else
    {
        START=START->NEXT;
        free(START->PREV);
        START->PREV=0;
        printf("\nDeletion successful\n");
    }
}
void del_from_end()
{
    node *TEMP;
    if(!START)
        printf("\nList is empty\n");
    else if(START->NEXT==0)
    {
        free(START);
        START=0;
        printf("\nDeletion successful\n");
    }
    else
    {
        for(TEMP=START ; TEMP->NEXT!=0 ; TEMP=TEMP->NEXT);

        TEMP->PREV->NEXT=0;
        free(TEMP);
        printf("\nDeletion successful\n");
    }
}
void del_from_pos()
{
    int i,pos,end;
    node *TEMP;
    printf("\nEnter the position of element to delete from_> ");
    scanf("%d",&pos);
    if(START)
    {
        for(end=0 , TEMP=START ; TEMP->NEXT!=0 ; end++ , TEMP=TEMP->NEXT);
        if(pos>0 && pos<end)
        {
            for(i=0 , TEMP=START ; i<pos ; i++ , TEMP=TEMP->NEXT);

            TEMP->PREV->NEXT=TEMP->NEXT;
            TEMP->NEXT->PREV=TEMP->PREV;
            free(TEMP);
            printf("\nDeletion successful\n");
        }
        else
            printf("\nDeletion not possible\n");
    }
    else
        printf("\nDeletion not possible\n");
}
void display()
{
    node *TEMP;
    if(!START)
        printf("\nList is empty\n");
    else
    {
        printf("\nSTART->");
        for(TEMP=START ; TEMP!=0 ; TEMP=TEMP->NEXT )
            printf(" [%d]->",TEMP->data);
        printf(" NULL\n");
    }
}
void reverse()
{
    node *P1,*TEMP;
    if(!START)
        printf("\nList is empty");
    else if(START->NEXT)
    {
        P1=START->NEXT;
        while(P1!=0)
        {
            TEMP=P1->PREV->NEXT;
            P1->PREV->NEXT=P1->PREV->PREV;
            P1->PREV->PREV=TEMP;
            P1=P1->NEXT;
        }
        START=TEMP;
        TEMP->NEXT=TEMP->PREV;
        TEMP->PREV=0;
        printf("\nList reversed\n");
    }
}
void search()
{
    int x,flag=0;
    node *TEMP;
    if(!START)
        printf("\nList is empty\n");
    else
    {
        printf("\nEnter the element to search for_> ");
        scanf("%d",&x);
        for(TEMP=START ; TEMP!=0 ; TEMP=TEMP->NEXT)
        {
            if(TEMP->data==x)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("\nElement found\n");
        else
            printf("\nElement not found\n");
    }
}
