#include <iostream>
using namespace std;

#define MAX_SIZE 1000

class Stack {
    int top;
public:
    int arr[MAX_SIZE];

    Stack() {
        top = -1;
    }

    bool push(int x) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    cout << "Elements present in stack : ";
    while (!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
