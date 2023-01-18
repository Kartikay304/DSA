/* Write a C program to create TWO singly linked list L1 and L2 and sort both the list and finally merge both the list such that L2 comes after L1.[ use double pointer] */

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}N;

void insert(N **head) {
    N *new_node=(N*)malloc(sizeof(N));
    N *temp=*head;
    int data;
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    if(*head==NULL) {
        new_node->next=NULL;
        *head=new_node;
    }
    else {
        while(temp->next!=NULL) temp=temp->next;
        new_node->next=NULL;
        temp->next=new_node;
    }
}

void sort(N **head) {
    N *temp=*head;
    int temp2=0;
    while(temp->next!=NULL) {
        if(temp->data>temp->next->data) {
            temp2=temp->data;
            temp->data=temp->next->data;
            temp->next->data=temp2;
        }
        temp=temp->next;
    }
}

void merge(N **head1, N **head2) {
    N *temp2=*head2;
    while(temp2->next!=NULL) {
        temp2=temp2->next;
    }
    temp2->next=*head1;
}

void display(N *node)
{
    while (node!=NULL)
    {
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}

int main() {
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    N *head1=NULL, *head2=NULL;
    int ch;
    printf("\n<---------------------->\n");
    printf("|         MENU         |\n");
    printf("<---------------------->\n");
    printf("|     1.Insert in ll 1 |\n");
    printf("|     2.Insert in ll 2 |\n");
    printf("|     3.Sort           |\n");
    printf("|     4.Merge          |\n");
    printf("|     5.Display        |\n");
    printf("|     6.Exit           |\n");
    printf("<---------------------->\n");
    while(1)
    {
        printf("\nEnter your choice (1-5)::");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: insert(&head1); break;
            case 2: insert(&head2); break;
            case 3: sort(&head1); sort(&head2);break;
            case 4: merge(&head2,&head1); break;
            case 5: printf("Elements in LL 1 ::");display(head1);printf("Elements in LL 2 ::"); display(head2); break;
            case 6: exit(0); break;
        }
    }
}