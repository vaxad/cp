#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define the structure of the linked list
struct LinkedList {
    struct Node* head;
    int size;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a new linked list
struct LinkedList* createLinkedList() {
    struct LinkedList* newList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Function to add a node to the end of the linked list
void addNode(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

// Function to insert a node at the given index in the linked list
void insertNode(struct LinkedList* list, int data, int index) {
    if (index < 0 || index > list->size) {
        printf("Error: Index out of range\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

// Function to remove a node at the given index in the linked list
void removeNode(struct LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Error: Index out of range\n");
        return;
    }
    struct Node* current = list->head;
    if (index == 0) {
        list->head = current->next;
    } else {
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        current->next = current->next->next;
    }
    free(current->next);
    list->size--;
}

// Function to print the linked list
void printList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by the linked list
void freeList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    // Create a new linked list
    struct LinkedList* list = createLinkedList();

    // Add some nodes to the linked list
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);

    // Insert a node at index 1
    insertNode(list, 4, 1);

    // Remove the node at index 2
    removeNode(list, 2);

    // Print the linked list
    printList(list);

    // Free the memory used by the linked list
    freeList(list);

    return 0;
}