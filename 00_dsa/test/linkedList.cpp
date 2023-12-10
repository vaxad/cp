#include <iostream>

using namespace std;

// Define the Node struct
struct Node {
    int data;
    Node* next;
};

// Define the LinkedList class
class LinkedList {
public:
    LinkedList() {
        head = NULL;
    }

    // Add a node to the end of the list
    void addNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Remove a node from the list
    void removeNode(int data) {
        if (head == NULL) {
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
        cout<<"Node not found\n";
    }

    // Traverse the list and print each node's data
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    Node* head;
};

int main() {
    LinkedList list;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);

    list.printList();

    list.removeNode(2);
    list.removeNode(9);

    list.printList();

    return 0;
}
