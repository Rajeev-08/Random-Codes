#include <stdio.h>

#define MAX 20

int n, m, trans[MAX][MAX], final[MAX], mark[MAX][MAX], group[MAX];

int main() {
    int i, j, k, f, changed=1;
    printf("States: "); scanf("%d",&n);
    printf("Symbols: "); scanf("%d",&m);

    printf("Transitions (delta(state,sym)): \n");
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&trans[i][j]);

    printf("No. of final states: "); scanf("%d",&f);
    printf("Final states: "); for(i=0;i<f;i++){ int x; scanf("%d",&x); final[x]=1; }

    // init distinguishability
    for(i=0;i<n;i++) for(j=0;j<n;j++)
        if(final[i]!=final[j]) mark[i][j]=1;

    // refine
    while(changed){
        changed=0;
        for(i=0;i<n;i++) for(j=0;j<n;j++)
            if(!mark[i][j] && i!=j)
                for(k=0;k<m;k++)
                    if(mark[ trans[i][k] ][ trans[j][k] ]){
                        mark[i][j]=1; changed=1; break;
                    }
    }

    // group states
    for(i=0;i<n;i++) group[i]=i;
    for(i=0;i<n;i++) for(j=i+1;j<n;j++) if(!mark[i][j]) group[j]=group[i];

    printf("\n--- Minimized DFA ---\n");
    int done[MAX]={0};
    for(i=0;i<n;i++) if(!done[group[i]]){
        done[group[i]]=1;
        printf("Group {");
        for(j=0;j<n;j++) if(group[j]==group[i]) printf(" %d",j);
        printf(" }%s\n",final[i]?" [FINAL]":"");
        for(k=0;k<m;k++){
            int nxt=trans[i][k];
            printf("  On %d -> Group {",k);
            for(j=0;j<n;j++) if(group[j]==group[nxt]) printf(" %d",j);
            printf(" }\n");
        }
    }
    return 0;
}
/* input:
States: 4
Symbols: 2
Transitions (delta(state,sym)):
1 2
0 3
3 0
2 1
No. of final states: 2
Final states: 2 3
*/
