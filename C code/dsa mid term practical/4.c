/* Write a C Program implement STACK using array in menu driven form. */

#include <stdio.h>
#define MAX 100

typedef struct STACK {
    int arr[MAX];
    int top;
}s;

void push(s *ptr) {
    int num;
    printf("Enter number::");
    scanf("%d",&num);
    ptr->arr[++ptr->top]=num;
}

void pop(s *ptr) {
    ptr->top--;
}

void display(s *ptr) {
    for(int i=ptr->top;i>=0;i--) {
        printf("%d ",ptr->arr[i]);
    }
}

int main() {
    s *ptr,pos;
    ptr=&pos;
    ptr->top = -1;
    int n;
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    printf("\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    while(1)
    {
        printf("\nEnter your choice::");
        scanf("%d",&n);
        switch(n)
        {
            case 1: push(ptr);
            break;
            case 2: pop(ptr);
            break;
            case 3: display(ptr);
            break;
            case 4: return 0;
        }
    }
}