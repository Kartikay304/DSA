 #include<stdio.h>

int main() {
    int n=5;
    // printf("Enter the number of terms::");
    // scanf("%d",&n);
    // int x[n],y[n][n];
    // printf("Enter the value of x and y::\n");
    // for(int i=0;i<n;i++) scanf("%f %f",&x[i],&y[i]);
    float x[] = { 1891, 1901, 1911,
                  1921, 1931 };
    float y[n][n];
    y[0][0] = 46;
    y[1][0] = 66;
    y[2][0] = 81;
    y[3][0] = 93;
    y[4][0] = 101;
    for(int j=1;j<n;j++) {
        for(int i=n-1;i>=j;i--) {
            y[i][j] = y[i][j-1]-y[i-1][j-1];
        }
    }
    for(int i=0;i<n;i++) {
        printf("%f",x[i]);
        for(int j=0;j<=i;j++) {
            printf("  %f ",y[i][j]);
        }
        printf("\n");
    }
    float X=1925,h,u,fact=1,Y;
    // printf("\nEnter the value of x for which you wants to find Y : "); 
    // scanf("%f",&X);
    h=x[1]-x[0];
    Y=y[n-1][0];
    u=(X-x[n-1])/(float)h;
    for(int i=1;i<n;i++) {   
        Y+=u*y[n-1][i]/(float)fact;
        u=u*(u+i);
        fact=fact*(i+1);
    }
    printf("\n Y(%f)=%f",X,Y); 
}