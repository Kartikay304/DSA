#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *previous;
    struct NODE *next;
}N;

N *head=NULL;

void insert() {
    int data;
    N *temp=head;
    printf("Enter data::");
    scanf("%d",&data);
    N *new_node=(N*)malloc(sizeof(N));
    new_node->data=data;
    if(head==NULL) {
        new_node->next=NULL;
        new_node->previous=NULL;
        head=new_node;
    }
    else {
        while(temp->next!=NULL) temp=temp->next;
        new_node->next=NULL;
        new_node->previous=temp;
        temp->next=new_node;
    }
}

void front_delete() {
    N *temp=head;
    head=head->next;
    head->previous=NULL;
    free(temp);
}

void end_delete() {
    N *temp=head;
    while(temp->next->next!=NULL) temp=temp->next;
    free(temp->next);
    temp->next=NULL;
}

void random_delete() {
    N *temp=head;
    int position;
    printf("Enter the posiiton::");
    scanf("%d",&position);
    if (temp == NULL || temp->next == NULL) return;
    for(int i=0;i<position-1;i++)
    {
        temp=temp->next; 
    }
    if(position==1) {
        front_delete();
        return;
    }
    else if(temp->next==NULL) {
        end_delete();
        return;
    }
    else {
        temp=temp->previous;
        N *next=temp->next->next;
        free (temp->next);
        temp->next=next;
        next->previous=temp;
    }
}

void display_next(N *NODE) {
    while(NODE!=NULL) {
        printf("%d ",NODE->data);
        NODE=NODE->next;
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
    printf("|    1.Insert           |\n");
    printf("|    2.Front_Delete     |\n");
    printf("|    3.Random_Delete    |\n");
    printf("|    4.End_Delete       |\n");
    printf("|    5.Display_next     |\n");
    printf("|    6.Display_prev     |\n");
    printf("|    7.Exit             |\n");
    printf("<----------------------->\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch) {
            case 1: insert(); break;
            case 2: front_delete(); break;
            case 3: random_delete(); break;
            case 4: end_delete(); break;
            case 5: display_next(head); break;
            case 6: display_prev(head); break;
            case 7: exit(0); break;
        }
    }
    return 0;
}