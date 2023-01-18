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
    printf("Entert data::");
    scanf("%d",&data);
    new_node->data=data;
    if(head==NULL) {
        head=new_node;
        new_node->next=NULL;
    }
    else {
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new_node;
        new_node->next=NULL;
    }
}

void display(N *node) {
    while(node!=NULL) {
        printf("%d ",node->data);
        node=node->next;
    }
}

void make_loop() {
    N *temp=head;
    N *last=head;
    int pos;
    printf("Enter the position::");
    scanf("%d",&pos);
    for(int i=1;i<pos;i++) {
        temp=temp->next;
    }
    while(last->next!=NULL) last=last->next;
    last->next=temp;
}

int detect_loop() {
    N *temp1=head;
    N *temp2=head;
    while(temp1!=NULL) {
        while(temp2->next!=NULL) {
            if(temp1->next==temp2->next) return 1;
            else return 0;
        }
    }
}


int main() {
    int ch,flag;
    printf("\n<----------------------->\n");
    printf("|         MENU          |\n");
    printf("<----------------------->\n");
    printf("|      1.Insert         |\n");
    printf("|      2.Make_loop      |\n");
    printf("|      3.Detect_loop    |\n");
    printf("|      4.Display        |\n");
    printf("|      5.Exit           |\n");
    printf("<----------------------->\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: insert(); break;
        case 2: make_loop(); break;
        case 3: flag=detect_loop(); if(flag==1) printf("Loop detected"); else printf("Loop not detected"); break;
        case 4: display(head); break;
        case 5: exit(0); break;
        }
    }
    return 0;
}