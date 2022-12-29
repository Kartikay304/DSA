// #include <stdio.h>
// #define f(x,y) x+y

// int main() {
//     float x0,y0,xn,n,h,yn,slope;
//     printf("Enter the values for x0 and y0::");
//     scanf("%f %f",&x0,&y0);
//     printf("Enter calculation point::");
//     scanf("%f",&xn);
//     printf("Enter the number of steps::");
//     scanf("%f",&n);
//     h=(xn-x0)/(float)n;
//     for(int i=0;i<n;i++) {
//         slope=f(x0,y0);
//         yn=y0+h*slope;
//         x0+=h;
//         y0=yn;
//     }
//     printf("The value of y at x= %f is %f",xn,yn);
// }

//euler advance
#include<stdio.h>
#include<math.h>
// #define f(x,y) x+y
double f(double x,double y) {
    return x*x+y*y;
}

int main() {
    double x0=1,y0=1.2,xn=1.05,h=0.05,yn,yn2,slope1,slope2,slope_avg;
    // printf("Enter the value of x0 and y0::");
    // scanf("%f %f",&x0,&y0);
    // printf("Enter the calculation point::");
    // scanf("%f",&xn);
    // printf("Enter the value oh h:");
    // scanf("%d",&h);
    // h=(xn-x0)/(float)n;
    while(fabs(xn-x0)>0.0000001) {
        slope1=h*f(x0,y0);
        yn=y0+slope1;
        slope2=h*f(x0+h,yn);
        slope_avg=(slope1+slope2)/(float)2;
        yn2=y0+slope_avg;
        x0=x0+h;
        y0=yn2;
    }
    printf("%lf",y0);

}