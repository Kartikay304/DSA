#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

struct process_struct {
    int pid;
    int at;
    int bt;
    int ct,tat,st,rt,wt;
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

int main () {
    int n;
    printf("Enter the number of process::");
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        printf("Enter Arrival time of process %d::",i+1);
        scanf("%d",&p[i].at);
        printf("Enter Brust time of process %d  ::",i+1);
        scanf("%d",&p[i].bt);
        p[i].pid=i;
    }
    int bt[n],t=0,min[4]={0,0,0,INT_MAX};//min[4]={index-no,process_id,arrival_time,brust_time}
    bool check=false;
    qsort((void*)p,n,sizeof(struct process_struct),comparatorAT);
    for(int i=0;i<n;i++) bt[i]=p[i].bt;
    for(int i=0;i<n;i++) {
        first:
        for(int j=0;j<n;j++) {
            if(p[j].at<=t && p[j].bt>0) {
                if(p[j].bt<min[3]) {
                    min[0]=j;
                    min[1]=p[j].pid;
                    min[2]=p[j].at;
                    min[3]=p[j].bt;
                } else if(p[j].bt==min[3]) {
                    if(p[j].at==min[2]) min[0]=(p[j].pid<min[1])?j:min[0];
                    else min[0]=(p[j].at<min[2])?j:min[0];
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
        min[3]=INT_MAX;                                //IMPORTANT
        t+=p[min[0]].bt;
        p[min[0]].ct=t;
        p[min[0]].tat=p[min[0]].ct-p[min[0]].at;
        p[min[0]].wt=p[min[0]].tat=bt[min[0]];
        p[min[0]].rt=p[min[0]].st-p[min[0]].at;
        p[min[0]].bt=0;
        check=false;
    }
    // for(int i=0;i<n;i++) p[i].bt=bt[i];
    qsort((void*)p,n,sizeof(struct process_struct),comparatorPID);
    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
}