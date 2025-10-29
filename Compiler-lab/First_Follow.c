#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

int n;
char prod[MAX][MAX];
char first[20],follow[20];

int isNonterminal(char c){
    return (c>='A'&&c<='Z');
}

void findfirst(char c){
    if(!isNonterminal(c)){
        if(!strchr(first,c))
            strncat(first,&c,1);
    }

    for(int i=0;i<n;i++){
        if(prod[i][0]==c){
            if(prod[i][2]=='#'){
                if(!strchr(first,'#'))
                    strncat(first,"#",1);
            }else if(!isNonterminal(prod[i][2])){
                if(!strchr(first,prod[i][2]))
                    strncat(first,&prod[i][2],1);
            }else{
                findfirst(prod[i][2]);
            }
        }
    }
}

void findfollow(char c){
    if(prod[0][0]==c){
        if(!strchr(follow,'$'))
            strncat(follow,"$",1);
    }

    for(int i=0;i<n;i++){
        for(int j=2;j<strlen(prod[i]);j++){
            if(prod[i][j]==c){
                if(prod[i][j+1]!='\0'){
                    first[0]='\0';
                    findfirst(prod[i][j+1]);
                    for(int k=0;k<strlen(first);k++){
                        if(first[k]!='#'&&!strchr(follow,first[k]))
                            strncat(follow,&first[k],1);
                    }
                    if(strchr(first,'#')&&prod[i][0]!=c){
                        findfollow(prod[i][0]);
                    }

                }else if(prod[i][0]!=c){
                    findfollow(prod[i][0]);
                }
            }
        }
    }
}
int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions (like E=E+T):\n");
    for (int i = 0; i < n; i++)
        scanf("%s", prod[i]);

    char c;
    printf("\nEnter the non-terminal to find FIRST & FOLLOW: ");
    scanf(" %c", &c);

    first[0] = '\0';
    findfirst(c);
    printf("FIRST(%c) = { ", c);
    for (int i = 0; i < strlen(first); i++)
        printf("%c ", first[i]);
    printf("}\n");

    follow[0] = '\0';
    findfollow(c);
    printf("FOLLOW(%c) = { ", c);
    for (int i = 0; i < strlen(follow); i++)
        printf("%c ", follow[i]);
    printf("}\n");

    return 0;
}
/*
3
S=AB
A=a
B=b
S

*/
