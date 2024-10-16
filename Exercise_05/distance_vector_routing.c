#include <conio.h>
#include <stdio.h>
#include <string.h>

void min(int[], int, int[][2], int);

void main() {
    int s[20][20], i, j, n, ne[20][20], k = 0, d[20], z[20][2], e[20];
    char nam[20], r;

    printf("Enter number of routers in the subnet: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    printf("Which router's routing table do you want to construct (A-Z): ");
    scanf(" %c", &r); // Added a space before %c to handle newline character

    printf("The neighbours of %c are: ", r);

    for (i = 0; i < n; i++) {
        if (s[r - 'A'][i] == 1) {
            printf("%c ", i + 'A');
            nam[k++] = i + 'A';
        }
    }
    printf("\n");

    for (i = 0; i < k; i++) {
        printf("Enter %c%c delay: ", r, nam[i]);
        scanf("%d", &d[i]);
    }

    for (i = 0; i < k; i++) {
        printf("\nEnter %c's routing table:\n", nam[i]);
        for (j = 0; j < n; j++) {
            scanf("%d", &ne[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            e[j] = ne[j][i] + d[j];
        }
        min(e, k, z, i);
    }

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
