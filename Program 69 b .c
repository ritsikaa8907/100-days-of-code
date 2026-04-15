//You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 101

typedef struct {
    int node;
    int dist;
} Pair;

Pair heap[MAX * MAX];
int size = 0;

void swap(Pair *a, Pair *b) {
    Pair t = *a;
    *a = *b;
    *b = t;
}

void push(Pair p) {
    heap[++size] = p;
    int i = size;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

Pair pop() {
    Pair top = heap[1];
    heap[1] = heap[size--];
    int i = 1;
    while (2 * i <= size) {
        int j = 2 * i;
        if (j + 1 <= size && heap[j + 1].dist < heap[j].dist)
            j++;
        if (heap[i].dist <= heap[j].dist)
            break;
        swap(&heap[i], &heap[j]);
        i = j;
    }
    return top;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int adj[MAX][MAX];
    int weight[MAX][MAX];
    int deg[MAX] = {0};
    int dist[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        for (int j = 1; j <= n; j++) {
            weight[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        adj[u][deg[u]] = v;
        weight[u][v] = w;
        deg[u]++;
    }

    dist[k] = 0;
    push((Pair){k, 0});

    while (size > 0) {
        Pair cur = pop();
        int node = cur.node;
        int d = cur.dist;

        if (d > dist[node]) continue;

        for (int i = 0; i < deg[node]; i++) {
            int v = adj[node][i];
            int w = weight[node][v];

            if (dist[node] + w < dist[v]) {
                dist[v] = dist[node] + w;
                push((Pair){v, dist[v]});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > ans)
            ans = dist[i];
    }

    return ans;
}
