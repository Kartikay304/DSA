#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Queue
{
    int front;
    int **arr;
}Q;

int priority(Q *q)
{
    int j,max_priority=q->arr[1][0],max_index=0;
    for(j=0;j<=q->front;j++)
    {
        if(q->arr[1][j]>max_priority)
        {
            max_priority=q->arr[1][j];
            max_index=j;
        }
    }
    return max_index;
}

void  enqueue(Q *q)
{
    q->front+=1;
    int num,priority;
    printf("Enter the number::");
    scanf("%d",&num);
    printf("Enter the priority::");
    scanf("%d",&priority);
    q->arr[0][q->front]=num;
    q->arr[1][q->front]=priority;
}

void  dequeue(Q *q)
{
    int dq_index=priority(q);
    int j;
    for(j=dq_index;j<=q->front;j++)
    {
        q->arr[0][j]=q->arr[0][j+1];
        q->arr[1][j]=q->arr[1][j+1];
    }
    q->front--;
}

void  display(Q *q)
{
    int j;
    for(j=0;j<=q->front;j++)
    {
        printf("Number is::%d Priority is::%d\n",q->arr[0][j],q->arr[1][j]);
    }
}

int main()
{
    Q *q=(Q*)malloc(sizeof(Q));
    int i;
    q->arr=(int**)malloc(2*sizeof(int));
    for(i=0;i<2;i++)
    {
        *(q->arr + i)=(int*)malloc(MAX*sizeof(int));
    }
    q->front=-1;
    int ch;
    while(1)
    {
        printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(q); break;
            case 2: dequeue(q); break;
            case 3: display(q); break;
            case 4: exit(0);
        }
    }
}