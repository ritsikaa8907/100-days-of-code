//Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

#include <stdbool.h>
#include <stdlib.h>

bool dfs(int node, int parent, int** adj, int* adjSize, bool visited[]) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, adjSize, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true; 
        }
    }
    return false;
}

bool isCycle(int edges[][2], int E, int V) {
    int* degree = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
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
        adj[v][index[v]++] = u;
    }

    bool* visited = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, degree, visited))
                return true;
        }
    }

    return false;
}
