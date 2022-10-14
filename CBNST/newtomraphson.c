#include<stdio.h>
#include<math.h>
#define f(x) cos(x)-4*x+2
#define g(x) -sin(x)-4

int main() {
    int n,count=0;
    float x1,x,e,f0,g0,fx1;
    printf("Enter the first assumption::");
    scanf("%f",&x1);
    printf("Enter the error tolerance::");
    scanf("%f",&e);
    do {
        g0 = g(x1);
		f0 = f(x1);
        x=x1-f0/g0;
        x1=x;
    }while(fabs(f(x1))>e);
    printf("%f",x1);
}
