#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1
#define MAX 100

typedef struct Queue
{
    int front;
    int rear;
    int *arr;
}Q;

int isfull(Q *q)
{
    if(q->front>q->rear || (q->front==0 && q->rear==MAX-1))
    {
        printf("Queue is full\n");
        return 1;
    }
    return 0;
}

int isempty(Q *q)
{
    if(q->front==-1)
    {
        printf("Queue is Empty\n");
        return 1;
    }
    return 0;
}

void enqueue(Q *q)
{
    if(!isfull(q))
    {
        if(q->front==-1) q->front=0;
        int num;
        printf("Enter the number to be Enqueued::");
        scanf("%d",&num);
        q->rear=(q->rear+1)%MAX;
        q->arr[q->rear]=num;
        printf("SUCCESS");
    }
}

void dequeue(Q *q)
{
    #if DEBUG
    printf("\nCurrent element for Dequeue:: %d\n",q->arr[q->front]);
    #endif

    if(!isempty(q))
    {
        if(q->front==q->rear)
        {
            q->rear=-1;
            q->front=-1;
        }
        else
        {
            q->front=(q->front+1)%MAX;
            printf("SUCCESS %d Dequeued",q->arr[q->front]);
        }
    }
}

void display(Q *q)
{
    int i;
    if(!isempty(q))
    {
        for(i=q->front;i!=q->rear;i=(i+1)%MAX)
        {
            printf("%d ",q->arr[i]);
        }
        printf("%d ", q->arr[i]);
    }
}

int main()
{
    Q *q=(Q*)malloc(sizeof(Q));
    q->arr=(int*)malloc(MAX*sizeof(int));
    q->front=-1;
    q->rear=-1;
    int ch;
    while(1)
    {
        printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(q); break;
            case 2: dequeue(q); break;
            case 3: display(q); break;
            case 4: exit(0);
        }
        scanf("waiting to exit %d",&ch);
    }
    return 0;
}