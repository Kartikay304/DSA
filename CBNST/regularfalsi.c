#include <stdio.h>
#include <math.h>
#define Epsilon 0.0001
#define f(x) x*x*x-2*x-5

int main() {
    double a,b;
    top:
    printf("Enter a::");
    scanf("%lf",&a);
    printf("Enter b::");
    scanf("%lf",&b);
    if(f(a)*f(b)>0) {
        printf("\nINVALID ASSUMPTIONS ENTER THE VALUES AGAIN\n");
        goto top;
    }
    double c=1,prevC=3,x,y;
    do {
        prevC=c;
        x=f(a);
        y=f(b);
        c=(a*y-b*x)/(y-x);
        printf("[%f,%f | %f] | [%f,%f | %f]\n",a,b,c,x,y,f(c));
        if(f(c)*x<0) b=c;
        else if(f(c)*y<0) a=c;
    }while(fabs(prevC-c)>=Epsilon);
    printf("The root of the equation is::%lf",c);

    return 0;
}