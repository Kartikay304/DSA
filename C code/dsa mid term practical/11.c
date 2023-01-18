/* Write a C program to Evaluate Postfix Expression using Stack */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct stack
{
    int size;
    int top;
    int* stk;
}s;

int isempty(s *ptr)
{
    return (ptr->top==-1)?1:0;
}

int isfull(s* ptr)
{
    return (ptr->top==ptr->size-1)?1:0;
}

void push(s* ptr,char val)
{
    if(!isfull(ptr))
    {
        ptr->top++;
        ptr->stk[ptr->top]=val;
    }

}

char pop(s* ptr)
{
    char val;
    return val = (!isempty(ptr))?(ptr->stk[ptr->top--]):val;
}

int operator(char ch)
{
    return (ch=='+'||ch=='-'||ch=='/'||ch=='*')?1:0;
}

int postfixEvaluation(s* ptr,char* postfix)
{
    int i=0;
    ptr->top=-1;
    ptr->size=strlen(postfix);
    ptr->stk=(int*)malloc((strlen(postfix))*sizeof(int));
    while(postfix[i]!='\0')
    {
        (!operator(postfix[i]))?(push(ptr,postfix[i]-'0')):({int val1 = pop(ptr);int val2 = pop(ptr);switch(postfix[i]){case '+': push(ptr,val2+val1); break;case '-': push(ptr,val2-val1); break;case '/': push(ptr,val2/val1); break;case '*': push(ptr,val2*val1); break;}});
        i++;
    }
    return pop(ptr);
}

int main()
{
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    int i;
    s* ptr = (s*)malloc(sizeof(s));
    char* postfix;
    printf("Enter postfix expression:: ");
    gets(postfix);
    printf("Evaluated expression::%d",postfixEvaluation(ptr,postfix));
    return 0;
}
