#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *out,*obj;
    out=fopen("out.txt","w");
    obj=fopen("obj.txt","r");
    char line[50],addr[10],ch;
    int hexaddr,st;
    if(out&&obj){
        while((ch=fgetc(obj))!=EOF){
            if(ch!='^'){
                fputc(ch,out);
            }
        }
    }else{
        printf("error op\n");
        exit(1);
    }
    fclose(obj);
    fclose(out);
int i,j;
printf("\n enter start add ;");
scanf("%x",&st);
    out=fopen("out.txt","r");
    printf("ADDRESS\t\tCONTENT\n");
    while(fscanf(out,"%s",line)!=EOF){
        if(line[0]=='T'){
            for(i=1,j=0;i<=6;i++,j++){
                addr[j]=line[i];
            }
            addr[j]='\0';
            sscanf(addr,"%x",&hexaddr);
            hexaddr+=st;
            i=9;
            while (line[i]!='\0')
            {
                printf("%x\t\t%c%c\n",hexaddr,line[i],line[i+1]);
                hexaddr++;i+=2;

            }
            
        }
    }fclose(out);
}