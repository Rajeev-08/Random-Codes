#include<stdio.h>
int queue[10],f=-1,r=-1;
int adj[20][20],n;
int stack[20],top=-1;

void enqueue(int data){
    r++;
    queue[r]=data;
    if(f==-1){
        f=0;
    }
}
int dequeue(){
    if(f==-1){
        return -1;
    }else{
        return queue[f++];
    }
}


void push(int data){
    stack[++top]=data;

}

int pop(){
    if(top!=-1)
    return stack[top--];
}

void bfs(int v){
    int visited[n];
    for(int i=1;i<=n;i++){
        visited[i]=0;
    }
    printf("\n bfs :");
    printf("%d ",v);
    visited[v]=1;
    enqueue(v);
    while(f<=r){
        v=dequeue();
        for(int j=1;j<=n;j++){
            if(adj[v][j]==1&&visited[j]!=1){
                printf("%d ",j);
                visited[j]=1;
                enqueue(j);

            }
        }
    }
}


void dfs(int v){
    int visited[n];
    for (int i=1;i<=n;i++){
        visited[i]=0;
    }
    push(v);
    while(top!=-1){
        
        v=pop();
        if(visited[v]!=1){
        printf("%d ",v);
        visited[v]=1;
        }
        for(int j=n;j>=1;j--){
            if(adj[v][j]==1&&visited[j]!=1){
                push(j);
            }
        }
        
    }

}

int main(){
    int v,choice;
    printf("enter the numner of vertices :");
    scanf("%d",&n);
    printf("\nenter the adjacency matrix :");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
printf("\nentered adj matrix :\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",adj[i][j]);           
        }
        printf("\n");
    }
    do{
        printf("\n1.BFS\n2.DFS\n3.EXIT");
        printf("\nenter a chpice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter the starting vertex :");
                scanf("%d",&v);
                bfs(v);
                break;
           case 2: 
           printf("enter the starting vertex :");
                scanf("%d",&v);
                dfs(v);
                break;        
        }

    }while(choice!=3);
}