#include <stdio.h>

int getsumfibo(int n,int n1,int n2)
{
    int n3=n1+n2,sum=0;
    if(n<0)
    {
        sum = -1;
    }
    if(n>0)
    {
        n--;
        n1=n2;
        n2=n3;
        sum+=n2 + getsumfibo(n,n1,n2); 
    }
    return sum;
}

int main()
{
    int n,n1=0,n2=1;
    scanf("%d",&n);
    // printf("%d %d ",n1,n2);
    n=n-2;
    printf("%d",(getsumfibo(n,n1,n2)+1));
}