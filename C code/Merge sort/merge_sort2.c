#include <stdio.h>

void mergearray(int a[],int s,int e)
{
    int mid=s+(e-s)/2;
    int i=s,j=mid+1,k=s,temp[100];
    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=e)
    {
        temp[k++]=a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    }
}

void mergesort(int a[],int s,int e)
{
  if(s>=e)
  {
      return;
  }
  int mid=s+(e-s)/2;
  mergesort(a,s,mid);
  mergesort(a,mid+1,e);
  mergearray(a,s,e);
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
}