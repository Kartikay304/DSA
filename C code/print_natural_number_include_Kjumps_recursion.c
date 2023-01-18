#include<stdio.h>

void printNatural(int x,int y,int k);

int main()
{
    int x,y,k;
    scanf("%d %d %d",&x,&y,&k);
    printNatural(x,y-k,k);
}

void printNatural(int x,int y,int k)
{
    if(y>x)
        printNatural(x,y-k,k);
    else
        return;
    printf("%d ",y);
}