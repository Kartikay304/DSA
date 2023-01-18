/* Write a the C program to create an array by inserting  N elements in it then find third repeating element from the array. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void enter_data(int arr[],int n) {
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}

void second_find(int arr[],int n) {
    int i,j,count=0,temp=arr[-1];
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(arr[i]==arr[j] && i!=j && temp!=arr[i]) {
                count++;
                temp=arr[i];
                break;
            }
        }
        if(count==3) {
            printf("Second repeating element::%d",arr[i]);
            printf("\n");
            return;
        }
    }
    printf("No third repeating is present");
}

int main() {
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    int *arr=(int*)malloc(MAX*sizeof(int));
    int n;
    printf("How many elements do you want to enter?::");
    scanf("%d",&n);
    enter_data(arr,n);
    second_find(arr,n);
}