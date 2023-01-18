#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Queue
{
    int front;
    int rear;
    int arr[MAX];
}Q;

int isfull(Q *q)
{
    if(q->rear==MAX-1)
    {
        printf("\nQueue is Full");
        return 1;
    }
    return 0;
}

int isempty(Q *q)
{
    if(q->front==-1 || q->front>q->rear)
    {
        printf("\nQueue is Empty");
        return 1;
    }
    return 0;
}

void enqueue(Q *q)
{
    if(!isfull(q))
    {
        q->front=0;
        q->rear+=1;
        int num;
        printf("Enter the number::");
        scanf("%d",&num);
        q->arr[q->rear]=num;
    }
}

void dequeue(Q *q)
{
    if(!isempty(q))
    {
        printf("The element %d is dequeued.\n",q->arr[q->front]);
        q->front+=1;
    }
}

void display(Q *q)
{
    int i;
    if(!isempty(q))
    {
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d ",q->arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    Q* q=(Q*)malloc(sizeof(Q));
    int ch;
    q->arr[MAX]=(int)malloc(MAX*sizeof(int));
    q->front=-1;
    q->rear=-1;
    while(1)
    {
        printf("\n\nMENU \n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit\n\n");
        printf("Enter your Choice::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(q); break;
            case 2: dequeue(q); break;
            case 3: display(q); break;
            case 4: exit(0);
        }
    }
    return 0;
}