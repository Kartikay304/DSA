#include<stdio.h>

int sum(int a[],int start,int end);

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",sum(a,0,n-1));
}

int sum(int a[],int start,int end)
{
    if(end>=start)    
    return (a[start] + sum(a,start+1,end));
    return 0;
}