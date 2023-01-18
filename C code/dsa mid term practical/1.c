/* Write a the C program to create an array by inserting  N elements in it then find second non repeating element from the array. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void enter_data(int arr[], int n) {
    printf("Enter elements::");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}

void find_second(int arr[], int n) {
    int i=0,j=0,count=0;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(arr[i]==arr[j] && i!=j)break;
        }
        if(j==n){
            count++;
        }
        if(count==2){
            printf("second non-repeating character is::%d",arr[i]);
            printf("\n");
            return ;
        }
    }
}

int main() {
    int *arr=(int*)malloc(MAX*sizeof(int));
    int n;
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    printf("How many elements do you want to enter?::");
    scanf("%d",&n);
    enter_data(arr,n);
    find_second(arr,n);
}