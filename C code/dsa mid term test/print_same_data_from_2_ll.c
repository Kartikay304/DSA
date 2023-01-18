#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}N;

N *head1=NULL;
N *head2=NULL;

void insert(N **node) {
    int data;
    N *new_node=(N*)malloc(sizeof(N));
    N *temp= *node;
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    if(*node==NULL) {
        new_node->next=NULL;
        *node=new_node;
    }
    else {
        while(temp->next!=NULL) temp=temp->next;
        new_node->next=NULL;
        temp->next=new_node;
    }
}

void display(N *node1, N *node2) {
    while(node1!=NULL) {
        node2=head2;
        while(node2!=NULL) {
        if(node1->data==node2->data) printf("%d ",node1->data);
        node2=node2->next;
        }
        node1=node1->next;
    }
}

int main() {
    int ch;
    printf("\n<----------------------->\n");
    printf("|         MENU          |\n");
    printf("<----------------------->\n");
    printf("|      1.Insert_1       |\n");
    printf("|      2.Insert_2       |\n");
    printf("|      3.Display        |\n");
    printf("|      3.Exit           |\n");
    printf("<----------------------->\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch) {
            case 1: insert(&head1); break;
            case 2: insert(&head2); break;
            case 3: display(head1,head2); break;
            case 4: exit(0); break;
        }
    }
    return 0;
}