#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert node at end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Bubble Sort for Linked List
void bubbleSort(Node* head) {
    if (head == nullptr) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap values
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    Node* head = nullptr;

    // Insert unsorted values
    insertAtEnd(head, 30);
    insertAtEnd(head, 10);
    insertAtEnd(head, 50);
    insertAtEnd(head, 20);
    insertAtEnd(head, 40);

    cout << "Original list: ";
    printList(head);

    bubbleSort(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
