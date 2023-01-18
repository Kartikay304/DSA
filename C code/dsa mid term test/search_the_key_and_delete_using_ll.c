#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}N;

N *head=NULL;

void insert() {
    int data;
    N *new_node=(N*)malloc(sizeof(N));
    N *temp=head;
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    if(head==NULL) {
        new_node->next=NULL;
        head=new_node;
    }
    else {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        new_node->next=NULL;
        temp->next=new_node;
    }
}

int find_pos() {
    int key,count=0;
    printf("Enter key::");
    scanf("%d",&key);
    N *current=head;
    while(current!=NULL)
    {
        if(current->data==key)  return count;
        count++;
        current=current->next;
    }
    return 0;
}

void delete() {
    int position=find_pos();
    if (head == NULL) return;
    N* temp = head;
    if (position == 0)
    {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i=0; temp!=NULL && i<position-1; i++) temp = temp->next;
    if (temp == NULL || temp->next == NULL) return;
    N *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void display(N *node) {
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node=node->next;
    }
}

int main() {
    int ch;
    printf("\n<----------------------->\n");
    printf("|         MENU          |\n");
    printf("<----------------------->\n");
    printf("|      1.Insertion      |\n");
    printf("|      2.Delete_key     |\n");
    printf("|      3.Display        |\n");
    printf("|      4.Exit           |\n");
    printf("<----------------------->\n");
    while (1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(head); break;
            case 4: exit(0); break;
        }
    }
    return 0;
}