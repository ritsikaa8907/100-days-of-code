//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
#include <stdbool.h>
#include <stdlib.h>

bool dfs(int node, int** adj, int* adjSize, int* state) {
    if (state[node] == 1) return true;   
    if (state[node] == 2) return false;  

    state[node] = 1; 

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (dfs(neighbor, adj, adjSize, state))
            return true;
    }

    state[node] = 2;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    // Step 1: Count outgoing edges (for adjacency list)
    int* degree = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int b = prerequisites[i][1];
        degree[b]++;
    }

    // Step 2: Allocate adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    // Step 3: Fill adjacency list
    int* index = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][index[b]++] = a;  // edge b → a
    }

    // Step 4: DFS cycle detection
    int* state = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        if (dfs(i, adj, degree, state))
            return false;
    }

    return true;
}
