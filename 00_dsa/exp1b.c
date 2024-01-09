#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = item;
    printf("%d enqueued to the queue.\n", item);
}

void dequeue() {
    if (front == -1 || front > rear) {
        front=-1;
        rear=-1;
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front]);
    front++;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
