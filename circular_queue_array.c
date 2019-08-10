//C program to implement circular queue using array
#include<stdio.h>
#define SIZE 3
int queue[SIZE],FRONT=-1,REAR=-1;
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
    if(FRONT==(REAR+1)%SIZE)
    {
        printf("\nCannot insert, queue is full\n");
        return;
    }
    if(FRONT==-1 && REAR==-1)
        FRONT++;

    REAR=(REAR+1)%SIZE;
    printf("\nEnter data _> ");
    scanf("%d",&queue[REAR]);
    printf("\nInsertion successful\n");
    display();
}

void del()
{
    if(FRONT==-1)
    {
        printf("\nCannot delete, queue is empty\n");
        return;
    }
    printf("\nElement %d is removed\n",queue[FRONT]);

    if(FRONT==REAR)
    {
        FRONT=-1;
        REAR=-1;
    }
    else
        FRONT=(FRONT+1)%SIZE;
    display();
}

void display()
{
    int i;
    if(FRONT==-1)
        printf("\nQueue is empty");
    else
    {
        printf("\nFRONT ->");
        for(i=FRONT ; i!=REAR ; i=(i+1)%SIZE)
            printf(" %d ->",queue[i]);

        printf(" %d ->",queue[i]);
        printf(" REAR\n");
    }
}

void search(int x)
{
    int i,pos;
    if(FRONT==REAR && FRONT==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    for(i=FRONT , pos=0 ; i!=REAR ; i=(i+1)%SIZE , pos++)
    {
        if(queue[i]==x)
            break;
    }
    if(queue[i]==x)
        printf("\nElement found at position %d\n",pos);
    else
        printf("\nElement not found\n");
}

