/* Write a C program Create a  Dynamic array and then Reverse the array  using recursion and then finally print the array. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void enter_data(int arr[],int n) {
    printf("\nEnter elements::");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}

void swap(int arr[],int start,int end){
    int temp;
    temp = arr[start];  
    arr[start] = arr[end];
    arr[end] = temp;
}

void reverse(int arr[],int start,int end) {
    if (start > end)
    return;
    swap(arr,start,end);
    reverse(arr,start+1,end-1);
}

void print_data(int arr[],int n) {
    printf("\nElements in array::");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

int main() {
    printf("\nName: Kartikay kala, Section: H, Roll_No: 31, std_id: 20011090\n");
    int n,*arr=(int*)malloc(MAX*sizeof(int));
    printf("How many elements do you want to enter?::");
    scanf("%d",&n);
    enter_data(arr,n);
    reverse(arr,0,n-1);
    print_data(arr,n);
}