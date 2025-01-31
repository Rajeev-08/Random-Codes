#include<stdio.h>
#include<math.h>
int n,l,b[100];
 int loc=0;


void build(int data, int i){
    char ch;
    b[i]=data;
    printf("\ndo you want to create left/right child (l/r) :");
    scanf(" %c",&ch);
    if(ch == 'l'){
        printf("\nenter the node :");
        scanf("%d",&data);
        build(data, 2*i);
    }
    if(ch == 'r' ){
        printf("\nenter the node :");
        scanf("%d", &data);
        build(data, 2*i+1);
    }

}   
int search(int data,int i){
   
    if(i>0&&b[i]==data){
        return i;
    }
    if(b[2*i]!=0){
        loc=search(data,2*i);
        
    }
    if(b[2*i+1]!=0){
        loc=search(data,2*i+1);
        
    }
    return loc;

}
void insert(int pnode){
    int data;
    int i=search(pnode,1);
   char ch;
    if(b[2*i]==0){
        
            printf("enter the LEFT node : ");
            scanf("%d",&data);
            b[2*i]=data;
        
    }
    if(b[2*i+1]==0){
        
            printf("enter the RIGHT node : ");
            scanf("%d",&data);
            b[2*i+1]=data;
        
    }
    }

void display(){
    for(int i=1;i<=n;i++){
        if(b[i] == 0){
            printf("_ ");
        }else{
            printf("%d ",b[i]);
        }
    }
}

void delete(int data){
    int i=search(data,1);
    printf("index : %d",i);
    if(i==0){
        printf("not found");
    }else{
    if(b[2*i]==0&&b[2*i+1]==0){
        b[i]=0;
    }else{
        printf("\ncan't delete non leaf node");
    }
    }
}

int main(){
    int choice,data,pnode;
    printf("enter the number of levels :");
    scanf("%d",&l);
    n=pow(2,l+1)-1;
    for(int i=1;i<=n;i++){
        b[i]=0;
    }
    do{
     printf("\n1.build\n2.insert\n3.delete\n4.display\n5.exit");
     printf("\nenter the choice :");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:printf("enter the root node :");
                    scanf("%d",&data);
                    build(data, 1);
                    break;
             case 2:printf("enter the parent node :");
                    scanf("%d",&pnode);
                    insert(pnode);
                    break;
                   
            case 3:printf("enter the node to delete :");
                scanf("%d",&data);
                delete(data);
                break;      

            case 4: display(); 
                    break;       

        }
}while(choice!=5);

}