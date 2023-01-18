#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}N;

N *head=NULL;

void front_addition()
{
    N *new_node=(N*)malloc(sizeof(N));
    int data;
    printf("Enter the data::");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=head;
    head=new_node;
}

void end_addition()
{
    N *new_node=(N*)malloc(sizeof(N));
    int data;
    N *temp=head;
    printf("Enter the data::");
    scanf("%d",&data);
    if(head==NULL)
    {
        new_node->data=data;
        new_node->next=head;
        head=new_node;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next; 
        }
        new_node->data=data;
        temp->next=new_node;
        new_node->next=NULL;
    }
}

void random_addition()
{
    N *new_node=(N*)malloc(sizeof(N));
    int data,position;
    N *temp=head;
    new_node->next=NULL;
    printf("Enter the data::");
    scanf("%d",&data);
    printf("Enter the position::");
    scanf("%d",&position);
    if(head==NULL)
    {
        new_node->data=data;
        new_node->next=head;
        head=new_node;
    }
    else
    {
        for(int i=2;i<position;i++)
        {
            if(temp->next==NULL)
            {
                break;
            }
            temp=temp->next;
        }
        new_node->data=data;
        new_node->next=temp->next;
        temp->next=new_node;
    }
}

void display(N *node)
{
    while (node!=NULL)
    {
        printf("%d ",node->data);
        node=node->next;
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\nMENU\n1.Front_addition\n2.End_addition\n3.Random_addition\n4.Display\n5.Exit\n");
        printf("Enter your choice::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: front_addition(); break;
            case 2: end_addition(); break;
            case 3: random_addition(); break;
            case 4: display(head); break;
            case 5: exit(0);
        }
    }
    return 0;
}