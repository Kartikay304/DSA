#include <stdio.h>

int getfact(int n)
{
    int factorial;
    n--;
    if(n==0)
    {
        factorial = 1;
        return factorial;
    }
    else
    {
       factorial = n * getfact(n);
       return factorial;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    n++;
    printf("%d",getfact(n));
}