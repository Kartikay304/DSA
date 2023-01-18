/* Write a C Program to create  singly linked list by adding nodes in the right hand side and delete alternate node from the list and then print
   the final list. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}N;

void insert(N **head) {
    N *temp=*head;
    N *new_node=(N*)malloc(sizeof(N));
    int data;
    printf("Enter data::");
    scanf("%d",&data); 
    new_node->data=data;
    if(*head==NULL) {
        *head=new_node;
        new_node->next=NULL;
    }
    else {
        while(temp->next!=NULL) temp=temp->next;
        new_node->next=NULL;
        temp->next=new_node;
    }
}

void delete(N *head) {
    N *temp=head->next;
    if(temp==NULL)
    return;
    head->next=temp->next;
    free(temp);
    delete(head->next);
}

void display(N *node) {
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
}

int main() {
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    N *head=NULL;
    int ch;
    printf("\n<---------------------->\n");
    printf("|         MENU         |\n");
    printf("<---------------------->\n");
    printf("|     1.Insert         |\n");
    printf("|     2.Delete         |\n");
    printf("|     3.Display        |\n");
    printf("|     4.Exit           |\n");
    printf("<---------------------->\n");
    while(1)
    {
        printf("\nEnter your choice (1-5)::");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: insert(&head); break;
            case 2: delete(head); break;
            case 3: display(head); break;
            case 4: exit(0); break;
        }
    }
}