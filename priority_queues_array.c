//C program to implement priority queues using array
#include<stdio.h>
#define SIZE 4
int queue[SIZE],FRONT=-1,REAR=-1;
void insert(int);
void del();
void disp();
int main()
{
    int ch;
    while(1)
    {
        printf("\n\nPriority Queue\nEnter choice\n1>Insert\n2>Remove\n3>Display\n");
        printf("\nEnter any other value to exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter data_> ");
                    scanf("%d",&ch);
                    insert(ch);
                    break;
            case 2: del();
                    break;
            case 3: disp();
                    break;
            default:return 0;
        }
    }
}

void insert(int data)
{
    int i,j,inserted=0;
    if(REAR==SIZE-1)
        printf("\nQueue overflow");
    else
    {
        if(FRONT==-1)   //inserting first element
        {
            FRONT++;    //same as setting FRONT to 0
            queue[++REAR]=data;
        }
        else
        {
            for(i=FRONT;i<=REAR;i++)    //loop for inserting in order of priority
            {
                if(data>queue[i])   //checking for priority
                {
                    for(j=REAR+1;j>i;j--)   //performing right shift
                        queue[j]=queue[j-1];
                    queue[j]=data;
                    inserted=1;     //setting flag indicating element inserted
                    break;
                }
            }
            if(!inserted)   //checking if element already inserted
                queue[++REAR]=data; //inserting element at end of queue
            else
                REAR++; //incrementing rear pointer
        }
        disp();
    }
}
void del()
{
    int i;
    if(FRONT==-1)   //checking if queue is empty
        printf("\nQueue underflow");
    else
    {
        printf("\n%d is removed",queue[FRONT]);
        for(i=FRONT;i<REAR;i++)     //shifting all elements towards left
            queue[i]=queue[i+1];
        REAR--;     //decrementing rear pointer since element was deleted
    }
    if(REAR==-1)    //resetting front pointer if queue is empty
        FRONT=-1;
    disp();
}
void disp()
{
    int i;
    if(FRONT==-1)
        printf("\nQueue underflow");
    else
    {
        printf("\nFRONT -> ");
        for(i=0;i<=REAR;i++)
            printf("%d -> ",queue[i]);
        printf("REAR\n");
    }
}
