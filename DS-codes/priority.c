#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,n,bt[10],p[10],compt[10],wt[10],tat[10],temp1,temp2;
    float sumwt=0.0,sumat=0.0;
    printf("enter the NO.of process :");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("\n Enter the bt:");
    scanf("%d",&bt[i]);
    printf("\n enter the priority :");
    scanf("%d",&p[i]);
}
for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
        if(p[i]>p[j]){
            temp1=bt[i];
            bt[i]=bt[j];
            bt[j]=temp1;
            temp2=p[i];
            p[i]=p[j];
            p[j]=temp2;
        }
    }
}
compt[0]=bt[0];
wt[0]=0;
for(i=1;i<n;i++)
compt[i]=bt[i]+compt[i-1];
for(i=0;i<n;i++){
    tat[i]=compt[i];
    wt[i]=tat[i]-bt[i];
    sumat+=tat[i];
    sumwt+=wt[i];
}
printf("\n total wt : %f",sumwt);
printf("\n AVG wt : %f",sumwt/n);
printf("\n total tat : %f",sumat);
printf("\n avg tat : %f",sumat/n);
}