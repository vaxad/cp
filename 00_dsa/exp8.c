#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a graph
struct Graph {
    int vertices;
    int adjMatrix[MAX_SIZE][MAX_SIZE];
};

// Function to initialize the graph
void initGraph(struct Graph* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

#include <stdbool.h>

// Function to perform Breadth First Search (BFS)
void BFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_SIZE] = { false };
    int queue[MAX_SIZE];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS traversal: ");

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// Function to perform Depth First Search (DFS)
void DFSUtil(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_SIZE] = { false };

    printf("DFS traversal: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

int main() {
    struct Graph graph;
    int choice, vertices, src, dest, startVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    initGraph(&graph, vertices);

    while (1) {
        printf("\nGraph Traversal Menu\n");
        printf("1. Add an edge\n");
        printf("2. Perform Breadth First Search (BFS)\n");
        printf("3. Perform Depth First Search (DFS)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addEdge(&graph, src, dest);
                break;
            case 2:
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &startVertex);
                BFS(&graph, startVertex);
                break;
            case 3:
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &startVertex);
                DFS(&graph, startVertex);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
