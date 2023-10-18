#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* findMiddle(Node* head) {
    if (!head) return nullptr;
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    Node dummy(0);
    Node* tail = &dummy;

    while (left && right) {
        if (left->data <= right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = left ? left : right;
    return dummy.next;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    int size = 1;
    Node dummy(0);
    dummy.next = head;

    while (true) {
        Node* cur = dummy.next;
        Node* tail = &dummy;
        while (cur) {
            Node* left = cur;
            Node* right = findMiddle(left);
            cur = findMiddle(right);
            tail->next = merge(left, right);

            while (tail->next) tail = tail->next;
        }
        size *= 2;
        if (!cur) break;
    }

    return dummy.next;
}

void printList(Node* head) {
    Node* current = head; // Creamos una copia del puntero head
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Crea una lista enlazada de ejemplo
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);

    // Versión iterativa
    Node* sortedIterative = mergeSort(head);

    // Imprime la lista ordenada
    cout << "Lista ordenada (iterativa): ";
    printList(sortedIterative);

    return 0;
}
