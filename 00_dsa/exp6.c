#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Deque;

void initDeque(Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isFull(Deque *deque) {
    return (deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1);
}

int isEmpty(Deque *deque) {
    return deque->front == -1;
}

void insertFront(Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert element.\n");
        return;
    }

    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front--;
    }

    deque->data[deque->front] = value;
    printf("Element %d inserted at the front.\n", value);
}

void insertRear(Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert element.\n");
        return;
    }

    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX_SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }

    deque->data[deque->rear] = value;
    printf("Element %d inserted at the rear.\n", value);
}

int deleteFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete element.\n");
        return -1;
    }

    int value = deque->data[deque->front];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == MAX_SIZE - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }

    printf("Element %d deleted from the front.\n", value);
    return value;
}

int deleteRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete element.\n");
        return -1;
    }

    int value = deque->data[deque->rear];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX_SIZE - 1;
    } else {
        deque->rear--;
    }

    printf("Element %d deleted from the rear.\n", value);
    return value;
}

void displayDeque(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = deque->front;
    while (i != deque->rear) {
        printf("%d ", deque->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", deque->data[i]);
}

int main() {
    Deque deque;
    initDeque(&deque);

    insertFront(&deque, 10);
    insertFront(&deque, 20);
    insertRear(&deque, 30);
    insertRear(&deque, 40);

    displayDeque(&deque);

    deleteFront(&deque);
    deleteRear(&deque);

    displayDeque(&deque);

    return 0;
}
