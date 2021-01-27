#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node
{

public:
    int value;
    Node *next;

    Node() : value(0), next(nullptr) {}
    Node(int val) : value(val), next(nullptr) {}
    Node(int val, Node *nextNode) : value(val), next(nextNode) {}
    int GetValue() { return value; }
};

class LinkedList
{
    Node *head = nullptr, *tail = nullptr;
    int count = 0;

public:
    LinkedList() {}

    ~LinkedList();

    int GetFrontValue();

    int GetTailValue();

    void AddNodeToFront(Node *node);

    void AddNodeToEnd(Node *node);

    void RemoveNode(int val);

    void RemoveFront();

    void RemoveEnd();

    void PrintList();

    int GetCount() { return count; }

    bool IsEmpty() { return count == 0; }

    void ClearLinkedList();
};

#endif