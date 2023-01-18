/* Write a C Program implement QUEUE using Link List  in menu driven form. */

#include <stdio.h>
#include <stdlib.h>
  
struct node {
    int data;
    struct node *next;
};
 

int isEmpty(struct node **head) {
    if (*head == NULL) return 1;
    else return 0;
}

int peek(struct node *top) {
    return top->data;
}

void push(struct node **head,struct node **top) {
    int data;
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    struct node *temp=*head;
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    if(*head==NULL)
    {
        new_node->next=*head;
        *head=new_node;
    }
    else
    {
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new_node;
        new_node->next=NULL;
    }
    *top=new_node;
}
 
void pop(struct node **head, struct node **top) {
    if (isEmpty(head)) {
        printf("\nStack is Empty\n");
        return;
    } else {
        struct node *temp=*head,*temp1;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next =NULL;
        free (temp1);
        *top=temp;
    }
}

void display(struct node *nodePtr) {
  while (nodePtr != NULL) {
    printf("%d", nodePtr->data);
    nodePtr = nodePtr->next;
    if(nodePtr != NULL)
        printf("-->");
  }
  printf("\n ");
}

int main() {
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    struct node *head=NULL, *top=NULL;
    int ch;
    printf("\n<---------------------->\n");
    printf("|       MENU           |\n");
    printf("<---------------------->\n");
    printf("|     1.PUSH           |\n");
    printf("|     2.POP            |\n");
    printf("|     3.DISPLAY        |\n");
    printf("|     4.EXIT           |\n");
    printf("<---------------------->\n");
    while(1) {
        printf("\nEnter your choice (1-4)::");
        scanf("%d",&ch);
        switch (ch) {
            case 1: push(&head,&top); break;
            case 2: pop(&head,&top);break;
            case 3: display(head); break;
            case 4: exit(0); break;
        }
    }
}