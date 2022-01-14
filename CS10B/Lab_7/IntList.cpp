#include "IntList.h"

#include <iostream>
using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    IntNode *curr;
    while(head != nullptr) {
        curr = head;
        head = head->next;
        delete curr;
    }
}

void IntList::push_front(int value) {
    IntNode *newNode = new IntNode(value);
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void IntList::pop_front() {
    if(this->empty() == false) {
        head = head->next;
    }
}

bool IntList::empty() const {
    return (head == nullptr);
}

const int & IntList::front() const {
    return head->value;
}

const int & IntList::back() const {
    return tail->value;
}

ostream &operator<<(ostream &o, const IntList &list) {
    IntNode *temp = list.head;
    while(temp != nullptr) {
        if(temp->next != nullptr) {
            o << temp->value << " ";
        }
        else {
            o << temp->value;
        }
        temp = temp->next;
    }
    return o;
}

