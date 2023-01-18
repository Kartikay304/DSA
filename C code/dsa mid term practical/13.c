/* Write C program to create a doubly link list by adding the node right hand side and then check list is in palindrome form or not. */

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *previous;
    struct NODE *next;
}N;

void insert(N **head) {
    int data;
    N *new_node=(N*)malloc(sizeof(N));
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=(*head);
    new_node->previous=NULL;
    if ((*head)!=NULL) (*head)->previous = new_node;
    (*head) = new_node;
}

void check(N *node) {
    N *last;
    int digit_fordward=0,digit_reverse=0;
    while(node!=NULL) {
        digit_fordward=digit_fordward*10+node->data;
        last=node;
        node=node->next;
    }
    while(last!=NULL) {
        digit_reverse=digit_reverse*10+last->data;
        last=last->previous;
    }
    if(digit_fordward==digit_reverse) printf("\nLinked List is palindrome\n");
    else printf("\nLinked List is not palindrome\n");
}

void display(N *node) {
    N *last;
    printf("\nTraversal in forward direction \n");
    while(node!=NULL) {
        printf("%d ",node->data);
        last=node;
        node=node->next;
    }
    printf("\nTraversal in reverse direction \n");
    while(last!=NULL) {
        printf("%d ",last->data);
        last=last->previous;
    }
}

int main() {
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    N *head=NULL;
    int ch;
    printf("\n<---------------------->\n");
    printf("|         MENU         |\n");
    printf("<---------------------->\n");
    printf("|      1.Insert         |\n");
    printf("|      2.Check          |\n");
    printf("|      3.Display        |\n");
    printf("|      4.Exit           |\n");
    printf("<---------------------->\n");
    while(1)
    {
        printf("\nEnter your choice (1-4)::");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: insert(&head); break;
            case 2: check(head); break;
            case 3: display(head); break;
            case 4: exit(0); break;
        }
    }
}