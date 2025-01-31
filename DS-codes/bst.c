#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*right;
    struct node*left;
};
struct node*root=NULL;
struct node*ptr=NULL;
struct node*create(int value){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->right=NULL;
    new->left=NULL;
    return new;
    
}

struct node*suc(struct node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node*insert(struct node*root,int value){
    if(root==NULL){
        return create(value);
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}


struct node*delete(struct node*root,int value){
    if(root==NULL){
        return root;
    }
    if(value<root->data){
        root->left=delete(root->left,value);
    }else if(value>root->data){
        root->right=delete(root->right,value);
    }else{
        if(root->left==NULL){
            ptr=root->right;
            free(root);
            return ptr;
        }else if(root->right==NULL){
            ptr=root->left;
            free(root);
            return ptr;
        }
        ptr=suc(root->right);
        root->data=ptr->data;
        root->right=delete(root->right,ptr->data);
    }
    return root;
}
void traversal(struct node*root){

    if(root!=NULL){
        traversal(root->left);
        printf("%d",root->data);
        traversal(root->right);
    }
}

int main(){
    int n,value;
    printf("enter no of elements to insert : ");
    scanf("%d",&n);
    printf("enter %d elments to insert : ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        root=insert(root,value);
    }
    printf("entered tree\n");
    traversal(root);
        printf("enter the value to delete : ");
            scanf("%d",&value);
            root=delete(root,value);
            printf("after deleting %d ",value);
            traversal(root);
        
    
}