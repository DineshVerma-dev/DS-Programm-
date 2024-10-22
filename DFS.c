#include <stdio.h>
#include <conio.h>

int v, adj[10][10], visited[10];
void dfs(int k);

void main() {
    int i, j;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &v);
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            printf("Is vertex %d adjacent to vertex %d? Enter 1 if yes and 0 if no: ", j + 1, i + 1);
            scanf("%d", &adj[i][j]);
        }
    }
    for (i = 0; i < v; i++) {
        visited[i] = 0;
    }
    printf("Depth First Search of the graph is as shown:\n");
    for (i = 0; i < v; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }
    getch();
}

void dfs(int k) {
    int j;
    visited[k] = 1;
    printf("%d ", k + 1);
    for (j = 0; j < v; j++) {
        if (adj[k][j] == 1 && visited[j] == 0) {
            dfs(j);
        }
    }
}
