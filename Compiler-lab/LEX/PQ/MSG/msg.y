%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(const char *s);

typedef struct {
    char userid[50];
    char username[50];
    char message[100];
    char latitude[20];
    char longitude[20];
    char country[50];
    char state[50];
} Record;

Record rec;
%}

%union {
    char *str;
}

%token <str> STRING REALNUM
%token NEWLINE

%%
file : entries
     ;

entries : entries entry
        | entry
        ;

entry : STRING STRING STRING REALNUM REALNUM STRING STRING NEWLINE
       {
           strcpy(rec.userid, $1);
           strcpy(rec.username, $2);
           strcpy(rec.message, $3);
           strcpy(rec.latitude, $4);
           strcpy(rec.longitude, $5);
           strcpy(rec.country, $6);
           strcpy(rec.state, $7);
           printf("✅ Valid Entry:\n");
           printf("UserID: %s | Username: %s | Message: %s | Lat: %s | Long: %s | Country: %s | State: %s\n\n",
                  rec.userid, rec.username, rec.message, rec.latitude, rec.longitude, rec.country, rec.state);
       }
     ;
%%

void yyerror(const char *s) {
    printf("❌ Invalid record detected.\n");
}

int main() {
    printf("Reading entries from file...\n\n");
    yyparse();
    return 0;
}
/* 
U123 John HelloWorld 12.34 77.89 India Karnataka
U456 Alice HiThere 19.07 72.87 India Maharashtra
*/
