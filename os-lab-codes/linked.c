#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int file;
    int next;
}disk;

int main(){
    int size,n,i,j;
    printf("enter the size of disk :");
    scanf("%d",&size);

    disk block[size];
    for(i=0;i<size;i++){
        block[i].file=-1;
        block[i].next=-1;
    }

    printf("\n enter the no.of files :");
    scanf("%d",&n);
    int start[n],end[n];
    for(i=0;i<n;i++){
        int filesize,ptr=0,last_ptr=-1;
        printf("\n enter the size of f%d :",i);
        scanf("%d",&filesize);
        for(j=0;j<filesize;j++){
            while(block[ptr].file!=-1){
            ptr=(ptr+1)%size;
            }

            if(j==0){
                start[i]=ptr;
            }else{
                block[last_ptr].next=ptr;
            }

            last_ptr=ptr;
            block[ptr].file=i;
        }
        end[i]=last_ptr;

    }

    printf("\n filetable\nfilename\tstart\tend\n");
    for(i=0;i<n;i++){
        printf("f%d\t%d\t%d\n",i,start[i],end[i]);
    }

    printf("\ndisk\nblock\tfile\tnext\n");
    for(i=0;i<size;i++){
        printf("%d\t%d",i,block[i].file);
        if(block[i].file!=-1&&block[i].next==-1){
            printf("\tEND\n");
        }else{
            printf("\t%d\n",block[i].next);
        }
    }



}