//You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph. Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
#include <stdio.h>

#define MAX 1001

int parent[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb)
        return 0;

    parent[pa] = pb;
    return 1;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    for (int i = 1; i <= edgesSize; i++)
        parent[i] = i;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (!unionSet(u, v)) {
            int* res = (int*)malloc(2 * sizeof(int));
            res[0] = u;
            res[1] = v;
            *returnSize = 2;
            return res;
        }
    }

    *returnSize = 0;
    return NULL;
}
