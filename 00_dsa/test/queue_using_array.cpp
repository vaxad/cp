#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Error: Queue is full\n";
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = x;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return;
        }
        else if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
    }
    int Front() {
        if (front == -1) {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    void print() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.print(); // Output: 1 2 3 4
    q.dequeue();
    q.dequeue();
    q.print(); // Output: 3 4
    cout << q.Front() << endl; // Output: 3
    return 0;
}
