#include<stdio.h>
#include<stdlib.h>
int main(){
    int max[20][20],alloc[20][20],need[20][20],avail[10],safe[10],ind=0,finish[10];
    int i,j,k,a,np,nr;

    printf("\n enter the no.of process and res :");
    scanf("%d%d",&np,&nr);

printf("\n enter max : \n");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            scanf("%d",&max[i][j]);
        }
    }
printf("\n enter alloc : \n");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
printf("\n need \n");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            need[i][j]=max[i][j]-alloc[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }

printf("\n enter avail : \n");
for(i=0;i<nr;i++){
    scanf("%d",&avail[i]);
}

for(i=0;i<np;i++) finish[i]=0;

for(k=0;k<np;k++){
    for(i=0;i<np;i++){
        if(finish[i]==0){
            int flag=0;
            for(j=0;j<nr;j++){
                if(need[i][j]>avail[j]){
                    flag=1;
                    break;
                }
            }

            if(flag==0){
                safe[ind++]=i;
                for(a=0;a<nr;a++){
                    avail[a]+=alloc[i][a];
                }
                finish[i]=1;
            }
        }
    }
}
 
 int f=0;
 for(i=0;i<np;i++){
    if(finish[i]==0){
        f=1;
        break;
    }
 }
 if(f==1){
    printf("\nthe system is unsafe");
 }else{
    printf("\nthe system is in safe state\nsafe seq : ");
    for(i=0;i<ind;i++){
        printf("P%d ",safe[i]);
    }
 }
    
}