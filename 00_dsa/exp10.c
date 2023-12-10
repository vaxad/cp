#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Structure for representing a hash table entry
struct HashNode {
    int key;
    int data;
    struct HashNode* next; // For separate chaining
};

// Structure for representing a hash table
struct HashTable {
    struct HashNode* table[SIZE]; // Array of pointers to HashNode
};

// Initialize the hash table
void initializeHashTable(struct HashTable* hashTable) {
    for (int i = 0; i < SIZE; i++) {
        hashTable->table[i] = NULL;
    }
}

// Hash function (simple modulo operation)
int hashFunction(int key) {
    return key % SIZE;
}

// Insert key and data into the hash table
void insert(struct HashTable* hashTable, int key, int data) {
    int index = hashFunction(key);

    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;

    // Separate chaining: handle collisions by chaining
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        struct HashNode* current = hashTable->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Inserted (%d, %d) at index %d\n", key, data, index);
}

// Search for a key in the hash table
void search(struct HashTable* hashTable, int key) {
    int index = hashFunction(key);

    struct HashNode* current = hashTable->table[index];

    while (current != NULL) {
        if (current->key == key) {
            printf("Key %d found at index %d with data %d\n", key, index, current->data);
            return;
        }
        current = current->next;
    }

    printf("Key %d not found in the hash table\n", key);
}

// Delete a key from the hash table
void delete(struct HashTable* hashTable, int key) {
    int index = hashFunction(key);

    struct HashNode* current = hashTable->table[index];
    struct HashNode* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                hashTable->table[index] = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Key %d deleted from index %d\n", key, index);        
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Key %d not found in the hash table\n", key);
}

// Display the hash table
void display(struct HashTable* hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        struct HashNode* current = hashTable->table[i];
        while (current != NULL) {
            printf("(%d, %d) -> ", current->key, current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashTable hashTable;
    initializeHashTable(&hashTable);

    int choice, key, data;

    do {
        printf("\nHashing Techniques Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Delete Element\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and data to insert: ");
                scanf("%d %d", &key, &data);
                insert(&hashTable, key, data);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(&hashTable, key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(&hashTable, key);
                break;
            case 4:
                display(&hashTable);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
