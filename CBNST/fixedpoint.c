#include<stdio.h>
#include<math.h>

#define f(x) cos(x)-3*x+1
#define g(x) (1+cos(x))/3

int main() {
    int n,step=0;
    float x0,x,e;
    printf("Enter the assumption::");
    scanf("%f",&x0);
    printf("Enter max no of steps::");
    scanf("%d",&n);
    printf("Enter error tolence::");
    scanf("%f",&e);
    do {
        x=g(x0);
        step++;
        printf("Itertion %d, %f and f(%f) is %f\n",step,x,x,f(x));
        if(step>=n)printf("Not convergent");
        x0=x;
    }while(fabs(f(x))>e);
    printf("Root is:: %f",x);
}