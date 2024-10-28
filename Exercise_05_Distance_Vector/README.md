# 5. Take an example subnet graph with weights indicating delay between nodes. Now obtain Routing table at each node using distance vector routing algorithm

Dijkstra's algorithm is also called the single-source shortest path algorithm. It is based on the greedy technique. The algorithm maintains a list `visited[]` of vertices, whose shortest distance from the source is already known.

If `visited[i]` equals 1, then the shortest distance of vertex `i` is already known. Initially, `visited[i]` is marked as `0`, except for the source vertex. At each step, we mark `visited[v]` as `1`, where `v` is the vertex at the shortest distance from the source vertex. At each step of the algorithm, the shortest distance of each vertex is stored in an array `distance[]`.

### C Code Implementation:

```c
#include <conio.h>
#include <stdio.h>
#include <string.h>

void min(int[], int, int[][2], int);

void main() {
    int s[20][20], i, j, n, ne[20][20], k = 0, d[20], z[20][2], e[20];
    char nam[20], r;

    // Input the number of routers in the subnet
    printf("Enter number of routers in the subnet: ");
    scanf("%d", &n);

    // Input the adjacency matrix for the subnet
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    // Select the router for which to construct the routing table
    printf("Which router's routing table do you want to construct (A-Z): ");
    scanf(" %c", &r); // Added a space before %c to handle newline character

    // Display the neighbors of the selected router
    printf("The neighbors of %c are: ", r);
    for (i = 0; i < n; i++) {
        if (s[r - 'A'][i] == 1) {
            printf("%c ", i + 'A');
            nam[k++] = i + 'A';
        }
    }
    printf("\n");

    // Input the delay between the selected router and its neighbors
    for (i = 0; i < k; i++) {
        printf("Enter %c%c delay: ", r, nam[i]);
        scanf("%d", &d[i]);
    }

    // Input each neighbor's routing table
    for (i = 0; i < k; i++) {
        printf("\nEnter %c's routing table:\n", nam[i]);
        for (j = 0; j < n; j++) {
            scanf("%d", &ne[i][j]);
        }
    }

    // Calculate the minimum delay for each node
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            e[j] = ne[j][i] + d[j];
        }
        min(e, k, z, i);
    }

    // Print the routing table for the selected router
    printf("To\t");
    for (i = 0; i < k; i++) {
        printf("%c\t", nam[i]);
    }

    printf("\nNEW TABLE FOR %c\n", r);
    for (i = 0; i < k; i++) {
        printf(".....\t");
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%c|", i + 'A');
        for (j = 0; j < k; j++) {
            printf("%d\t", ne[j][i]);
        }

        if (r == (i + 'A')) {
            printf("0\t-\n");
        } else {
            printf("%d\t%c\n", z[i][0], nam[z[i][1]]);
        }
    }
}

void min(int e[20], int k, int z[20][2], int i) {
    int b;

    z[i][0] = e[0];
    z[i][1] = 0;

    for (b = 1; b < k; b++) {
        if (e[b] < z[i][0]) {
            z[i][0] = e[b];
            z[i][1] = b;
        }
    }
}
```
