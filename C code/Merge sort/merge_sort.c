#include <stdio.h>

void mergearray(int x[],int y[],int a[],int s,int e)
{
    int mid=s+(e-s)/2;
    int i=s,j=mid+1,k=s;
    while(i<=mid && j<=e)
    {
        if(x[i]<y[j])
        {
            a[k]=x[i];
            i++;
            k++;
        }
        else{
            a[k]=y[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        a[k]=x[i];
        k++;
        i++;
    }
    while(j<=e)
    {
        a[k]=y[j];
        k++;
        j++;
    }
}

void mergesort(int a[],int s,int e)
{
    if(s>=e){
        return;
    }

    int x[100],y[100],mid=0;
    mid=s+(e-s)/2;
    for(int i=s;i<=mid;i++)
    {
        x[i]=a[i];
    }
    for(int i=mid+1;i<=e;i++)
    {
        y[i]=a[i];
    }
    mergesort(x,s,mid);
    mergesort(y,mid+1,e);
    mergearray(x,y,a,s,e);
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int s=0,e=n-1;
    mergesort(a,s,e);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}