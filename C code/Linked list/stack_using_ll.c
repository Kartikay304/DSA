#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}N;

N *top=NULL;

void push(){
    int data;
    printf("Enter data::");
    scanf("%d",&data);
    N *new_node=(N*)malloc(sizeof(N));
    new_node->data=data;
    new_node->next=top;
    top=new_node;
}

void pop() {
    N *temp=top;
    if(top==NULL) {
        printf("STACK is EMPTY");
        return;
    }
    top=top->next;
    free(temp);
}

void peek() {
    printf("%d",top->data);
}

void display(N *top) {
    N *temp=top;
    if(temp!=NULL) {
        display(temp->next);
        printf("%d ",temp->data);
    }
}

int main() {
    int ch;
    printf("\n<---------------->\n");
    printf("|      MENU      |\n");
    printf("<----------------->\n");
    printf("|    1.PUSH      |\n");
    printf("|    2.POP       |\n");
    printf("|    3.PEEK       |\n");
    printf("|    4.DISPLAY   |\n");
    printf("|    5.Exit      |\n");
    printf("<---------------->\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(top); break;
            case 5: exit(0);
        }
    }
    return 0;
}