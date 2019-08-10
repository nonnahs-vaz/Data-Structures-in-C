//C program to implement dequeue using arrays (delete restricted)
#include<stdio.h>
#define SIZE 4
int dq[SIZE],FRONT=-1,REAR=-1;
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
void insert_at_front(int data)
{
    int i;
    if(REAR==SIZE-1)    //checking if queue is full
    {
        printf("\nQueue is full");
        return;
    }
    if(FRONT==-1)   //inserting first element
    {
        dq[++FRONT]=data;
        REAR++; //FRONT & REAR both pointing to 0th position
    }
    else    //inserting at front
    {
        for(i=++REAR ; i>FRONT ; i--)   //loop for shifting elements right
            dq[i]=dq[i-1];
        dq[i]=data; //placing element at front
    }
    printf("\n%d was inserted at front\nUpdated queue is:",data);
    display();
}
void insert_at_end(int data)
{
    if(REAR==SIZE-1)    //checking if queue is full
    {
        printf("\nQueue is full");
        return;
    }
    if(FRONT==-1)   //inserting first element
    {
        dq[++REAR]=data;
        FRONT++;    //FRONT & REAR both pointing to 0th position
    }
    else
        dq[++REAR]=data;    //inserting at rear position
    printf("\n%d was inserted at front\nUpdated queue is:",data);
    display();
}
void del_front()
{
    int i;
    if(FRONT==-1)   //checking if queue is empty
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\n%d is deleted\nUpdated queue is:",dq[FRONT]);
    for(i=FRONT ; i<REAR ; i++) //loop for shifting elements towards left
        dq[i]=dq[i+1];
    if((--REAR)==-1)    //decrementing REAR since element one element is reduced and checking if queue is empty
        FRONT=-1;   //resetting FRONT pointer if queue is empty
    display();
}
void display()
{
    int i;
    if(FRONT==-1)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nFRONT ->");
    for(i=FRONT ; i<=REAR ; i++)
        printf(" %d ->",dq[i]);
    printf(" REAR\n");
}
