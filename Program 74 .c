//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

#define MAX 100

void winner(char votes[][20], int n) {
    int count[MAX] = {0};
    char unique[MAX][20];
    int u = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < u; j++) {
            if (strcmp(unique[j], votes[i]) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(unique[u], votes[i]);
            count[u] = 1;
            u++;
        } else {
            count[found]++;
        }
    }

    int maxVotes = 0;
    char ans[20];

    for (int i = 0; i < u; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(ans, unique[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(unique[i], ans) < 0) {
                strcpy(ans, unique[i]);
            }
        }
    }

    printf("%s %d\n", ans, maxVotes);
}

int main() {
    char votes[][20] = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"};
    int n = 13;

    winner(votes, n);

    return 0;
}
