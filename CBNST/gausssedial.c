#include<stdio.h>
#include<math.h>
#define f1(x,y,z)  (17-y+2*z)/20
#define f2(x,y,z)  (-18-3*x+z)/20
#define f3(x,y,z)  (25-2*x+3*y)/20

int main() {
    float e;
    printf("Enter error tolerance::");
    scanf("%f",&e);
    float e1,e2,e3,x1,y1,z1,x0=0,y0=0,z0=0;
    int count=1;
    do {
        x1=f1(x0,y0,z0);
        y1=f2(x0,yo,z0);
        z1=f3(x0,y0,z0);
        e1=fabs((x0-x1));
        e2=fabs((y0-y1));
        e3=fabs((y0-y1));
        printf("%d ,%.3f %.3f %.3f\n",count,x1,y1,z1);
        count++;
        x0=x1;
        y0=y1;
        z0=z1;
    }while(e1>e && e2>e && e3 >e);
}