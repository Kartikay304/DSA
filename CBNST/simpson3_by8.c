#include<stdio.h>

int main() {
    float u,l,h,k,integration;
    int intr;
    printf("Enter upper and lower limit::");
    scanf("%f %f",&u,&l);
    printf("Enter the interval");
    scanf("%d",&intr);
    h=(u-l)/(float)intr;
    integration = f(u) + f(l);
    for(int i=1;i<=intr-1;i++) {
        k = l +i*h;
        if(i%3==0) {
            integration+=2*f(k);
        }
        else integration+=3*f(k);
    }
    integration = integration*3*h/(float)8;
}