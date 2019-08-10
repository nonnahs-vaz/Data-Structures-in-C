//C program to implement linear queue using array
#include<stdio.h>
#define SIZE 5
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
    int i;
    if(REAR==SIZE-1)
        printf("\nCannot insert, queue is full\n");
    else
    {
        printf("\nEnter data _> ");
        scanf("%d",&queue[++REAR]);
        printf("\nInsertion successful\n");
    }
}
void del()
{
    if(FRONT==REAR)
        printf("\nCannot delete, queue is empty\n");
    else
        printf("\nElement %d is deleted\n",queue[++FRONT]);

    if(FRONT==REAR)
    {
        FRONT=-1;
        REAR=-1;
    }
}
void display()
{
    int i;
    if(FRONT==REAR)
        printf("\nQueue is empty");
    else
    {
        printf("\nFRONT -> ");
        for(i=FRONT+1 ; i<=REAR ; i++)
            printf(" %d ->",queue[i]);
        printf(" REAR\n");
    }
}
void search(int x)
{
    int i;
    if(FRONT==REAR)
        printf("\nQueue is empty\n");
    else
    {
        for(i=FRONT ; i<=REAR ; i++)
        {
            if(queue[i]==x)
                break;
        }
        if(i==REAR+1)
            printf("\nElement not found\n");
        else
            printf("\nElement found at position %d\n",i);
    }
}
