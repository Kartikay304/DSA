/* Write a C Program implement  priority QUEUE using array in menu driven form. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct QUEUE {
    int arr[2][MAX];
    int front;
}Q;

int priority(Q *ptr) {
    int max_priority=ptr->arr[1][0],max_index=0;
    for(int j=0;j<=ptr->front;j++) {
        if(max_priority<ptr->arr[1][j]) {
            max_priority=ptr->arr[1][0];
            max_index=j;
        }
    }
    return max_index;
}

void enqueue(Q *ptr) {
    int num,priority;
    ptr->front+=1;
    printf("Enter number::");
    scanf("%d",&num);
    printf("Enter priority::");
    scanf("%d",&priority);
    ptr->arr[0][ptr->front]=num;
    ptr->arr[1][ptr->front]=priority;
}

void dequeue(Q *ptr) {
    int dq_index=priority(ptr);
    for(int i=dq_index;i<ptr->front;i++) {
        ptr->arr[0][i]=ptr->arr[0][i+1];
        ptr->arr[1][i]=ptr->arr[1][i+1];
    }
    ptr->front--;
}

void display(Q *ptr) {
    for(int i=0;i<=ptr->front;i++) {
        printf("%d ",ptr->arr[0][i]);
    }
}

int main() {
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    Q *ptr=(Q*)malloc(sizeof(Q));
    ptr->front=-1;
    int ch;
    printf("\nMENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch){
            case 1: enqueue(ptr); break;
            case 2: dequeue(ptr); break;
            case 3: display(ptr); break;
            case 4: return 0;
        }
    }
}