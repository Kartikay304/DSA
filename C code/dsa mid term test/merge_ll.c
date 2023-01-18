#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}N;

N *head1=NULL;

N *head2=NULL;

void insert(N **start) {
    int data;
    N *new_node =(N*)malloc(sizeof(N));
    N *temp=*start;
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    if(*start==NULL) {
        new_node->next=NULL;
        *start=new_node;
    }
    else {
        while(temp->next!=NULL) temp=temp->next;
        new_node->next=NULL;
        temp->next=new_node;
    }
}

void merge() {
    N *temp1=head1;
    N *temp2=head2;
    while(temp1->next!=NULL) {
        temp1=temp1->next;
    }
    temp1->next=temp2;
}

void display(N *node) {
    while(node!=NULL) {
        printf("%d ",node->data);
        node=node->next;
    }
}
int main() {
    int ch;
    printf("\n<----------------------->\n");
    printf("|         MENU          |\n");
    printf("<----------------------->\n");
    printf("|      1.Insert_on_1    |\n");
    printf("|      2.Insert_on_2    |\n");
    printf("|      3.Merge          |\n");
    printf("|      4.Display        |\n");
    printf("|      5.Exit           |\n");
    printf("<----------------------->\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch (ch) {
        case 1: insert(&head1); break;
        case 2: insert(&head2); break;
        case 3: merge(); break;
        case 4: display(head1); break;
        case 5: exit(0); break;
        }
    }
}