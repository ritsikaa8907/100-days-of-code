//Using BFS or DFS, check if the entire graph is connected.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000

void dfs(int node, int** graph, int* graphColSize, bool visited[]) {
    visited[node] = true;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, graph, graphColSize, visited);
        }
    }
}

bool isConnected(int** graph, int graphSize, int* graphColSize) {
    bool visited[SIZE] = {false};

    dfs(0, graph, graphColSize, visited);

    for (int i = 0; i < graphSize; i++) {
        if (!visited[i])
            return false;
    }

    return true;
}

int main() {
    int n = 4;

    int** graph = (int**)malloc(n * sizeof(int*));
    int graphColSize[] = {1, 1, 1, 1};

    graph[0] = (int[]) {1};
    graph[1] = (int[]) {0};
    graph[2] = (int[]) {3};
    graph[3] = (int[]) {2};

    if (isConnected(graph, n, graphColSize))
        printf("Graph is Connected\n");
    else
        printf("Graph is Not Connected\n");

    free(graph);
    return 0;
}
