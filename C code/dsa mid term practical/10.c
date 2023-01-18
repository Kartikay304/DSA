/* Write a C Program implement QUEUE using array in menu driven form. */

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

int main() {
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    int ch;
    Q *ptr=(Q*)malloc(sizeof(Q));
    ptr->front=-1;
    ptr->rear=-1;
    printf("\n<---------------------->\n");
    printf("|         MENU         |\n");
    printf("<---------------------->\n");
    printf("|       1.Enqueue      |\n");
    printf("|       2.Dequeue      |\n");
    printf("|       3.Display      |\n");
    printf("|       4.Exit         |\n");
    printf("<---------------------->\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch){
            case 1: enqueue(ptr); break;
            case 2: dequeue(ptr); break;
            case 3: display(ptr); break;
            case 4: return 0;
        }
    }
}