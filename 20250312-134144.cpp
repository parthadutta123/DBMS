#include <iostream>
#define SIZE 5

using namespace std;

class CircularQueue {
private:
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        cout << "Inserted: " << value << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        int data = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();

    cout << "Dequeued: " << cq.dequeue() << endl;
    cq.enqueue(60);
    cq.display();

    return 0;
}


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// Function to insert a node at the end of the circular linked list
void insertEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;

    if (*head == nullptr) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to find the distance between two elements
int findDistance(Node* head, int key1, int key2) {
    if (!head) return -1;

    Node *temp = head, *node1 = nullptr, *node2 = nullptr;
    int index = 0, pos1 = -1, pos2 = -1;

    // Traverse the circular linked list to find both keys
    do {
        if (temp->data == key1) pos1 = index;
        if (temp->data == key2) pos2 = index;
        if (pos1 != -1 && pos2 != -1) break;
        temp = temp->next;
        index++;
    } while (temp != head);

    if (pos1 == -1 || pos2 == -1) return -1;  // One or both elements not found

    int distance1 = abs(pos2 - pos1);
    int distance2 = index - distance1;

    return min(distance1, distance2);
}

int main() {
    Node* head = nullptr;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    int key1 = 10, key2 = 40;
    int distance = findDistance(head, key1, key2);

    if (distance != -1)
        cout << "Distance between " << key1 << " and " << key2 << " is: " << distance << endl;
    else
        cout << "One or both elements not found in the list." << endl;

    return 0;
}
