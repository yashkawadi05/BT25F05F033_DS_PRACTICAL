#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Delete a node
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Element not found." << endl;
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    // Display the list
    void display() {
        Node* temp = head;

        cout << "Singly Linked List: ";

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;

    // Insert elements
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Original List:" << endl;
    list.display();

    // Delete an element
    list.deleteNode(30);

    cout << "After deleting 30:" << endl;
    list.display();

    return 0;
}
