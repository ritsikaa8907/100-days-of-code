//There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:There are no self-edges (graph[u] does not contain u).There are no parallel edges (graph[u] does not contain duplicate values).If v is in graph[u], then u is in graph[v] (the graph is undirected).The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.Return true if and only if it is bipartite
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[MAX];
    
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    int queue[MAX];
    
    for (int start = 0; start < graphSize; start++) {
        if (color[start] != -1)
            continue;

        int front = 0, rear = 0;

        queue[rear++] = start;
        color[start] = 0;

        while (front < rear) {
            int node = queue[front++];

            for (int i = 0; i < graphColSize[node]; i++) {
                int neighbor = graph[node][i];

                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                }
                else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}
