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
            if (graph->adjMatrix[currentVertex][i]==1 && visited[i] != true) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_SIZE] = { false };
    int stack[MAX_SIZE];
    int top = 0;
    printf("BFS traversal: ");
    visited[startVertex] = true;
    int currentVertex = startVertex;
    while (top!=-1) {
        int newVertex=-1;
        printf("%d ", currentVertex);
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i]==1 && visited[i] != true) {
                visited[i] = true;
                stack[top++] = currentVertex;
                currentVertex=i;
                break;
            }
            if(i==graph->vertices-1){
                i=0;
                currentVertex=stack[top--];
            }
        }
    }
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
