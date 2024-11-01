#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == MAX - 1) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
    }
}

int dequeue() {
    int item;
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        item = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return item;
    }
}

bool isEmpty() {
    return front == -1;
}

void bfs(int adjMatrix[MAX][MAX], int vertices, int startVertex) {
    int i, current;
    int visited[MAX] = {0};
    enqueue(startVertex);
    visited[startVertex] = 1;
    printf("Breadth First Search starting from vertex %d: ", startVertex);

    while (!isEmpty()) {
        current = dequeue();
        printf("%d ", current);
        for (i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int adjMatrix[MAX][MAX], int vertices, int current, int visited[MAX]) {
    int i;
    printf("%d ", current);
    visited[current] = 1;

    for (i = 0; i < vertices; i++) {
        if (!visited[i] && adjMatrix[current][i]) {
            dfs(adjMatrix, vertices, i, visited);
        }
    }
}

int main() {
    int vertices, i, j,adjMatrix[MAX][MAX],startVertex, visited[MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

   
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

   
    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);

    bfs(adjMatrix, vertices, startVertex);

    visited[MAX] = (0);
    printf("Depth First Search starting from vertex %d: ", startVertex);
    dfs(adjMatrix, vertices, startVertex, visited);
    printf("\n");

    return 0;
}

