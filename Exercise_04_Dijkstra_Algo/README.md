# 4. Implement Dijkstra’s Algorithm to Compute the Shortest Path Through a Graph

Dijkstra's algorithm is used to find the shortest paths between nodes in a graph. It can represent various systems, such as road networks. Dijkstra's original algorithm finds the shortest path between two nodes, but a more common variant selects a single node as the source and computes the shortest paths to all other nodes, forming a shortest-path tree.

## Algorithm Implementation

```c
#include <conio.h>
#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode);

int main() {
    int G[MAX][MAX], i, j, n, u;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("\nEnter the starting node: ");
    scanf("%d", &u);
    dijkstra(G, n, u);
    return 0;
}

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Create the cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];

    // Initialize distance[], pred[], and visited[]
    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    // Find the shortest path for all nodes
    while (count < n - 1) {
        mindistance = INFINITY;

        // Select the next node at minimum distance
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        // Update the distances
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }

        count++;
    }

    // Print the path and distance of each node
    for (i = 0; i < n; i++)
        if (i != startnode) {
            printf("\nDistance of node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            do {
                j = pred[j];
                printf(" <- %d", j);
            } while (j != startnode);
        }
}
```

## Output

```bash
Enter the number of vertices: 5

Enter the adjacency matrix:
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0

Enter the starting node: 0

Distance of node 1 = 10
Path = 1 <- 0

Distance of node 2 = 50
Path = 2 <- 3 <- 0

Distance of node 3 = 30
Path = 3 <- 0

Distance of node 4 = 60
Path = 4 <- 2 <- 3 <- 0
```

## Explanation

- **Dijkstra's Algorithm**: The algorithm is designed to find the shortest path from a source node to all other nodes in the graph. It uses a priority-based approach to pick the next closest node to the source.
- **Graph Representation**: The graph is represented by an adjacency matrix where the weights of the edges between the nodes are given as input. If there is no direct edge between two nodes, the weight is considered infinite (`INFINITY`).
- **Steps**:
  - Initialize the distance and predecessor arrays.
  - Continuously select the unvisited node with the smallest tentative distance.
  - Update the distance and predecessor for each neighboring node of the selected node.
  - Repeat until all nodes are visited.

This implementation demonstrates how Dijkstra's algorithm can be used to calculate the shortest path and distances from a starting node to all other nodes in a graph.
