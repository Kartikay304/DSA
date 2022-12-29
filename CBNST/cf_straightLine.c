#include<stdio.h>

int main() {
    int n;
    float sumx=0,sumy=0,sumxy=0,sumx2=0,a,b;
    float x[n],y[n];
    printf("Enter number of observations::");
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%f",&x[i]);
    for(int i=0;i<n;i++) scanf("%f",&y[i]);
    for(int i=0;i<n;i++) {
        sumx+=x[i];
        sumy+=y[i];
        sumxy=x[i]*y[i];
        sumx2=x[i]*x[i];
    }
    a=(sumx2-sumx*sumxy)/(float)(n*sumx2-sumx*sumx);
    b=(n*sumxy-sumx*sumy)/(float)(n*sumx2-sumx*sumx);

}