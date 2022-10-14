#include<stdio.h>
#include <math.h>
#define Epsilon 0.00001

double func(double x) {
    return (exp(-x)*(3,2*sin(x)-0.5*cos(x))) ;
}

int main()  {
    double a,b;
    printf("Enter a::");
    scanf("%lf",&a);
    printf("Enter b::");
    scanf("%lf",&b);
    if(func(a)*func(b)>=0) {
        printf("Wrong values of a and b");
        return 0;
    }
    double c=a;
    do {
        c=b+(a-b)/2;
        if(func(c) == 0.00) break;
        printf("[%f,%f] = %f\n",a,b,c);
        if(func(c)*func(a)<0) b=c;
        else a=c;
    }while( fabs(b-a)>=Epsilon );
    printf("The value of root is :%lf",c);
    return 0;
}