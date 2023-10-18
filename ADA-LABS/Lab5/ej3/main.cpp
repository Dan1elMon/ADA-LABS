#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->data < right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

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

Node* mergesortRecursive(Node* head) {
    if (!head || !head->next) return head;

    Node* mid = findMiddle(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;

    left = mergesortRecursive(left);
    right = mergesortRecursive(right);

    return merge(left, right);
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);

    Node* sortedRecursive = mergesortRecursive(head);

    // imprime la lista ordenada
    cout << "Lista ordenada (iterativa): ";
    printList(sortedRecursive);

    return 0;
}
