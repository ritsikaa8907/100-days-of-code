//Build a graph with n vertices and m edges using adjacency matrix representation.
#include <stdio.h>

int main() {
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int adj[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int type;
    printf("Enter 0 for Undirected Graph, 1 for Directed Graph: ");
    scanf("%d", &type);

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if(type == 0) { 
            adj[v][u] = 1;
        }
    }

    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
