// INFIX to POSTFIX
// applicable only for + - / * 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int size;
    int top;
    char *stk;
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

int precedence(char ch)
{
    return ((ch=='+'||ch=='-')?2:(ch=='*' || ch=='/')?3:0);
}

char* infixtopostfix(s* ptr,char* infix)
{
    int i=0,j=0;
    ptr->top = -1;
    ptr->stk = (char *) malloc(ptr->size * sizeof(char));
    char *b = (char *)malloc((strlen(infix)+1)*sizeof(char));
    while(infix[i]!='\0')
    {
        b[j]= (!operator(infix[i]))?({b[j]=infix[i];i++;j++;}):((precedence(infix[i])>precedence(ptr->stk[ptr->top]))?({push(ptr,infix[i]);i++;}):({b[j]=pop(ptr);j++;}));
    }
    while(!isempty(ptr))
    {
        b[j] = pop(ptr);
        j++;
    }
    b[j] = '\0';
    return b;
}

int main()
{
    s* ptr = (s*)malloc(sizeof(s));
    char* infix;
    gets(infix);
    ptr->size = strlen(infix);
    printf("postfix is %s", infixtopostfix(ptr, infix));
    return 0;
}