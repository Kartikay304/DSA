#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}N;

N *head=NULL;

void insert()
{
    int data;
    N *new_node=(N*)malloc(sizeof(N));
    N *temp=head;
    printf("Enter data::");
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
        new_node->next=NULL;
        temp->next=new_node;
    }
}

void delete()
{
    N *temp1=head;
    N *temp2=head;
    N *dup;
    while(temp1!=NULL && temp1->next!=NULL)
    {
        while(temp2!=NULL && temp2->next!=NULL)
        {
            if(temp1->data==temp2->next->data)
            {
                dup=temp1->next;
                temp2->next=temp2->next->next;
                free(dup);
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

void display(N *node)
{
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node=node->next;
    }
}

int main()
{
    int ch;
    printf("\n<----------------------->\n");
    printf("|         MENU          |\n");
    printf("<----------------------->\n");
    printf("|    1.Insertion        |\n");
    printf("|    2.Delete_Dublicate |\n");
    printf("|    3.Display          |\n");
    printf("|    4.Exit             |\n");
    printf("<----------------------->\n");
    while(1)
    {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: insert(); break;
        case 2: delete(); break;
        case 3: display(head); break;
        case 4: exit(0);
        }
    }
    return 0;
}