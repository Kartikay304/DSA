#include<stdio.h>

int main() {
    int n=5;
    // printf("Enter the number of terms::");
    // scanf("%d",&n);
    float x[n],y[n],p,iP,viP;
    // for(int i=0;i<n;i++) {
    //     printf("Enter the calue of x & y for %d::",i+1);
    //     scanf("%f %f",&x[i],&y[i]);
    x[0] = 5;
    y[0] = 150;
    x[1] = 7;
    y[1] = 392;
    x[2] = 11;
    y[2] = 1452;
    x[3] = 13;
    y[3] = 2366;
    x[4] = 17;
    y[4] = 5202;
    printf("Enter the value of interpolation point::");
    scanf("%f",&iP);
    for(int i=0;i<n;i++) {
        p=1;
        for(int j=0;j<n;j++) {
            if(i!=j) p*=(iP-x[j])/(x[i]-x[j]);
        }
        viP+=p*y[i];
    }
    printf("Interpolated value at %.3f is %.3f.", iP, viP);
}