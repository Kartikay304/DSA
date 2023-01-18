#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}N;

N *head=NULL;

void front_insert() {
    int data;
    N *new_node=(N*)malloc(sizeof(N));
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=head;
    head=new_node;
    
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
    printf("|    1.Front_Insert     |\n");
    printf("|    2.Random_insert    |\n");
    printf("|    3.End_insert       |\n");
    printf("|    4.Display          |\n");
    printf("|    5.Exit             |\n");
    printf("<----------------------->\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch) {
            case 1: front_insert(); break;
            // case 2: random_insert(); break;
            // case 3: end_insert(); break;
            case 4: display(head); break;
            case 5: exit(0); break;
        }
    }
    return 0;
}