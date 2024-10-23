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

Algorithm for Depth First Search (DFS) in a Graph
Initialize Variables:

Declare v for the number of vertices.
Create a 2D array adj for the adjacency matrix.
Create an array visited to track visited vertices.
Input Graph:

Prompt the user for the number of vertices.
For each vertex, input the adjacency information to fill the adj matrix.
Initialize Visited Array:

Set all values in the visited array to 0.
Perform DFS:

For each vertex:
If it has not been visited, call the dfs function.
DFS Function (dfs(int k)):

Mark vertex k as visited.
Print the visited vertex.
For each adjacent vertex j:
If adj[k][j] is 1 (indicating an edge) and visited[j] is 0:
Recursively call dfs(j).
End:

Return control to the main function after completion.
