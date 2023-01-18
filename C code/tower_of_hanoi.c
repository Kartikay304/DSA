#include<stdio.h>

void towerofhanoi(int n,char a,char b,char c)
{
    if(n>0)
    {
        towerofhanoi(n-1,a,c,b);
        printf("Move disk %d from %c to %c\n",n,a,c);
        towerofhanoi(n-1,b,a,c);
    }
}

int main()
{
    int n=3;
    char A='A',B='B',C='C';
    towerofhanoi(n,A,B,C);
}