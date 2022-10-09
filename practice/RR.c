#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>

struct process_struct{
    int pid;
    int at;
    int bt;
    int ct,tat,wt,rt,st;
}p[100];

typedef struct queue {
    int qt[100];
    int front;
    int rear;
}Q;

void push(Q *q,int num) {
    q->qt[q->rear++]=num;
}

void pop(Q *q) {
    q->front++;
}

int front(Q *q) {
    return (q->qt[q->front]);
}

int comparatorAT(const void *a,const void *b) {
    int x=((struct process_struct*)a)->at;
    int y=((struct process_struct*)b)->at;
    if(x<y) return -1;
    else return 1;
}

int comparatorPID(const void *a,const void *b) {
    int x=((struct process_struct*)a)->pid;
    int y=((struct process_struct*)b)->pid;
    if(x<y) return -1;
    else return 1;
}

int main() {
    int n,tquant;
    Q *q=(Q*)malloc(sizeof(Q));
    printf("Enter the number of process::");
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        printf("Enter the Arrival time of process %d::",i+1);
        scanf("%d",&p[i].at);
        printf("Enter the Brust   time of process %d::",i+1);
        scanf("%d",&p[i].bt);
        p[i].pid=i;
    }
    printf("Enter time Quantum::");
    scanf("%d",&tquant);
    int bt[n],pCompleted=0,t=0,qFront=-1,selected=0;
    int flag=0;
    qsort((void*)p,n,sizeof(struct process_struct),comparatorAT);
    for(int i=0;i<n;i++) bt[i]=p[i].bt;
    q->front=0;
    q->rear=0;
    int k=0;

    while(pCompleted!=n) {
        first:
        for(k=selected;k<n && p[k].at<=t ;k++) {
            push(q,k);
            flag=1;
        }
        selected=k;
        if(qFront!=-1 && p[qFront].bt>0) {
            push(q,qFront);
            flag=1;
        }
        if(selected==n) flag=1;
        if(flag==0) {
            t++;
            goto first;
        }
        qFront=front(q);
        printf("%d ",qFront);
        pop(q);
        if(p[qFront].bt>tquant) {
            if(p[qFront].bt==bt[qFront]) p[qFront].st=t;
            t+=tquant;
            p[qFront].bt-=tquant;
        } else {
            if(p[qFront].bt==bt[qFront]) p[qFront].st=t;
            pCompleted++;
            t+=p[qFront].bt;
            p[qFront].ct=t;
            p[qFront].tat=p[qFront].ct-p[qFront].at;
            p[qFront].wt=p[qFront].tat-p[qFront].at;
            p[qFront].rt=p[qFront].st-p[qFront].at;
            p[qFront].bt=0;
        }
        flag=0;
    }

    for(int i=0;i<n;i++) p[i].bt=bt[i];
    qsort((void*)p,n,sizeof(struct process_struct),comparatorPID);
    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
    printf("\n\n\n");
    for(int i=0;i<q->rear;i++) printf("%d ,",q->qt[i]+1);
}