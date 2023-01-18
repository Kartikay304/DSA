#include <stdio.h>

int binarysearch(int a[],int n,int key)
{
  int *s=&a[0],*e=&a[n-1],*mid;
  while(*e>=*s)
  {
    mid=&a[*s+(*e-*s)/2];
    if(key==a[*mid])
    {
      return *mid;
    }
    else if(key<a[*mid])
    {
      *e=*mid-1;
    }
    else{
      *s=*mid+1;
    }
  }
  return -1;
}

int main()
{
  int n,i,key;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter key:");
  scanf("%d",&key);
  int pos=binarysearch(a,n,key);
  if(pos==-1)
  {
    printf("Key not found");
  }
  else
  {
    printf("Key found at position no %d::",pos);
  }
}