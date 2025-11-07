
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int adj[MAX][MAX];
int visited[MAX];
int n;
void createGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("BFS Traversal: ");
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
void DFS(int start) {
    int i;
    printf("%d ", start);
    visited[start] = 1;
    for (i = 0; i < n; i++) {
        if (adj[start][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}
int main() {
    int start, i;
    createGraph();
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    BFS(start);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");
    return 0;
}
