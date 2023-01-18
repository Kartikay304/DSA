#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

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

void front_enqueue(Q *q)
{
    if(!isfull(q))
    {
        if(q->front==-1)
        {
            q->front=0;
            q->rear+=1;
            int num;
            printf("Enter the number::");
            scanf("%d",&num);
            q->arr[q->rear]=num;
        }
        else if(q->front>0)
        {
        q->front-=1;
        int num;
        printf("Enter the number::");
        scanf("%d",&num);
        q->arr[q->front]=num;
        }
        else{
            printf("no space in first");
        }
    }
}

void end_enqueue(Q *q)
{
    if(!isfull(q))
    {
        if(q->front==-1) q->front=0;
        q->rear+=1;
        int num;
        printf("Enter the number::");
        scanf("%d",&num);
        q->arr[q->rear]=num;
    }
}

void front_dequeue(Q *q)
{
    if(!isempty(q))
    {
        printf("The element %d is dequeued.\n",q->arr[q->front]);
        q->front+=1;
    }
}

void end_dequeue(Q *q)
{
    if(!isempty(q))
    {
        printf("The element %d is dequeued.\n",q->arr[q->rear]);
        q->rear-=1;
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
        printf("\nMENU\n1.Front_Enqueue\n2.End_Enqueue\n3.Front_Dequeue\n4.End_Dequeue\n5.Display\n6.Exit\n");
        printf("Enter your Choice::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: front_enqueue(q); break;
            case 2: end_enqueue(q); break;
            case 3: front_dequeue(q); break;
            case 4: end_dequeue(q); break;
            case 5: display(q); break;
            case 6: exit(0);
        }
    }
    return 0;
}