//very basic queue implimentation
#include<stdio.h>
#define MAX 100

int Enqueue(int back,int a[])
{
    int n;
    scanf("%d",&n);
    a[back]=n;
    back--;
    return back;
}

int Dequeue(int rear)
{
    rear--;
    return rear;
}

void Display(int rear,int a[],int back)
{
    int i;
    for(i=rear;i>back;i--)
    {
        printf("%d ",a[i]);
    }    
}

int main()
{
    int ch,rear=MAX-1,back=MAX-1;
    int a[MAX];
    while(1)
    {
        printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: back=Enqueue(back,a); break;
            case 2: rear=Dequeue(rear); break;
            case 3: Display(rear,a,back); break;
            case 4: return 0;
        }
    }
    return 0;
}