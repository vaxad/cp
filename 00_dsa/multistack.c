#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 3
#define MAX_SIZE 100

struct MultiStack {
    int data[MAX_SIZE];
    int top[MAX_STACKS];
};

struct MultiStack stacks;

void initialize() {
    for (int i = 0; i < MAX_STACKS; i++) {
        stacks.top[i] = i;
    }
}

void push(int stackNumber, int value) {
    if (stackNumber < 0 || stackNumber >= MAX_STACKS) {
        printf("Invalid stack number!\n");
        return;
    }

    if (stacks.top[stackNumber] >= MAX_SIZE) {
        printf("Stack %d is full. Cannot push %d.\n", stackNumber, value);
        return;
    }

    int index = stacks.top[stackNumber];
    stacks.data[index] = value;
    stacks.top[stackNumber] += MAX_STACKS;
    printf("%d pushed to Stack %d at %d index.\n", value, stackNumber, index);
}

void pop(int stackNumber) {
    if (stackNumber < 0 || stackNumber >= MAX_STACKS) {
        printf("Invalid stack number!\n");
        return;
    }

    if (stacks.top[stackNumber] <= stackNumber) {
        printf("Stack %d is empty. Cannot pop.\n", stackNumber);
        return;
    }

    stacks.top[stackNumber] -= MAX_STACKS;
    int index = stacks.top[stackNumber];
    int value = stacks.data[index];
    printf("%d popped from Stack %d.\n", value, stackNumber);
}

void display(int stackNumber) {
    if (stackNumber < 0 || stackNumber >= MAX_STACKS) {
        printf("Invalid stack number!\n");
        return;
    }

    printf("Stack %d elements: ", stackNumber);
    for (int i = stackNumber; i < MAX_SIZE; i += MAX_STACKS) {
        if (i >= stacks.top[stackNumber]) {
            break;
        }
        printf("%d ", stacks.data[i]);
    }
    printf("\n");
}

int main() {
    int choice, stackNumber, value;

    initialize();

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the stack number: ");
                scanf("%d", &stackNumber);
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(stackNumber, value);
                break;
            case 2:
                printf("Enter the stack number: ");
                scanf("%d", &stackNumber);
                pop(stackNumber);
                break;
            case 3:
                printf("Enter the stack number: ");
                scanf("%d", &stackNumber);
                display(stackNumber);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
