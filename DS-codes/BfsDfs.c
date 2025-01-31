#include<stdio.h>
#include<stdlib.h>
int queue[5],f=-1,r=-1;
int Adj[20][20];
int stack[5],top=-1;
void enqueue(int data)
{
    r++;
    queue[r]=data;
    if(f==-1)
        f=0;
}

int dequeue()
{
    if(f==-1)
        return -1;
    else
        return queue[f++];
}

void push(int data)
{
    stack[++top]=data;
}

int pop()
{
    if(top!=-1)
        return stack[top--];
}

void breadthfs(int v, int n) {
    int visited[n];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    printf("BFS traversal: %d ", v);
    visited[v] = 1;
    enqueue(v);

    while (f <= r) { // Adjusted condition
        v = dequeue();
        for (int j = 1; j <= n; j++) {
            if (Adj[v][j] == 1 && visited[j] != 1) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}


void depthfs(int v,int n)
{
    int visited[n];
    for(int i=1;i<=n;i++)
        visited[i]=0;
    push(v);
    while(top!=-1)
    {
        v=pop();
        if(visited[v]!=1)
            printf("%d ",v);
        visited[v]=1;
        for(int j=n;j>=1;j--)
        {
            if((Adj[v][j]==1)&&(visited[j]!=1))
            {
                push(j);
            }
        }
    }
    return;
}


int main()
{
    int n,i,j,ch,vertex;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");

    for ( i = 1; i <=n; i++)
    {
        for( j = 1; j <=n; j++)
        {
            scanf("%d",&Adj[i][j]);
        }
    }
    
    printf("Entered adjacency matrix of graph:\n");
    for ( i = 1; i <= n; i++)
    {
        for( j = 1; j <= n; j++)
        {
            printf("%d  ",Adj[i][j]);
        }
        printf("\n");
    }
    
    printf("Menu options for traversal:\n1.BFS\n2.DFS\n3.Exit\n");
    while(1)
    {
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the initial vertex:");
                    scanf("%d",&vertex);
                    breadthfs(vertex,n);
                    break;
            case 2: printf("Enter the initial vertex:");
                    scanf("%d",&vertex);
                    depthfs(vertex,n);
                    break;
            default:exit(0);
  }
}

}