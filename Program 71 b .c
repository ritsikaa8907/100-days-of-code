//You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[0] = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        visited[u] = 1;
        result += dist[u];

        for (int v = 0; v < n; v++) {
            int cost = abs(points[u][0] - points[v][0]) +
                       abs(points[u][1] - points[v][1]);

            if (!visited[v] && cost < dist[v]) {
                dist[v] = cost;
            }
        }
    }

    return result;
}
