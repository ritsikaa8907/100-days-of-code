//Problem: Detect cycle in directed graph using DFS and recursion stack.
#include <stdbool.h>
#include <stdlib.h>

bool dfs(int node, int** adj, int* adjSize, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool isCyclic(int V, int edges[][2], int E) {
    int* degree = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        degree[edges[i][0]]++;
    }

    int** adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    int* index = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][index[u]++] = v; 
    }

    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, degree, visited, recStack))
                return true;
        }
    }

    return false;
}
