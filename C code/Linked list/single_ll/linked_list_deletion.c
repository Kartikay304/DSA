#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}N;

N *head=NULL;

void insertion()
{
    int data;
    N *new_node=(N*)malloc(sizeof(N));
    N *temp=head;
    printf("Enter data::");
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

void front_delete()
{
    N *temp=head;
    head=head->next;
    free (temp);
}

void random_delete()
{
    int position;
    printf("Enter position::");
    scanf("%d",&position);
    N *current=head;
    if (head == NULL) 
    {
      return;
    }
    if (position == 1) {
      head = current->next;
      free(current);
      return;
    }
    for(int i=1;current!=NULL && i<position-1;i++)
    {
        current=current->next;
    }
    if (current == NULL || current->next == NULL) return;
    N *next=current->next->next;
    free (current->next);
    current->next=next;
}

void end_delete()
{
    N *temp=head;
    N *temp1=NULL;
    while(temp->next->next!=NULL) temp=temp->next;
    temp1=temp->next;
    temp->next=NULL;
    free(temp1);
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
    printf("\n<---------------------->\n");
    printf("|         MENU         |\n");
    printf("<---------------------->\n");
    printf("|     1.Insertion      |\n");
    printf("|     2.Front_Deletion |\n");
    printf("|     3.Random_Deletion|\n");
    printf("|     4.End_Deletion   |\n");
    printf("|     5.Display        |\n");
    printf("|     6.Exit           |\n");
    printf("<---------------------->\n");
    while(1)
    {
        printf("\nEnter your choice (1-6)::");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: insertion(); break;
            case 2: front_delete(); break;
            case 3: random_delete(); break;
            case 4: end_delete(); break;
            case 5: display(head); break;
            case 6: exit(0); break;
        }
    }
    return 0;
}