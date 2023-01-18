#include<stdio.h>

void printNatural(int n);

int main()
{
    int n;
    scanf("%d",&n);
    printNatural(n);
}

void printNatural(int n)
{
    if(n)
        printNatural(n-1);
    else
        return;
    printf("%d ",n);
}