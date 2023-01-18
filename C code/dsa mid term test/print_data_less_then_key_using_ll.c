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
        while(temp->next!=NULL) temp=temp->next;
        new_node->next=NULL;
        temp->next=new_node;
    } 
}

void display(N *node) {
    int key;
    printf("\nEnter key::");
    scanf("%d",&key);
    while(node!=NULL) {
        if(node->data<key) printf("%d ",node->data);
        node=node->next;
    }
}

int main() {
    int ch;
    printf("\n<----------------------->\n");
    printf("|         MENU          |\n");
    printf("<----------------------->\n");
    printf("|      1.Insertion      |\n");
    printf("|      2.Display        |\n");
    printf("|      3.Exit           |\n");
    printf("<----------------------->\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch) {
            case 1: insert(); break;
            case 2: display(head); break;
            case 3: exit(0); break;
        }
    }
    return 0;
}