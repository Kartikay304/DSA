/* Write a C Program implement QUEUE using Link List  in menu driven form. */

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}N;

int isEmpty(struct NODE **head) {
    if (*head == NULL) return 1;
    else return 0;
}

void enqueue(N **head, N**top){
    int data;
    N *new_node=(N*)malloc(sizeof(N));
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
    *top=new_node;
}

void dequeue(N **head, N **top) {
    if (isEmpty(head)) {
        printf("\nStack is Empty\n");
        return;
    }
    else {
        N *temp=*head;
        N *temp1=NULL;
        if(temp->next==NULL){
            temp=temp->next;
            free(temp);
        }
        else {
        while(temp->next->next!=NULL) temp=temp->next;
        temp1=temp->next;
        temp->next=NULL;
        free(temp1);
        *top=temp;
        }
    }
}

void display(N *node) {
  while (node != NULL) {
    printf("%d", node->data);
    node = node->next;
    if(node != NULL) printf("-->");
  }
  printf("\n");
}

int main() {
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    N *head=NULL, *top=NULL;
    int ch;
    printf("\n<---------------------->\n");
    printf("|       MENU           |\n");
    printf("<---------------------->\n");
    printf("|     1.Enqueue        |\n");
    printf("|     2.Dequeue        |\n");
    printf("|     3.DISPLAY        |\n");
    printf("|     4.EXIT           |\n");
    printf("<---------------------->\n");
    while(1) {
        printf("\nEnter your choice (1-4)::");
        scanf("%d",&ch);
        switch (ch) {
            case 1: enqueue(&head,&top); break;
            case 2: dequeue(&head,&top);break;
            case 3: display(head); break;
            case 4: exit(0); break;
        }
    }
}