#include<stdio.h>

void getfibo(int n,int n1,int n2)
{
    int n3;
    if(n>0){
    n3=n1+n2;
    printf("%d ",n3);
    n1=n2;
    n2=n3;
    n--;
    getfibo(n,n1,n2);
    }
}

int main()
{
    int n,n1=0,n2=1;
    scanf("%d",&n);
    printf("0 1 ");
    getfibo(n-2,n1,n2);
    return 0;
}