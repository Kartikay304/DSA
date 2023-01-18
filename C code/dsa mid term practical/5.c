/* Write a C Program to Convert Infix to Postfix Expression using Stack. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

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

int isoperand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))?1:0;
}

int precedence(char ch)
{
    return ((ch=='+'||ch=='-')?1:((ch=='*' || ch=='/')?2:0));
}

char *infixtopostfix(s *ptr,char infix[]) {
    ptr->top=-1;
    int i=0,j=0;
    char temp;
    ptr->stk=(char*)malloc(ptr->size*sizeof(char));
    char *postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    for(i=0;i<infix[i]!='\0';i++) {
        if(isoperand(infix[i])) postfix[j++]=infix[i];
        else {
            if(infix[i]=='(') push(ptr,infix[i]);
            else if(infix[i]==')') while(temp=pop(ptr)!='(') postfix[j++]=temp;
            else {
                while(!isempty(ptr)&&precedence(infix[i])<=precedence(ptr->stk[ptr->top])) {
                    postfix[j++]=pop(ptr);
                }
                push(ptr,infix[i]);
            }
        }
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
    char *infix=(char*)malloc(MAX*sizeof(char));
    printf("Enter INFIX expression::");
    scanf("%[^\n]%*c", infix);
    ptr->size = strlen(infix);
    printf("POSTFIX expression is::%s",infixtopostfix(ptr, infix));
    return 0;
}