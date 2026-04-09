//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void topologicalSort(int n, int graph[MAX][MAX]) {
    int indegree[MAX] = {0};
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for (i = 0; i < n; i++) {
            if (graph[u][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    if (count != n) {
        printf("\nGraph has a cycle. Topological sort not possible.\n");
    }
}

int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Topological Sort: ");
    topologicalSort(n, graph);

    return 0;
}
