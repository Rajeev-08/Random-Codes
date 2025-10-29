
#include <stdio.h>
#include <stdbool.h>

#define MNS 31
#define MSYM 10

void main() {
    int nst, nsym, nfin, nfm = 0;
    char alpha[MSYM];
    int nfa_table[MNS][MSYM] = {0};
    printf("Enter number of NFA states (max %d): ", MNS);
    scanf("%d", &nst);
    printf("Enter number of symbols (max %d): ", MSYM);
    scanf("%d", &nsym);

    printf("Enter symbols: ", nsym);
    for (int i = 0; i < nsym; i++) scanf(" %c", &alpha[i]);

    printf("\nHow many NFA final states? ");
    scanf("%d", &nfin);

    if (nfin > 0) {
        printf("Enter the final state(s): ");
        for (int i = 0; i < nfin; i++) {
            int final_state;
            scanf("%d", &final_state);
            nfm |= (1 << final_state);
        }
    }

    printf("\nEnter NFA transitions:\n");
    for (int i = 0; i < nst; i++) {
        for (int j = 0; j < nsym; j++) {
            int n_next;
            printf("d(q%d, %c) -> No. of states: ", i, alpha[j]);
            scanf("%d", &n_next);
            if (n_next > 0) {
                printf("Enter state(s): ");
                for (int k = 0; k < n_next; k++) {
                    int next_state;
                    scanf("%d", &next_state);
                    nfa_table[i][j] |= (1 << next_state);
                }
            }
        }
    }

    int max_dfa_states = 1 << nst;
    int dfa_states[max_dfa_states], dfa_table[max_dfa_states][MSYM], q[max_dfa_states];
    int dfa_count = 0, q_head = 0, q_tail = 0;
    dfa_states[dfa_count++] = (1 << 0);
    q[q_tail++] = 0;

    while (q_head < q_tail) {
        int current_dfa_idx = q[q_head++];
        int current_set = dfa_states[current_dfa_idx];
        for (int i = 0; i < nsym; i++) {
            int next_set = 0, found_idx = -1;
            for (int s = 0; s < nst; s++) {
                if ((current_set >> s) & 1) next_set |= nfa_table[s][i];
            }
            for (int j = 0; j < dfa_count; j++) {
                if (dfa_states[j] == next_set) {
                    found_idx = j;
                    break;
                }
            }
            if (found_idx != -1) dfa_table[current_dfa_idx][i] = found_idx;
            else {
                dfa_states[dfa_count] = next_set;
                dfa_table[current_dfa_idx][i] = dfa_count;
                q[q_tail++] = dfa_count;
                dfa_count++;
            }
        }
    }

    printf("\n--- Final DFA Transition Table ---\nState\t");
    for (int i = 0; i < nsym; i++) printf("'%c'\t", alpha[i]);
    printf("\n------------------------------------\n");

    for (int i = 0; i < dfa_count; i++) {
        bool is_final = (dfa_states[i] & nfm) != 0;
        printf("%sD%d\t", is_final ? "*" : " ", i);
        for (int j = 0; j < nsym; j++) printf("D%d\t", dfa_table[i][j]);
        printf("\n");
    }

    printf("\n(DFA State Definitions:)\n");
    for (int i = 0; i < dfa_count; i++) {
        printf("D%d = { ", i);
        for (int s = 0; s < nst; s++) {
            if ((dfa_states[i] >> s) & 1) printf("%d ", s);
        }
        printf("}\n");
    }
}
