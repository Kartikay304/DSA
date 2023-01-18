#include <stdio.h>
# define MAX 100

typedef struct stack
{
    int a[MAX];
    int top;
}s;
s *ptr, pos;

int push()
{
    int num;
    if(ptr->top==MAX-1)
        return 0;
    else
    {
        scanf("%d",&num);
        ptr->a[++ptr->top]=num;
    }
    return 0;
}

int pop()
{
    if(ptr->top==-1)
    {
        return 0;
    }
    else
    ptr->top--;
    return 0;
}

void display()
{
    int i;
    for(i=ptr->top;i>=0;i--)
    {
        printf("%d ",ptr->a[i]);
    }
    printf("\n");
}

int main()
{
    ptr = &pos;
    int n;
    ptr->top = -1;
    printf("MENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    while(1)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: return 0;
        }
    }
    return 0;
}