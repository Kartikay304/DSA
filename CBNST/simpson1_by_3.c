#include<stdio.h>
#define f(x) x*x

int main() {
    float u,l,h,integration,k;
    int intr;
    printf("Enter upper and lower bound::");
    scanf("%f %f",&u,&l);
    printf("Enter no of intervals::");
    scanf("%d",&intr);
    h=(u-l)/intr;
    integration = f(u) +f(l);
    for(int i=1;i<=intr-1;i++) {
        k=l+i*h;
        if(i%2==0) integration+=2*f(k);
        else integration+=4*f(k);
    }
    integration=integration*h/3;
}