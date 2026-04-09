//Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int q[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    q[++rear] = x;
}

int dequeue() {
    return q[front++];
}

int isEmpty() {
    return front > rear;
}

char* findOrder(char *words[], int N, int K) {
    int adj[K][K];
    int indegree[K];

    for (int i = 0; i < K; i++) {
        indegree[i] = 0;
        for (int j = 0; j < K; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len = strlen(w1) < strlen(w2) ? strlen(w1) : strlen(w2);

        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (adj[u][v] == 0) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                break;
            }
        }
    }

    for (int i = 0; i < K; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    char *ans = (char*)malloc((K + 1) * sizeof(char));
    int idx = 0;

    while (!isEmpty()) {
        int u = dequeue();
        ans[idx++] = u + 'a';

        for (int v = 0; v < K; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    if (idx != K) {
        return "";
    }

    ans[idx] = '\0';
    return ans;
}
