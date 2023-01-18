/* Write a C program to create a circular link list by adding the nodes in right hand side and then print the list. */

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}N;

void insert(N **last) {
    N *new_node=(N*)malloc(sizeof(N));
    int data;
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    if((*last)==NULL) {
        new_node->next=new_node;
        (*last)=new_node;
    }
    else {
        new_node->next=(*last)->next;
        (*last)->next=new_node;
    }
}

void display(N **last) {
    N *temp;
    temp=(*last)->next;
    do {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=(*last)->next);
}

int main() {
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    int ch;
    N *last=NULL;
    printf("\n<---------------------->\n");
    printf("|         MENU          |\n");
    printf("<---------------------->\n");
    printf("|      1.Insert         |\n");
    printf("|      2.Display        |\n");
    printf("|      3.Exit           |\n");
    printf("<---------------------->\n");
    while(1)
    {
        printf("\nEnter your choice (1-4)::");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: insert(&last); break;
            case 2: display(&last); break;
            case 3: exit(0); break;
        }
    }
}