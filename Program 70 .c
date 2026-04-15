//Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m, src;
    Edge edges[MAX];
    int dist[MAX];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    scanf("%d", &src);

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    int hasCycle = 0;

    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasCycle = 1;
            break;
        }
    }

    if (hasCycle) {
        printf("Negative weight cycle detected\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", dist[i]);
        }
    }

    return 0;
}
