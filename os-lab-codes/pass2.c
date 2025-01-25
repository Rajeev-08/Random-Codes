#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
FILE *inter,*optab,*symtab,*length,*as,*obj;
obj=fopen("obj.txt","w");
as=fopen("as.txt","w");
optab=fopen("optab.txt","r");
symtab=fopen("symtab.txt","r");
inter=fopen("inter.txt","r");
length=fopen("length.txt","r");

char label[20],mne[20],operand[20],opcode[20],temp[20],start[20],locctr[20],size[20],l[20],t[20];
int i,j;

fscanf(inter,"%s\t%s\t%s\t%s",locctr,label,mne,operand);
fprintf(as,"%s\t%s\t%s\t%s",locctr,label,mne,operand);
fscanf(length,"%s\t%s",temp,size);
strcpy(start,operand);
fprintf(obj,"H^%s^00%s^0000%s\n",label,start,temp);
fprintf(obj,"T^00%s^%s",start,size);

while(fscanf(inter,"%s\t%s\t%s\t%s",locctr,label,mne,operand)!=EOF){
    fprintf(as,"\n%s\t%s\t%s\t%s\t",locctr,label,mne,operand);
    fseek(optab,0,SEEK_SET);
    int found=0;
    while(fscanf(optab,"%s\t%s",opcode,temp)!=EOF){
        if(strcmp(opcode,mne)==0){
            found=1;
            break;
        }
    }

    if(found==1){
        fseek(symtab,0,SEEK_SET);
        while(fscanf(symtab,"%s\t%s",l,t)!=EOF){
            if(strcmp(l,operand)==0){
                break;
            }
        }
        fprintf(as,"%s%s",temp,t);
        fprintf(obj,"^%s%s",temp,t);
    }

    if(strcmp(mne,"BYTE")==0){
        fprintf(obj,"^");
            for(i=2;i<strlen(operand)-1;i++){
                fprintf(as,"%x",operand[i]);
                fprintf(obj,"%02X",operand[i]);          
        }
    }else if(strcmp(mne,"WORD")==0){
        fprintf(as,"00000%s",operand);
        fprintf(obj,"^00000%s",operand);
    }
}

fprintf(obj,"\nEND^00%s",start);

fclose(optab);fclose(symtab);fclose(inter);fclose(length);fclose(as);fclose(obj);
}