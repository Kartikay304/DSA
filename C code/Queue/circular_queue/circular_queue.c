#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int isfull(int *rptr,int *fptr)
{
    if((*fptr == *rptr + 1) || (*fptr == 0 && *rptr == MAX - 1))
    {
        printf("\nQueue is Full\n");
        return 1;
    }
    return 0;
}

int isempty(int *fptr,int *rptr)
{
    if(*fptr==-1)
    {
        printf("\nQueue is Empty\n");
        return 1;
    }
    return 0;
}

void enqueue(int arr[],int *fptr,int *rptr)
{
    if(!isfull(rptr,fptr))
    {
        int num;
        printf("Enter the number to be enqueued::");
        scanf("%d",&num);
        if (*fptr == -1) *fptr = 0;
        *rptr = (*rptr + 1) % MAX;
        arr[*rptr] = num;
    }
}

void dequeue(int arr[],int *fptr,int *rptr)
{
    if(!isempty(fptr,rptr))
    {
        int element = arr[*fptr];
        if (*fptr == *rptr) {
        *fptr = -1;
        *rptr = -1;
        }
        else {
        *fptr = (*fptr + 1) % MAX;
        }
    }
}

void display(int arr[],int *fptr,int *rptr)
{
    int i;
    if(!isempty(fptr,rptr))
    {
        printf("\n Front -> %d ", *fptr);
        printf("\n Items -> ");
        for (i = *fptr; i != *rptr; i = (i + 1) % MAX)
        {
            printf("%d ", arr[i]);
        }
        printf("%d ", arr[i]);
        printf("\n Rear -> %d \n", *rptr);
    }
}

int main()
{
    int ch;
    int front=-1,rear=-1;
    int *fptr,*rptr;
    fptr=&front;
    rptr=&rear;
    int arr[MAX];
    while(1)
    {
        printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice::");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: enqueue(arr,fptr,rptr); break;
        case 2: dequeue(arr,fptr,rptr); break;
        case 3: display(arr,fptr,rptr); break;
        case 4: exit(0);
        }
    }
    return 0;
}