//COMSC-210 | Lab 17 | Annie Morales
// IDE used: Visual Studio Code

// This modified program will leverage functions to peform these linked list operations:
// adding a node to the front; adding a node to the tail; deleting a node' inserting a node;
// and deleting the entire linked list.

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node 
{
    float value;
    Node *next;
};

void output(Node *);

// Function prototypes
void addToFront(Node *&, float);
void addToTail(Node *&, float);
void deleteNode(Node *&, float);
void insertNode(Node *&, float);
void deleteList(Node *&);

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

    // Adds a node to the front of the list
    cout << "Enter a value to add to the front of the list: ";
    float frontValue;
    cin >> frontValue;
    addToFront(head, frontValue);
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

// Function to add a node to the front of the list
void addToFront(Node *&head, float value) 
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

// Function to add a node to the tail of the list
void addToTail(Node *&head, float value) 
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a node
void deleteNode(Node *&head, float value) 
{
    if (!head) return;
    if (head->value == value) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *current = head;
    Node *prev = nullptr;
    while (current && current->value != value) {
        prev = current;
        current = current->next;
    }
    if (current) {
        prev->next = current->next;
        delete current;
    }
}

// Function to insert a node
void insertNode(Node *&head, float value) 
{
    Node *newNode = new Node;
    newNode->value = value;
    if (!head) {
        newNode->next = nullptr;
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = nullptr;
}

// Function to delete the entire linked list
void deleteList(Node *&head) 
{
    Node *current = head;
    while (current) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}