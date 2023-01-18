#include<iostream>
#include<stdlib.h>
#define MAX 1000000
using namespace std;

typedef struct STACK {
	int stk[MAX];
	int top;
}s;

typedef struct QUEUE {
	int que[MAX];
	int front;
	int rear;
}q;

void push(s *ptr,int n) {
   ptr->stk[++ptr->top]=n;
}

void display(s *ptr) {
   for(int i=0;ptr->stk[i]!=-1;i++) cout<<ptr->stk[i]<<" ";
}

void enqueue(q *qtr,int num) {
	qtr->que[++qtr->rear]=num;
}

void game(int arr[],s *ptr,q *qtr1,q *qtr2) {
	for(int i=qtr1->front;qtr1->rear>=qtr1->front || qtr2->rear>=qtr2->front;i++) {
		if(qtr1->que[qtr1->front]>qtr2->que[qtr2->rear]) {
			push(ptr,1);
			qtr2->rear--;
		}
		else if(qtr1->que[qtr1->front]<qtr2->que[qtr2->rear]) {
			push(ptr,2);
			qtr1->front++;
		}
		else {
			push(ptr,0);
			qtr2->rear--;
            qtr1->front++;
		}
	}
	ptr->stk[++ptr->top]=-1;
	display(ptr);
}

int main() {
	s *ptr=(s*)malloc(sizeof(s));
	q *qtr1=(q*)malloc(sizeof(q));
	q *qtr2=(q*)malloc(sizeof(q));
	ptr->top=-1;
	qtr1->front=0;
	qtr1->rear=-1;
	qtr2->front=0;
	qtr2->rear=-1;
	int n,num;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>num;
		enqueue(qtr1,num);
		enqueue(qtr2,num);
	}
	game(arr,ptr,qtr1,qtr2);
}