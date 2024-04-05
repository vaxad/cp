#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Queue
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }
    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Error: Queue is full\n";
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = x;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Error: Queue is empty\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }
    int Front()
    {
        if (front == -1)
        {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "QUEUE: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void printArr(int arr[100], int n)
{
    cout << "\nBLOCKS: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " --- ";
}
int main()
{
    int nb, np, block[100], process[100], hit = 0;
    Queue q;
    bool used[100] = {false};
    cout << "LRU: " << endl;
    cout << "enter number of blocks: ";
    cin >> nb;
    for (int i = 0; i < nb; i++)
    {
        block[i] = -1;
    }
    cout << "enter number of processes in stream: ";
    cin >> np;
    for (int i = 0; i < np; i++)
    {
        cout << "enter id of process " << i + 1 << ": ";
        cin >> process[i];
    }
    for (int i = 0; i < np; i++)
    {
        printArr(block, nb);
        q.print();
        cout << "INSERTING: " << process[i] << " --- ";
        for (int j = 0; j < nb; j++)
        {
            if (block[j] == process[i])
            {
                hit++;
                int arr[100], k = 0, l = 0;
                while (!q.isEmpty())
                {
                    if (q.Front() != j)
                    {
                        arr[k] = q.Front();
                        q.dequeue();
                        k++;
                    }
                    else
                    {
                        q.dequeue();
                    }
                }
                while (l < k)
                {
                    q.enqueue(arr[l]);
                    l++;
                }
                q.enqueue(j);
                cout << "(HIT!) --- ";
                q.print();
                break;
            }
            if (block[j] == -1)
            {
                block[j] = process[i];
                q.enqueue(j);
                cout << "(FAULT!)";
                break;
            }
            else if (j == nb - 1)
            {
                int oldestInd = q.Front();
                block[oldestInd] = process[i];
                q.enqueue(oldestInd);
                q.dequeue();
                cout << "(FAULT!)";
                break;
            }
        }
    }
    cout << endl << hit << " hits and " << np - hit << " faults\n";
    float ratio = (float)(hit) / (float)(np);
    cout << "hit ratio: " << ratio;
    return 0;
}