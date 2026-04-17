//Using DFS or BFS, count number of connected components.
#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

void dfs(int node, int** graph, int* graphColSize, bool visited[]) {
    visited[node] = true;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, graph, graphColSize, visited);
        }
    }
}

int countComponents(int** graph, int graphSize, int* graphColSize) {
    bool visited[MAX] = {false};
    int count = 0;

    for (int i = 0; i < graphSize; i++) {
        if (!visited[i]) {
            dfs(i, graph, graphColSize, visited);
            count++;
        }
    }

    return count;
}
