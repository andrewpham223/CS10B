#include "IntList.h"

#include <iostream>
using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    IntNode *current;
    while(head != nullptr) {
        current = head;
        head = head->next;
        delete current;
    }
}

void IntList::push_front(int value) {
    if(head == nullptr) {
        IntNode *newNode = new IntNode(value);
        newNode->value = value;
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
    }
    else {
        IntNode *newNode = new IntNode(value);
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }
}

void IntList::pop_front() {
    if(this->empty() == false) {
        IntNode *temp = head;
        head = head->next;
        delete temp;
    }
    if(this->empty()) {
        head = nullptr;
        tail = nullptr;
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

IntList::IntList(const IntList &cpy) {
    if(cpy.head == nullptr) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = new IntNode(cpy.head->value);
        IntNode *current = head;
        IntNode *cpyCurrent = cpy.head;
        while(cpyCurrent->next != nullptr) {
            current->next = new IntNode(cpyCurrent->next->value);
            cpyCurrent = cpyCurrent->next;
            current = current->next;
        }
        tail = current;
    }
}

IntList & IntList::operator=(const IntList &rhs) {
    if(this == &rhs) {
        return *this;
    }
    else {
        if(rhs.head == nullptr) {
            head = nullptr;
        }
        else {
            head = new IntNode(rhs.head->value);
            IntNode *current = head;
            IntNode *rhsCurrent = rhs.head;
            while(rhsCurrent->next != nullptr) {
                current->next = new IntNode(rhsCurrent->next->value);
                rhsCurrent = rhsCurrent->next;
                current = current->next;
            }
            tail = current;
        }
    }
    return *this;
}

void IntList::push_back(int value) {
    IntNode *newNode = new IntNode(value);
    if(head == nullptr)  {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void IntList::clear() {
    if(head != nullptr) {
        IntNode *current = head;
        IntNode *temp;
        while(current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }
        head = current;
        tail = current;
    }
}

void IntList::selection_sort() {
    if(head != nullptr) {
        IntNode *temp = head;
        IntNode *parser = temp;
        IntNode *minNode = temp;
        int min = head->value;
        while(temp->next != nullptr) {
            if(parser->value < min) {
                min = parser->value;
                minNode = parser;
            }
            parser = parser->next;
            if(parser->next == nullptr) {
                if(parser->value < min) {
                    min = parser->value;
                    minNode = parser;
                }
                minNode->value = temp->value;
                temp->value = min;
                temp = temp->next;
                parser = temp;
                min = temp->value;
                minNode = temp;
            }
        }
    }
}

void IntList::insert_ordered(int val) {
    if(head != nullptr) {
        if(val <= head->value) {
            this->push_front(val);
        }
        else if(val >= tail->value) {
            this->push_back(val);
        }
        else {
            IntNode *prev = head;
            IntNode *current = head->next;
            IntNode *newNode = new IntNode(val);
            while(current != nullptr) {
                if(newNode->value >= prev->value && newNode->value <= current->value) {
                    prev->next = newNode;
                    newNode->next = current;
                    break;
                }
                prev = prev->next;
                current = current->next;
            }
        }
    }
    if(head == nullptr) {
        this->push_front(val);
    }

}

void IntList::remove_duplicates() {

    for(IntNode *i = head; i != nullptr; i = i->next) {
        IntNode *copy = i;
        IntNode *prev = i;
        for(IntNode *curr = prev->next; curr != nullptr; curr = curr->next) {
            if(prev->next==tail && curr->value==copy->value) {
                prev->next = prev->next->next;
                delete curr;
                tail = prev;
            }
            else if(curr->value == copy->value) {
                prev->next = curr->next;
                delete curr;
                curr = prev;
            }
            else {
                prev = prev->next;
            }
        }
    }
}
