#include<stdio.h>
struct p{
    int bt;
    int at;
    int tt;
    int ct;
    int done;
    int wt;
    int id;
}p[10],temp;

int main(){
    int ttt=0,twt=0,n,i,j;
    printf("enter the no .of process :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\n enter the at :");
        scanf("%d",&p[i].at);
        printf("\n enter the bt :");
        scanf("%d",&p[i].bt);
        p[i].id=i+1;
p[i].done=0;
    }

for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
        if(p[j].at<p[i].at){
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;

        }
    }
}

int np=n,time=0;
while(np>0){
    int min=-1,minbt=9999;
    for(i=0;i<n;i++){
        if(p[i].at<=time&&!p[i].done&&p[i].bt<minbt){
            min=i;
            minbt=p[i].bt;
        }   
     }

if(min!=-1){
    p[min].ct=time+p[min].bt;
    p[min].tt=p[min].ct-p[min].at;
    p[min].wt=p[min].tt-p[min].bt;
    ttt+=p[min].tt;
    twt+=p[min].wt;
    np--;
    time=p[min].ct;
    p[min].done=1;

}else{
    time++;
}
}
printf("\npno\t wt\t tt\n");
for(i=0;i<n;i++)
{
    printf("%d\t%d\t%d\n",p[i].id,p[i].wt,p[i].tt);
}
printf("\n avg tt : %d",ttt/n);
printf("\n avg wt : %d",twt/n);
}