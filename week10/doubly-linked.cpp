#include <iostream>
#include "doubly-linked.h"

List::List()
{
    first = nullptr;
}

List::~List() {}

// insert at the end of the list.
void List::insert(int n)
{
    Node *node = new Node{n, nullptr, nullptr};

    if (first == nullptr)
    {
        first = node;
        return;
    }

    // create a copy of the first node.
    Node *last = first;
    // traverse until we find the last node.
    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = node;
    node->prev = last;
}

// void List::insertFront(int n) {
// Node *node = new Node{n, nullptr, nullptr};
// node->next = first;

// if (first != nullptr)
// {
//     first->prev = node;
// }

// first = node;
// }

void List::reverse()
{
    if (first == nullptr)
    {
        return;
    }

    // make copies of first element.
    Node *head = first;
    Node *tail = first;

    // find the tail.
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    // loop until head and tail have both passed the middle values.
    while (head != tail && head->prev != tail)
    {
        // swap data
        int tmp = head->val;
        head->val = tail->val;
        tail->val = tmp;

        // lets advance the head and tail towards eachother
        head = head->next;
        tail = tail->prev;
    }
}

/*
// recursive reversing
Node *reverseR(Node *&n)
{
    if (n->next == nullptr)
    {
        Node *nn = n->next;
        n->next = n->prev;
        n->prev = nn;
        return n;
    }
    else
    {
        Node *nn = n->next;
        n->next = n->prev;
        n->prev = nn;

        return reverseR(n->prev);
    }
}

void List::reverse()
{
    first = reverseR(first);
}
*/

void List::print()
{
    if (first == nullptr)
    {
        return;
    }

    for (Node *n = first; n != nullptr; n = n->next)
    {
        std::cout << n->val << " ";
    }

    std::cout << std::endl;
}