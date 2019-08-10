//C program on singly linked list
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node node;
node * find_end(int *);
void display();
void reverse_list();
void search_list(int);
void display_list();
void deallocate_mem();
node * new_node();
void insert_at_pos(int);
void insert_at_beg();
void insert_at_end();
void del_from_beg();
void del_from_end();
void del_from_pos(int);
void del_specific_element(int);
void sort();
void create_list();
int count_nodes();
struct node
{
    int data;
    struct node *NEXT;
}*START=NULL;

int main()
{
    int choice;
    while(1)
     {
         printf("\n\nEnter the number of operation\n1> Insert at beginning\n2> Insert at end\n3> Insert at position\n4> Delete from beginning\n5> Delete from end\n6> Delete from position\n7> Delete specified element\n8> Display list\n9> Reverse list\n10> Search list\n11> Sort list\n12> Create list\n13> Count nodes in list\n");
         printf("enter any other value to exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
            case 1 : insert_at_beg();
                     break;
            case 2 : insert_at_end();
                     break;
            case 3 : printf("\nEnter the position of node_> ");
                     scanf("%d",&choice);
                     insert_at_pos(choice);
                     break;
            case 4 : del_from_beg();
                     break;
            case 5 : del_from_end();
                     break;
            case 6 : printf("\nEnter the index of node_> ");
                     scanf("%d",&choice);
                     del_from_pos(choice);
                     break;
            case 7 : printf("\nEnter the element to delete _> ");
                     scanf("%d",&choice);
                     del_specific_element(choice);
                     break;
            case 8 : display();
                     break;
            case 9 : reverse_list();
                     break;
            case 10: if(!START)
                        printf("\nList is empty\n");
                     else
                     {
                         printf("\nEnter the data to search in list_> ");
                         scanf("%d",&choice);
                         search_list(choice);
                     }
                     break;
            case 11: sort();
                     break;
            case 12: create_list();
                     break;
            case 13: choice=count_nodes();
                     printf("\nNumber of nodes in list is %d\n",choice);
                     break;
            default: return 0;
        }
     }
}
node * find_end(int *b)
{
	static node *TEMP=0;
	if(START)
        for(TEMP=START , *b=0; TEMP->NEXT!=NULL ; TEMP=TEMP->NEXT , *b+=1);

    return TEMP;
}
node * new_node()
{
    int data;
    static node *NEW_NODE;
    printf("\nEnter the data_> ");
    scanf("%d",&data);
    NEW_NODE=(node *)malloc(sizeof(node));
    NEW_NODE->data=data;
    return NEW_NODE;
}
void insert_at_beg()
{
    node *NEW_NODE;
    NEW_NODE=new_node();
    if(!START)
    {
        START=NEW_NODE;
        NEW_NODE->NEXT=NULL;
    }
    else
    {
        NEW_NODE->NEXT=START;
        START=NEW_NODE;
    }
    printf("\n%d was inserted successfully\n",NEW_NODE->data);
}
void insert_at_end()
{
    node *TEMP1,*NEW_NODE;
    int end;
    NEW_NODE=new_node();
    if(!START)
        START=NEW_NODE;
    else
    {
        TEMP1=find_end(&end);
        TEMP1->NEXT=NEW_NODE;
    }
    NEW_NODE->NEXT=NULL;
    printf("\n%d was inserted successfully\n",NEW_NODE->data);
}
void insert_at_pos(int count)
{
    node *TEMP2,*TEMP1,*NEW_NODE;
    int i,end=0;
    TEMP1=START;
    find_end(&end);
    if(count > 0 && count < end && START)
    {
        NEW_NODE=new_node();
        for(i=0 ; i<count ; i++)
        {
            TEMP2=TEMP1;
            TEMP1=TEMP1->NEXT;
        }
        TEMP2->NEXT=NEW_NODE;
        NEW_NODE->NEXT=TEMP1;
        printf("\n%d was inserted successfully\n",NEW_NODE->data);
    }
    else
        printf("\nOperation not possible\n");
}
void del_from_beg()
{
    node *TEMP1;
    TEMP1=START;
    if(!START)
        printf("\nList is empty\n");
    else
    {
        START=START->NEXT;
        free(TEMP1);
        printf("\nDeletion successful\n");
    }
}
void del_from_end()
{
     node *PREV=0,*ITR;
     if(!START)
        printf("\nList is empty\n");
     else
     {
        for(ITR=START ; ITR->NEXT ; ITR=ITR->NEXT)
            PREV=ITR;
        if(!PREV)
        {
            free(START);
            START=0;
        }
        else
        {
            PREV->NEXT=0;
            free(ITR);
        }
        display();
        printf("\nDeletion successful\n");
     }
}
void del_from_pos(int index)
{
    int end,i;
    node *TEMP2,*TEMP1;
    TEMP1=START;
    if(!START)
        printf("\nList is empty\n");
    else
    {
        find_end(&end);
        if(index>0 && index<end)
        {
            for(i=0 ; i<index ; i++)
            {
                TEMP2=TEMP1;
                TEMP1=TEMP1->NEXT;
            }
        TEMP2->NEXT=TEMP1->NEXT;
        free(TEMP1);
        printf("\nDeletion successful\n");
        }
    }
}
void del_specific_element(int data)
{
    node *PTR,*PREV;
    int flag=0;
    PREV=0;
    if(!START)
    {
        printf("\nList is empty\n");
        return;
    }
    for(PTR=START ; PTR ; PTR=PTR->NEXT)
    {
        if(PTR->data==data)
        {
            flag=1;
            break;
        }
        PREV=PTR;
    }
    if(flag)
    {
        if(!PREV)
        {
            PREV=START;
            START=START->NEXT;
            free(PREV);
        }
        else
        {
            PREV->NEXT=PTR->NEXT;
            free(PTR);
        }
        printf("\n%d was deleted\nList is :\n",data);
        display();
    }
    else
        printf("\nerror\n");
}
void display()
{
    node *TEMP;
    printf("\nSTART");
    for(TEMP=START ; TEMP!=NULL ; TEMP=TEMP->NEXT)
        printf(" -> [%d] ",TEMP->data);
    printf("-> NULL\n");
}
void reverse_list()
{
    node *P1,*P2,*LEAD;
    LEAD=START;
    P1=NULL;
    if(START==NULL)
        printf("\nList is empty\n");
    else
    {
        printf("\nList before reversing :\n");
        display();
        while(LEAD!=NULL)
        {
            P2=P1;
            P1=LEAD;
            LEAD=LEAD->NEXT;
            P1->NEXT=P2;
        }
        START=P1;
        printf("\nList after reversing :\n");
        display();
    }
}
void search_list(int data)
{
    node *TEMP;
    int i,f=0;
    for(i=0 , TEMP=START ; TEMP!=NULL ; i++,TEMP=TEMP->NEXT)
    {
        if(data==TEMP->data)
        {
            f=1;
            break;
        }
    }
    if(f)
        printf("\nData found at position %d\n",i);
    else
        printf("\nData not found\n");
}
void display_list()
{
    int choice,i;
    node *TEMP;
    TEMP=START;
    if(!TEMP)
        printf("\nList is empty\n");
    else
    {
        printf("\nEnter choice\n1>Display first node\n2>Display last node\n3>Display node at selected index\n4>Display all nodes\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nSTART -> [%d]\n",START->data);
                    break;
            case 2: TEMP=find_end(&choice);
                    printf("\n[%d] -> NULL\n",TEMP->data);
                    break;
            case 3: printf("\nEnter index of node to display_> ");
                    scanf("%d",&choice);
                    find_end(&i);
                    if(choice>=0 && choice<=i)
                    {
                        for(i=0;i<choice;i++)
                            TEMP=TEMP->NEXT;
                        printf("\n    [%d]\n",TEMP->data);
                    }
                    else
                        printf("\nIndex does not exist\n");
                    break;
            case 4: display();
                    break;
           default: printf("\nInvalid input\n");
        }
    }
}
void sort()
{
    node *ITR1,*ITR2;
    int temp;
    if(!START)
        printf("\nList is empty\n");
    else
    {
        if(START->NEXT)
        {
            for(ITR1=START ; ITR1 ; ITR1=ITR1->NEXT)
            {
                for(ITR2=ITR1->NEXT ; ITR2 ; ITR2=ITR2->NEXT)
                {
                    if(ITR1->data > ITR2->data)
                    {
                        temp=ITR1->data;
                        ITR1->data=ITR2->data;
                        ITR2->data=temp;
                    }
                }
            }
        }
        printf("\nList after sorting :\n");
        display();
    }
}
void create_list()
{
    node *NEW_NODE;
    int i;

    srand(time(0));
    for(i=0;i<5;i++)
    {
        NEW_NODE=(node *)malloc(sizeof(node));
        NEW_NODE->data=rand()%101;

        if(!START)
            NEW_NODE->NEXT=0;
        else
            NEW_NODE->NEXT=START;
        START=NEW_NODE;
    }
    printf("\nList of 5 nodes has been created\n");
    printf("\nList is:");
    display();
}
void deallocate_mem()
{
    node *TEMP1,*TEMP2;
    TEMP1=START;
    if(TEMP1!=NULL)
    {
        while(TEMP1!=NULL)
        {
            TEMP2=TEMP1;
            TEMP1=TEMP1->NEXT;
            free(TEMP2);
        }
    }
}
int count_nodes()
{
    int i;
    node *T;
    for(i=0, T=START ; T ; T=T->NEXT , i++);

    return i;
}
