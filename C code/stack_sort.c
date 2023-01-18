#include <stdio.h>
#include <stdlib.h>
//LinkedList is used to represent Stack:
struct stack
{
    int info;
    struct stack *next;
};
//Function to initialize stack:
void initializeStack(struct stack **start)
{
    *start = NULL;
}
//Function to check stack is empty:
int isEmpty(struct stack *start)
{
    if (start == NULL)
        return 1;
    return 0;
} 
//Function to push an item into stack
void push(struct stack **start, int a)
{
    struct stack *p = (struct stack *)malloc(sizeof(*p));
    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    p->info = a;
    p->next = *start;
    *start = p;
}
//Function to remove an item from stack
int pop(struct stack **start)
{
    int a;
    struct stack *temp;
    a = (*start)->info;
    temp = *start;
    (*start) = (*start)->next;
    free(temp);
    return a;
}
// Function to find top item
int top(struct stack *start)
{
    return (start->info);
}
void printingStack(struct stack *start)
{
    while (start)
    {
        printf("%d ", start->info);
        start = start->next;
    }
    printf("\n");
}
// Recursive function to insert an item a in sorted way
void sortedInsert(struct stack **start, int a)
{
    if (isEmpty(*start) || a > top(*start))
    {
        push(start, a);
        return;
    }
    int temp = pop(start);
    sortedInsert(start, a);
    push(start, temp);
}
// Function to sort stack
void sortStack(struct stack **start)
{
    if (!isEmpty(*start))
    {
        int a = pop(start);
        sortStack(start);
        sortedInsert(start,a);
    }
}
int main(void)
{
    struct stack *top;
    initializeStack(&top);
    push(&top, 20);
    push(&top, -5);
    push(&top, 19);
    push(&top, 15);
    push(&top, -3);
    printf("Stack elements before sorting:\n");
    printingStack(top);
    sortStack(&top);
    printf("\n\n");
    printf("Stack elements after sorting:\n");
    printingStack(top);
    return 0;
}