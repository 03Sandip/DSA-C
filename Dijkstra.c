#include <stdio.h>

#define INFINITY 9999
#define MAX_NODES 9

void dijkstra(int graph[MAX_NODES][MAX_NODES], int start, int numNodes) {
    int distances[MAX_NODES];
    
    for (int i = 0; i < numNodes; i++) {
        distances[i] = INFINITY;
    }
    
    distances[start] = 0;
    
    for (int count = 0; count < numNodes - 1; count++) {
        for (int u = 0; u < numNodes; u++) {
            for (int v = 0; v < numNodes; v++) {
                if (graph[u][v] != 0 && distances[u] != INFINITY && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                }
            }
        }
    }
    printf("Shortest distance from \n");
    for (int i = 0; i < numNodes; i++) {
        printf("%d to %d: %d\n", start, i, distances[i]);
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES];
    int numNodes, startNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the start node: ");
    scanf("%d", &startNode);

    dijkstra(graph, startNode, numNodes);

    return 0;
}
