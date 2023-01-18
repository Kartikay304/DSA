// linked list using array end_addition 
// only front addition at head = Null
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}N;

void create(int a[], N** head)
{
    int i;
    N *temp;
    for (i=0;i<6;i++)
    {
        N *new_node=(N*)malloc(sizeof(N));
        new_node->data=a[i];
        if(*head == NULL)
        {
            new_node->next=(*head);
            (*head)=new_node;
        }
        else
        {
            temp = *head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next = new_node;
            new_node->next=NULL;
        }
    }
}
void display(N *node)
{
    printf("data-");printf("\u2192");
    while(node!=NULL)
    {
        printf(" %d ", node->data);       
        node = node->next;
    }
}
int main()
{
    N *head=NULL;
    int a[] = {1,2, 3, 4, 5, 6};
    create(a,&head);
    display(head);
    return 0;
}