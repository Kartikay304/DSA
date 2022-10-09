#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<stdlib.h>

struct process_struct {
    int pid;
    int at;
    int bt;
    int ct,tat,wt,rt,st;
}p[00];

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
        p[i].pid=i;
    }

    qsort((void*)p,n,sizeof(struct process_struct),comparatorAT);
    for(int i=0;i<n;i++) bt[i]=p[i].bt;
    int pCompleted=0,t=0,min[4]={0,0,0,INT_MAX};
    bool check=false;

    while(pCompleted!=n) {
        first:
        for(int i=0;i<n;i++) {
            if(p[i].at<=t && p[i].bt>0) {
                if(p[i].bt<min[3]) {
                    min[0]=i;
                    min[1]=p[i].pid;
                    min[2]=p[i].at;
                    min[3]=p[i].bt;
                }else if(p[i].bt==min[3]) {
                    if(p[i].at==min[2]) min[0]=(p[i].pid<min[1])?i:min[0];
                    else min[0]=(p[i].at<min[2])?i:min[0];
                    min[1]=p[min[0]].pid;
                    min[2]=p[min[0]].at;
                    min[3]=p[min[0]].bt;
                }
                check=true;
            }
        }
        if(check==false) {
            t++;
            goto first;
        }
        printf("%d ",min[0]+1);
        if(p[min[0]].bt==bt[min[0]]) p[min[0]].st=t;
        p[min[0]].bt--;
        t++;
        min[3]=(p[min[0]].bt==0)?INT_MAX:min[3]-1;
        if(p[min[0]].bt==0) {
            pCompleted++;
            p[min[0]].ct=t;
            p[min[0]].tat=p[min[0]].ct-p[min[0]].at;
            p[min[0]].wt=p[min[0]].tat-bt[min[0]];
            p[min[0]].rt=p[min[0]].st-p[min[0]].at;
        }
        check=false;
    }
    for(int i=0;i<n;i++) p[i].bt=bt[i];

    qsort((void*)p,n,sizeof(struct process_struct),comparatorPID);
    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
}