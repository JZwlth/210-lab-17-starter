// COMSC-210 | Lab 17 | Zhaoyi Zheng
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Function prototypes
void output(Node *);
Node* addToFront(Node* head, float value);
Node* addToTail(Node* head, float value);
Node* deleteNode(Node* head, int position);
Node* insertNode(Node* head, int position, float value);
void deleteLinkedList(Node*& head);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// Function implementations
Node* addToFront(Node* head, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

Node* addToTail(Node* head, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        return newNode;
    }
    else {
        Node* current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
        return head;
    }
}

Node* deleteNode(Node* head, int position) {
    if (!head) return nullptr;

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    else {
        Node* current = head;
        Node* prev = nullptr;
        int count = 1;
        while (current && count < position) {
            prev = current;
            current = current->next;
            count++;
        }
        if (current) {
            prev->next = current->next;
            delete current;
        }
        return head;
    }
}

Node* insertNode(Node* head, int position, float value) {
    Node* newNode = new Node;
    newNode->value = value;

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    else {
        Node* current = head;
        Node* prev = nullptr;
        int count = 1;
        while (current && count < position) {
            prev = current;
            current = current->next;
            count++;
        }
        prev->next = newNode;
        newNode->next = current;
        return head;
    }
}

void deleteLinkedList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}