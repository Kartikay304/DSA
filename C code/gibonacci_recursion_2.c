#include <stdio.h>

void getfibo(int n,int n1,int n2)
{
    int n3=n1+n2;;
    if(n>=n3)
    {
        n1=n2;
        n2=n3;
        printf("%d ",n3);
        getfibo(n,n1,n2);
    }
}

int main()
{
    int n,n1=0,n2=1;
    scanf("%d",&n);
    printf("%d %d ",n1,n2);
    getfibo(n,n1,n2);
}