//There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network. Return all critical connections in the network in any order.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

int timeCounter;

void dfs(int u, int parent, int** graph, int* graphColSize,
         int* disc, int* low, int* visited,
         int** result, int* returnSize) {
    
    visited[u] = 1;
    disc[u] = low[u] = timeCounter++;

    for (int i = 0; i < graphColSize[u]; i++) {
        int v = graph[u][i];

        if (v == parent)
            continue;

        if (!visited[v]) {
            dfs(v, u, graph, graphColSize, disc, low, visited, result, returnSize);

            if (low[v] < low[u])
                low[u] = low[v];

            if (low[v] > disc[u]) {
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                         int* connectionsColSize, int* returnSize,
                         int** returnColumnSizes) {
    
    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphColSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        graphColSize[connections[i][0]]++;
        graphColSize[connections[i][1]]++;
    }

    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(graphColSize[i] * sizeof(int));
        graphColSize[i] = 0;
    }

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        graph[u][graphColSize[u]++] = v;
        graph[v][graphColSize[v]++] = u;
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));
    for (int i = 0; i < connectionsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }

    *returnSize = 0;
    timeCounter = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, graph, graphColSize, disc, low, visited, result, returnSize);
        }
    }

    return result;
}

