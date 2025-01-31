#include<stdio.h>
int n,choice,r=-1,f=-1,choice,value,priority,i;
struct Priority{
    int value;
    int prio;
};
struct Priority q[100],item;

void enq(int value ,int priority){
    if(r==n-1){
        printf("overflow");
    }else{
item.value=value;
item.prio=priority;
if(f==-1&&r==-1){
    f=r=0;
    q[f]=item;
}else{
        i=r;
        while(i>=f&&q[i].prio>item.prio){
            q[i+1]=q[i];
            i--;
        }
        q[i+1]=item;
        r++;
    }
}
}

void deq(){
    if(r==-1){
        printf("underflow");

    }
    value=q[0].value;
    priority=q[0].prio;
    printf("item with value %d and priority %d deleted ",value,priority);
    if(f==0&&r==0){
        f=r=-1;
    }else{
    
    f++;
    }

}

void dis(){
    if(r==-1){
        printf("underflow");
    }else{
        for(i=f;i<=r;i++){
            printf("\n value : %d prio : %d",q[i].value,q[i].prio);
        }
    }
}







int main(){
    printf("enter the size :");
    scanf("%d",&n);
    do{
        printf("\n1.enq\n2.deq\n3.dis\n4.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("emter the value ,priority :");
            scanf("%d %d",&value,&priority);
            enq(value ,priority);
            break;
            case 2:
           deq();
           break;
           case 3: dis();
           break;
        }
    

}while(choice !=4);
}
