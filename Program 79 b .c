//Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph

#include <stdio.h>
#include <stdlib.h>

void dfs1(int u, int* visited, int** adj, int* adjSize, int* stack, int* top) {
    visited[u] = 1;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs1(v, visited, adj, adjSize, stack, top);
        }
    }

    stack[(*top)++] = u;
}

void dfs2(int u, int* visited, int** rev, int* revSize) {
    visited[u] = 1;

    for (int i = 0; i < revSize[u]; i++) {
        int v = rev[u][i];
        if (!visited[v]) {
            dfs2(v, visited, rev, revSize);
        }
    }
}

int kosaraju(int V, int** edges, int edgesSize, int* edgesColSize) {
    int** adj = (int**)malloc(V * sizeof(int*));
    int** rev = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));
    int* revSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        revSize[edges[i][1]]++;
    }

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        rev[i] = (int*)malloc(revSize[i] * sizeof(int));
        adjSize[i] = 0;
        revSize[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;
        rev[v][revSize[v]++] = u;
    }

    int* visited = (int*)calloc(V, sizeof(int));
    int* stack = (int*)malloc(V * sizeof(int));
    int top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, visited, adj, adjSize, stack, &top);
        }
    }

    for (int i = 0; i < V; i++) visited[i] = 0;

    int count = 0;

    for (int i = V - 1; i >= 0; i--) {
        int node = stack[i];
        if (!visited[node]) {
            dfs2(node, visited, rev, revSize);
            count++;
        }
    }

    return count;
}
