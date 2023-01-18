#include <stdio.h>

/*
  approach:
           i) make end element as pivot.
          ii) Now count the no of element smaller then pivot.
         iii) now switch (smaller + 1)th position  with pivot position.
          iv) now by one element at a time from starting position to pivot-1 and compare first element with pivot is smaller do nothing and if larger then switch with end element
           v) now do i++ and j-- to compare first element and last elements respectively
*/

int partition(int a[],int s,int e)   
{
    int p,temp=0,i,j,count=0;
    for(i=s;i<=e;i++)
    {
        if(a[i]<a[e])                 
        {
            count++;
        }
    }
    p=s+count;
    temp=a[p];      
    a[p]=a[e];
    a[e]=temp;

    for(i=s;i<=p-1;i++)
    {
       if(a[i]>=a[p])
       {
           for(j=e;j>=p+1;j--)
           {
               if(a[i]>=a[j])
               {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
               }
           }
       }
    }
    return p;
}

void quicksort(int a[],int s,int e)
{
    if(s>=e)                      //length is equal to zero or only one element is left
    {
        return;
    }

    int p=partition(a,s,e);
    
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}

//driver code
int main()
{
    int n,i; 
    printf("Enter no of elements::");   //n is no of elements in array
    scanf("%d",&n);
    int a[n];
    printf("Enter elements::");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int s=0,e=n-1;                 //s is index of staring element of array and e is index of ending element of array
    
    quicksort(a,s,e);
    
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}