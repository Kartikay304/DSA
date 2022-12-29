#include <stdio.h>

float f(float x,float y){
    return (x-y)/(x+y) ;
}

int main() {
    float x0,y0,xn,h,yn,k1,k2,k3,k4,k;
    printf("Enter the value of x0,y0,xn and h::");
    scanf("%f %f %f %f",&x0,&y0,&xn,&h);
    while(x0<xn) {
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2.0,y0+k1/2.0);
        k3=h*f(x0+h/2.0,y0+k2/2.0);
        k4=h*f(x0+h,y0+k3);
        k=(k1+2*k2+2*k3+k4)/6;
        x0+=h;
        yn=y0+k;
        y0=yn;
    }
    printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);
}