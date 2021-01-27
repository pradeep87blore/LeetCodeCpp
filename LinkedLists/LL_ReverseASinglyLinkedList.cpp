/*

https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

#include "LinkedList.cpp"
#include <iostream>

using namespace std;

typedef Node ListNode;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(head == nullptr)
            return nullptr; // The List is empty

        if(head->next == nullptr) // Single node, so reversed list same as normal list
            return head;

        
    }
};

int main()
{
    LinkedList list;
    list.AddNodeToFront(new Node(10));
    list.AddNodeToFront(new Node(20));
    list.AddNodeToFront(new Node(30));
    list.AddNodeToFront(new Node(40));
    list.AddNodeToFront(new Node(50));
    auto newHeadNode = new Node(60); // Just to get the new head node since the head node in the LinkedList class is private :)
    list.AddNodeToFront(newHeadNode);

    list.PrintList();

    Solution sln;
    auto reversedList = sln.reverseList(newHeadNode);


}
