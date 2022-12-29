#include<stdio.h>
#include<math.h>
#define f(x) 1/(1+pow(x,2))
int main() {
    float u,l,integration,h;
    int n;
    printf("Enter the upper and lower intervals::"); 
    scanf("%f %f",&u,&l);
    printf("Enter the no of intervals::");
    scanf("%d",&n);
    h=(u-l)/(float)n;
    integration=f(u)+f(l);
    for(int i=1;i<=n-1;i++) {
        integration += 2*f(l+i*h);
    }
    integration*=h/(float)2;
    printf("\nRequired value of integration is: %.3f", integration);
}