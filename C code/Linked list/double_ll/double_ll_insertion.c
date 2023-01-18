#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *previous;
    struct NODE *next;
}N;

N *head=NULL;

void front_insert() {
    int data;
    N *new_node=(N*)malloc(sizeof(N));
    N *temp=head;
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=head;
    new_node->previous=NULL;
    if (head!=NULL)
    head->previous = new_node;
    head = new_node;
}

void end_insert() {
    int data;
    N *new_node=(N*)malloc(sizeof(N));
    N *temp=head;
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    if(head==NULL) {
        new_node->previous=head;
        new_node->next=NULL;
        head=new_node;
    }
    else {
        while(temp->next!=NULL) temp=temp->next;
        new_node->next=NULL;
        new_node->previous=temp;
        temp->next=new_node;
    }
}

void random_insert() {
    int data,position;
    N *new_node=(N*)malloc(sizeof(N));
    N *next_node=head;
    printf("Enter data::");
    scanf("%d",&data);
    printf("Enter position::");
    scanf("%d",&position);
    position--;
    new_node->data=data;
    for(int i=0;i<position;i++){
        next_node=next_node->next;
        }
    if(next_node == NULL) printf("Invalid!!!!");
    new_node->previous = next_node->previous;
    new_node->next = next_node;
    next_node->previous = new_node;
    if(new_node->previous!=NULL) {
        new_node->previous->next = new_node;
    } else {
        head = new_node;
    }
}

void display_next(N *node) {
    while(node!=NULL) {
        printf("%d ",node->data);
        node=node->next;
    }
}

void display_prev(N *node) {
    while(node->next!=NULL) {
        node=node->next;
    }
    while(node!=NULL) {
        printf("%d ",node->data);
        node=node->previous;
    }
}

int main() {
    int ch;
    printf("\n<----------------------->\n");
    printf("|         MENU          |\n");
    printf("<----------------------->\n");
    printf("|    1.Front_Insert     |\n");
    printf("|    2.End_Insert       |\n");
    printf("|    3.Random_Insert    |\n");
    printf("|    4.Display_next     |\n");
    printf("|    5.Display_prev     |\n");
    printf("|    6.Exit             |\n");
    printf("<----------------------->\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch) {
            case 1: front_insert(); break;
            case 2: end_insert(); break;
            case 3: random_insert(); break;
            case 4: display_next(head); break;
            case 5: display_prev(head); break;
            case 6: exit(0); break;
        }
    }
    return 0;
}