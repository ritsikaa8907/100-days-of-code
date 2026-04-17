//Given a reference of a node in a connected undirected graph. Return a deep copy (clone) of the graph. Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
#include <stdlib.h>

#define SIZE 1000

struct Node* visited[SIZE];
struct Node* original[SIZE];
int mapSize = 0;

struct Node* getCloned(struct Node* node) {
    for (int i = 0; i < mapSize; i++) {
        if (original[i] == node)
            return visited[i];
    }
    return NULL;
}

void storeMapping(struct Node* orig, struct Node* clone) {
    original[mapSize] = orig;
    visited[mapSize] = clone;
    mapSize++;
}

struct Node* cloneGraphDFS(struct Node* node) {
    if (node == NULL)
        return NULL;

    struct Node* existing = getCloned(node);
    if (existing != NULL)
        return existing;

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));

    storeMapping(node, clone);

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraphDFS(node->neighbors[i]);
    }

    return clone;
}

struct Node* cloneGraph(struct Node* node) {
    mapSize = 0;
    return cloneGraphDFS(node);
}
