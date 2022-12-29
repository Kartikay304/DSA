#include<stdio.h>

int main() {
    int n=5;
    // printf("Enter number of terms::");
    // scanf("%d",&n);
    float x[n],y[n][n];
    x[0]=1;
    x[1]=2;
    x[2]=3;
    x[3]=4;
    x[4]=5;
    y[0][0]=1;
    y[1][0]=2;
    y[2][0]=3;
    y[3][0]=4;
    y[4][0]=5;

    for(int j=1;j<n;j++) {
        for(int i=0;i<n-j;i++) {
            y[i][j] = y[i+1][j-1]-y[i][j-1];
        }
    }
    printf("::::Difference Table::::\n");
    for(int i=0;i<n;i++) {
        printf("%f ",x[i]);
        for(int j=0;j<n-i;j++) {
            printf("%f ",y[i][j]);
        }
        printf("\n");
    }
    float X,h,u,fact=1,Y;
    printf("\nEnter the value of x for which you wants to find Y : "); 
    scanf("%f",&X);
    h=x[1]-x[0];
    u=(X-x[0])/(float)h;
    Y=y[0][0];  
    for(int i=1;i<n;i++) {
        Y+=(u*y[0][i])/(float)fact;
        fact=fact*(i+1);
        u=u*(u-i);
    }
    printf("\n Y(%f)=%.3f",X,Y); 
}