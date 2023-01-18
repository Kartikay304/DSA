#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
}N;

N *head=NULL;

void insert()
{
    N *new_node = (N *)malloc(sizeof(N));
    N *temp=head;
    int data;
    printf("Enter the number::");
    scanf("%d",&data);
    new_node->data=data;
    if(head==NULL)
    {
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=NULL;
    }
}

void display(N *node)
{
    while(node!=NULL)
    {
    printf("%d ", node->data);
    node = node->next;
    }
}

void reverse()
{
    N *previous=NULL;
    N *current=head;
    N *next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    head=previous;
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n MENU\n1 Insert(traversal)\n");
        printf("2 Reversal\n");
        printf("3 Display\n");
        printf("4 Exit\n");
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert(); break;
            case 2: reverse(); break;
            case 3: display(head); break;
            case 4: exit(0);
            default : printf("invalid choice");
        }
    }
    return 0;
}