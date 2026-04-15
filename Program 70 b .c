//There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei. You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
#include <stdio.h>
#include <limits.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int dist[n];
    
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    
    dist[src] = 0;

    for (int i = 0; i <= k; i++) {
        int temp[n];
        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}
