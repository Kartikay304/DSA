#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct process_struct {
    int pid;
    int at;
    int bt;
    int ct,tat,wt,st,rt;
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
    printf("Enter number of process::");
    scanf("%d",&n);
    int bt[n];
    for(int i=0;i<n;i++) {
        printf("Enter the Arrival time of process %d::",i+1);
        scanf("%d",&p[i].at);
        printf("Enter the Brust time of process %d  ::",i+1);
        scanf("%d",&p[i].bt);
        p[i].pid=i;
    }
    qsort((void*)p,n,sizeof(struct process_struct),comparatorAT);
    for(int i=0;i<n;i++) bt[i]=p[i].bt;
    int t=0,selected[3]={0,0,INT_MAX};
    bool check=false;
    int ideal_time=0;
    for(int k=0;k<n;k++) {
        first:
        for(int i=0;i<n;i++) {
            if(p[i].bt>0 && p[i].at<=t) {
                if(p[i].at<selected[2]){
                    selected[0]=i;
                    selected[1]=p[i].pid;
                    selected[2]=p[i].at;
                } else if(p[i].at==selected[2]) selected[0]=(p[i].pid<selected[1])?i:selected[0];
                selected[1]=p[selected[0]].pid;
                selected[2]=p[selected[0]].at;
                check=true;
            }
        }
        if(check==false) {
            t++;
            ideal_time++;
            goto first;
        }
        selected[2]=INT_MAX;
        p[selected[0]].st=t;
        t+=p[selected[0]].bt;
        p[selected[0]].ct=t;
        p[selected[0]].tat=p[selected[0]].ct-p[selected[0]].at;
        p[selected[0]].wt=p[selected[0]].tat-bt[selected[0]];
        if(p[selected[0]].wt<0) p[selected[0]].wt=0;
        p[selected[0]].rt=p[selected[0]].st-p[selected[0]].at;
        p[selected[0]].bt=0;
        check=false;
    }
    float total_wt=0,total_tat=0,total_rt=0;
    float schedule_length=t-p[0].at;
    float throughput=n/(float)schedule_length;
    float cpu_util = ((t-ideal_time)/(float)t)*100;
    for(int i=0;i<n;i++) p[i].bt=bt[i];
    qsort((void*)p,n,sizeof(struct process_struct),comparatorPID);
    printf("\nPID\tAT\tBT\tST\tCT\tWT\tTAT\tRT\n");
    for(int i=0;i<n;i++){ 
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].wt,p[i].tat,p[i].rt);
        total_wt+=p[i].wt;
        total_tat+=p[i].tat;
    }
    printf("\nAverage TAT ::%f\nAverage WT ::%f\nSchedule Length ::%f\nThroughput ::%f\nCPU Utilization ::%f\n",total_tat/(float)n,total_wt/(float)n,schedule_length,throughput,cpu_util);
    return 0;
}