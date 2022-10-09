#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct process_struct {
    int pid;
    int at;
    int bt;
    int pt;
    int ct,tat,wt,rt,st;
}p[100];

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
    int n;
    printf("Enter the number of process::");
    scanf("%d",&n);
    int bt[n];
    for(int i=0;i<n;i++) {
        printf("Enter the Arrival time of process %d ::",i+1);
        scanf("%d",&p[i].at);
        printf("Enter the Brust time of process %d   ::",i+1);
        scanf("%d",&p[i].bt);
        printf("Enter the priority of process %d     ::",i+1);
        scanf("%d",&p[i].pt);
        p[i].pid=i;
    }
    qsort((void*)p,n,sizeof(struct process_struct),comparatorAT);
    for(int i=0;i<n;i++) bt[i]=p[i].bt;
    int pCompleted=0,t=0,max[4]={0,0,0,INT_MIN};
    bool check=true;
    while(pCompleted!=n) {
        first:
        for(int i=0;i<n;i++) {
            if(p[i].bt>0 && p[i].at<=t) {
                if(p[i].pt>max[3]) {
                    max[0]=i;
                    max[1]=p[i].pid;
                    max[2]=p[i].at;
                    max[3]=p[i].pt;
                } else if(p[i].pt==max[3]) {
                    if(p[i].at==max[2]) max[0]=(max[1]<p[i].pid)?max[0]:i;
                    else max[0]=(p[i].at<max[2])?i:max[0];
                    max[1]=p[max[0]].pid;
                    max[2]=p[max[0]].at;
                    max[3]=p[max[0]].pt;
                }
                check = true;
            }
        }
        if(check==false) {
            t++;
            goto first;
        }
        printf("%d",max[1]+1);
        if(p[max[0]].bt==bt[max[0]]) p[max[0]].st=t;
        p[max[0]].bt--;
        t++;
        if(p[max[0]].bt==0) max[3]=INT_MIN;
        if(p[max[0]].bt==0) {
            pCompleted++;
            p[max[0]].ct=t;
            p[max[0]].tat=p[max[0]].ct-p[max[0]].at;
            p[max[0]].wt=p[max[0]].tat-p[max[0]].bt;
            if(p[max[0]].wt<0) p[max[0]].wt=0;
            p[max[0]].rt=p[max[0]].st-p[max[0]].at;
            check=false;
        }
    }
    for(int i=0;i<n;i++) p[i].bt=bt[i];
    qsort((void*)p,n,sizeof(struct process_struct),comparatorPID);

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
}
