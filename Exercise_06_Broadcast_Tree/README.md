# Exercise 6: Obtain Broadcast Tree for a Subnet of Hosts

## Algorithm

The approach builds a graph of the subnet, where:

- Each node represents a router.
- Each arc represents a communication line between routers.

To determine the broadcast path between routers, the algorithm identifies the connected paths on the graph.

### Code

```c
#include <stdio.h>

int a[10][10], n;

void adj(int k) {
    int i, j;
    printf("Adjacent node of root node::\n");
    printf("%d\n\n", k);
    for (j = 1; j <= n; j++) {
        if (a[k][j] == 1 || a[j][k] == 1)
            printf("%d\t", j);
    }
    printf("\n");
    for (i = 1; i <= n; i++) {
        if ((a[k][j] == 0) && (a[i][k] == 0) && (i != k))
            printf("%d", i);
    }
}

void main() {
    int i, j, root;
    printf("Enter no.of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacent matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            printf("Enter connection of %d --> %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    printf("Enter root node: ");
    scanf("%d", &root);
    adj(root);
}
```

### Explanation

1. **Input Adjacency Matrix**: Takes an adjacency matrix as input to define connections between routers.
2. **Display Adjacent Nodes**: Based on the root node input, the program identifies and prints nodes directly connected to the root node.

### Output Example

```bash
Enter no.of nodes: 5
Enter adjacent matrix
Enter connection of 1 --> 1: 0
Enter connection of 1 --> 2: 1
Enter connection of 1 --> 3: 1
Enter connection of 1 --> 4: 0
Enter connection of 1 --> 5: 0
Enter connection of 2 --> 1: 1
Enter connection of 2 --> 2: 0
Enter connection of 2 --> 3: 1
Enter connection of 2 --> 4: 1
Enter connection of 2 --> 5: 0
Enter connection of 3 --> 1: 1
Enter connection of 3 --> 2: 1
Enter connection of 3 --> 3: 0
Enter connection of 3 --> 4: 0
Enter connection of 3 --> 5: 0
Enter connection of 4 --> 1: 0
Enter connection of 4 --> 2: 1
Enter connection of 4 --> 3: 0
Enter connection of 4 --> 4: 0
Enter connection of 4 --> 5: 1
Enter connection of 5 --> 1: 0
Enter connection of 5 --> 2: 0
Enter connection of 5 --> 3: 0
Enter connection of 5 --> 4: 1
Enter connection of 5 --> 5: 0
Enter root node: 2

Adjacent node of root node::
2
1   3   4
5
```
