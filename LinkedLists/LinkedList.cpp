#include "LinkedList.h"
#include <iostream>

using namespace std;

int LinkedList::GetFrontValue()
{
    if (IsEmpty())
    {
        return -1;
    }
    return head->GetValue();
}

int LinkedList::GetTailValue()
{
    if (IsEmpty())
    {
        return -1;
    }
    return tail->GetValue();
}

void LinkedList::AddNodeToFront(Node *node)
{
    if (IsEmpty())
    {
        head = tail = node;
        count++;
        return;
    }

    node->next = head;
    head = node;
    count++;
    return;
}

void LinkedList::AddNodeToEnd(Node *node)
{
    if (IsEmpty())
    {
        head = tail = node;
        count++;
        return;
    }
    tail->next = node;
}

void LinkedList::RemoveNode(int val)
{
}

void LinkedList::RemoveFront()
{
}

void LinkedList::RemoveEnd()
{
}

void LinkedList::PrintList()
{
    if (IsEmpty())
    {
        cout << "List is empty" << endl;
    }
    auto node = head;
    while (node->next != nullptr)
    {
        cout << node->GetValue() << " ";
        node = node->next;
    }
    cout << node->GetValue() << " "<< endl;
}

void LinkedList::ClearLinkedList()
{
    while (!IsEmpty())
    {
        RemoveFront();
    }
}

LinkedList::~LinkedList()
{
    ClearLinkedList();
}