#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}N;

N *head=NULL;

void check_dup(N *head)
{
    N *temp=head;
    while (temp->next != NULL) {
        N *ptr = temp->next;
        while (ptr != NULL) {
            if (temp->data == ptr->data) {
                printf("DUP FOUND");
                return;
            }
            ptr = ptr->next;
        }
        temp = temp->next;
    }
    printf("DUP NOT FOUND");
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
        printf("\nMENU\n1.End_addition\n2.Find DUP\n3.Display\n4.Exit\n");
        printf("Enter your choice::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: end_addition(); break;
            case 2: check_dup(head); break;
            case 3: display(head); break;
            case 4: exit(0);
        }
    }
    return 0;
}