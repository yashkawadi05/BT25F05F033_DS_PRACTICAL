#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

// Insert a node at the end
void insert(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Display in forward direction
void displayForward() {
    Node* temp = head;

    cout << "Forward List: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Display in backward direction
void displayBackward() {
    Node* temp = tail;

    cout << "Backward List: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL" << endl;
}

int main() {
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter data for node " << i << ": ";
        cin >> value;

        insert(value);
    }

    displayForward();
    displayBackward();

    return 0;
}

