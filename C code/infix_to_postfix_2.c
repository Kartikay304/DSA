// INFIX to POSTFIX
// applicable only for + - / * ( )
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
    (!isfull(ptr))?(ptr->stk[++ptr->top]=val):0;
}

char pop(s* ptr)
{
    char val;
    return val = (!isempty(ptr))?(ptr->stk[ptr->top--]):val;
}

int operand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))?1:0;
}

int precedence(char ch)
{
    return ((ch=='+'||ch=='-')?1:((ch=='*' || ch=='/')?2:0));
}

char* infixtopostfix(s* ptr,char infix[])
{
    int i=0,j=0;
    ptr->top = -1;
    char x;
    ptr->stk = (char *) malloc(ptr->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    for(i=0;infix[i]!='\0';i++)
    {
        (operand(infix[i])?(postfix[j++]=infix[i]):((infix[i]=='(')?(push(ptr,infix[i])):((infix[i]==')')?({while((x=pop(ptr))!='('){postfix[j++] = x;}}):({while(!isempty(ptr)&&(precedence(infix[i])<=precedence(ptr->stk[ptr->top]))){postfix[j++]=pop(ptr);}push(ptr,infix[i]);}))));
    }
    while(!isempty(ptr))
    {
        postfix[j++]=pop(ptr);
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    s* ptr = (s*)malloc(sizeof(s));
    char infix[10];
    printf("Enter INFIX expression::");
    scanf("%[^\n]%*c", infix);
    ptr->size = 9;
    printf("POSTFIX expression is::%s",infixtopostfix(ptr, infix));
    return 0;
}