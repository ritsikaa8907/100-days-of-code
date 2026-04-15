Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
  #include <stdio.h>
#include <limits.h>

#define MAX 100

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n, i, j, src;
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    scanf("%d", &src);

    for (i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] && dist[u] != INT_MAX &&
                dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
