#include <iostream>

using namespace std;

// Define the node structure
struct Node {
    int data;
    Node* next;
};

// Define the stack class
class Stack {
    private:
        Node* top;
    public:
        Stack() {
            top = NULL;
        }
        void push(int x) {
            Node* temp = new Node;
            temp->data = x;
            temp->next = top;
            top = temp;
        }
        void pop() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        void display() {
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
    return 0;
}
