#include<stdio.h>

int main() {
    int n=5;
    printf("Enter no of terms::");
    scanf("%d",&n);
    float x[n],y[n][n];
    for(int i=0;i<n;i++) { 
        printf("Enter the value of x and y for term %d::",i+1);
        scanf("%f %f",&x[i],&y[i]);
    }
    // x[0]=1;
    // x[1]=2;
    // x[2]=3;
    // x[3]=4;
    // x[4]=5;
    // y[0][0]=1;
    // y[1][0]=2;
    // y[2][0]=3;
    // y[3][0]=4;
    // y[4][0]=5;
    //calculating difference table
    for(int j=1;j<n;j++) {
        for(int i=0;i<n-j;i++) y[i][j] = y[i+1][j-1]-y[i][j-1];
    }
    //printing difference table
    for(int i=0;i<n;i++) {
        printf("%f ",x[i]);
        for(int j=0;j<n-i;j++) printf("%f ",y[i][j]);
        printf("\n");
    }
    float X,y1,y2,y3,y4;
    printf("Enter the value of X for which you want value of Y::");
    scanf("%f",&X);
    int i=0;
    do {
        i++;
    }while(x[i]<X);
    i--;
    float u=(X-x[i])/(x[1]-x[0]);
    y1=u*y[i][1];
    y2=u*(u-1)*y[i-1][2]/(float)2;
    y3=u*(u-1)*u*(u+1)*y[i-1][3]/(float)6;
    float Y=y[i][0]+y1+y2+y3;
    printf("%f",Y);

}