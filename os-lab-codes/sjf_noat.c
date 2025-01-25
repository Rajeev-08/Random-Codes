#include<stdio.h>
#include<stdlib.h>
struct sjf{
    int pid;
    int bt,tt,wt;
}p[10],temp;
int main(){
    int ttt=0,twt=0,i,j,n;
    printf("\n enter the no.of process :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i].pid=i;
        printf("\n enter bt of P%d : ",i);
        scanf("%d",&p[i].bt);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[j].bt<p[i].bt){
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
        twt+=p[i].wt;
    }

    for(i=0;i<n;i++){
        p[i].tt=p[i].wt+p[i].bt;
        ttt+=p[i].tt;
    }
    printf("\n pno\tbt\twt\ttt\n");
for(i=0;i<n;i++){
    printf("P%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
}
printf("\navg wt %d",twt/n);
printf("\navg tt %d",ttt/n);

}