#include<stdlib.h>
#include<stdio.h>
struct fcfs{
    int bt,at,tt,wt,pid;
}p[10],temp;
int main(){
    int n,j,i,twt=0,ttt=0;
    printf("enter the o of p;");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i].pid=i;
        printf("\n enter at of P%d",i);
        scanf("%d",&p[i].at);
        printf("\n enter bt of P%d",i);
        scanf("%d",&p[i].bt);
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].at>p[j].at){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
for(i=n-1;i>-1;i--){
    for(j=i-1;j>-1;j--){
        p[i].wt+=p[j].bt;
    }
    p[i].wt-=p[i].at;
    twt+=p[i].wt;
}
for(i=0;i<n;i++){
    p[i].tt=p[i].wt+p[i].bt;
    ttt+=p[i].tt;
}

printf("\n pno\tat\tbt\twt\ttt\n");
for(i=0;i<n;i++){
    printf("P%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tt);
}
printf("\navg wt %d",twt/n);
printf("\navg tt %d",ttt/n);
}