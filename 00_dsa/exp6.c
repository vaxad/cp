#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int data[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertFront(int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert element.\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }

    data[front] = value;
    printf("Element %d inserted at the front.\n", value);
}

void insertRear(, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert element.\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    data[rear] = value;
    printf("Element %d inserted at the rear.\n", value);
}

int deleteFront() {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete element.\n");
        return -1;
    }

    int value = data[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }

    printf("Element %d deleted from the front.\n", value);
    return value;
}

int deleteRear() {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete element.\n");
        return -1;
    }

    int value = data[rear];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }

    printf("Element %d deleted from the rear.\n", value);
    return value;
}

void displayDeque() {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", data[i]);
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
