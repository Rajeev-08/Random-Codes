#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sym_read{
    char label[20];
    int add;
}sym[20];

int main(){
    char label[10],mne[10],operand[10],opcode[10];
    int locctr=0,size=0,start=0,temp,ind=-1,i,len;

 FILE *input, *optab, *symtab, *inter, *length;

    input = fopen("input.txt", "r");
    optab = fopen("optab.txt", "r");
    symtab = fopen("symtab.txt", "w");
    inter = fopen("inter.txt", "w");

    fscanf(input,"%s\t%s\t%x",label,mne,&temp);
    if(strcmp(mne,"START")==0){
        start=temp;
        locctr=start;
        fprintf(inter,"-\t%s\t%s\t%x\n",label,mne,locctr);
        fscanf(input,"%s\t%s\t%s",label,mne,operand);
    }
    while(strcmp(mne,"END")!=0){

    fprintf(inter,"%x\t%s\t%s\t%s\n",locctr,label,mne,operand);

        if(strcmp(label,"-")!=0){
            for(i=0;i<=ind;i++){
                if(strcmp(sym[i].label,label)==0){
                    printf("\n dup");
                    exit(0);
                }
            }
            strcpy(sym[++ind].label,label);
            sym[ind].add=locctr;
        }

        fseek(optab,0,SEEK_SET);
        int found=0;
        while(fscanf(optab,"%s\t%x",opcode,&temp)!=EOF){
            if(strcmp(opcode,mne)==0){
                locctr+=3;size+=3;
                 found=1;
                break;

            }
        }
if(!found){
            if(strcmp(mne,"WORD")==0){
            locctr+=3;size+=3;
            }else if(strcmp(mne,"RESW")==0){
            locctr+=atoi(operand)*3;
            }else if(strcmp(mne,"RESB")==0){
            locctr+=atoi(operand);
            }else if(strcmp(mne,"BYTE")==0){
            if(operand[0]='C'){
                len=strlen(operand)-3;
            }else{
                len=(strlen(operand)-3)/2;
            }
            locctr+=len;
            size+=len;
            }
        }
        fscanf(input,"%s\t%s\t%s",label,mne,operand);
  }
    fprintf(inter,"\t%s\t%s\t%s",label,mne,operand);// printing END

    for(i=0;i<=ind;i++)
    fprintf(symtab,"%s\t%x\n",sym[i].label,sym[i].add);

    length=fopen("length.txt","w");
    fprintf(length,"%x\t%x",locctr-start,size);

    fclose(input);fclose(inter);fclose(optab);fclose(symtab);fclose(length);
}
