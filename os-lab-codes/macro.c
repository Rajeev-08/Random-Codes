#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct macro_definition{
    char label[20],opcode[20],operand[20];
}mac[20];
int main(){
FILE*input,*output,*macrodef;
    char label[20],opcode[20],operand[20],macroname[20];
    int lines,i;

input = fopen("input.txt", "r");
output = fopen("output.txt", "w");
macrodef = fopen("macro_def.txt", "w");

fscanf(input,"%s\t%s\t%s",label,opcode,operand);

while(strcmp(opcode,"END")!=0){
    if(strcmp(opcode,"MACRO")==0){
            strcpy(macroname,label);
            fscanf(input,"%s\t%s\t%s",label,opcode,operand);
            lines=0;
        while(strcmp(opcode,"MEND")!=0){
            fprintf(macrodef,"%s\t%s\t%s\n",label,opcode,operand);
            strcpy(mac[lines].label,label);
            strcpy(mac[lines].opcode,opcode);
            strcpy(mac[lines].operand,operand);
            fscanf(input,"%s\t%s\t%s",label,opcode,operand);
            lines++;
            }
    }else if(strcmp(opcode,macroname)==0){
            fprintf(output,"%s\t%s\t%s\n",label,mac[0].opcode,mac[0].operand);
            for(i=1;i<lines;i++){
                fprintf(output,"%s\t%s\t%s\n",mac[i].label,mac[i].opcode,mac[i].operand);
            }   
    }else{
            fprintf(output,"%s\t%s\t%s\n",label,opcode,operand);
    }


    if(fscanf(input,"%s\t%s\t%s",label,opcode,operand)==EOF){
        break;
        }

}

 fprintf(output,"%s\t%s\t%s",label,opcode,operand);
 fclose(input);fclose(output);fclose(macrodef);
}