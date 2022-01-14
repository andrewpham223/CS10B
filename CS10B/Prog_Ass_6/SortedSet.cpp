#include "SortedSet.h"

#include <iostream>
using namespace std;

SortedSet::SortedSet() : IntList() { }

SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) { }

SortedSet::SortedSet(const IntList &cpy) : IntList(cpy) {
    this->remove_duplicates();
    this->selection_sort();
}

SortedSet::~SortedSet() { }

bool SortedSet::in(int val) const{
    bool flag = false;
    IntNode *temp = head;
    while(temp != nullptr) {
        if(temp->value == val) {
            flag = true;
        }
        temp = temp->next;
    }
    return flag;
}


SortedSet SortedSet::operator|(const SortedSet &rhs) const {
    SortedSet s;
    IntNode *temp = this->head;
    while(temp != nullptr) {
        s.add(temp->value);
        temp = temp->next;
    }
    temp = rhs.head;
    while(temp != nullptr) {
        s.add(temp->value);
        temp = temp->next;
    }
    return s;

}

SortedSet SortedSet::operator&(const SortedSet &rhs) const {
    SortedSet s;
    IntNode *temp = this->head;
    while(temp != nullptr) {
        if(this->in(temp->value) && rhs.in(temp->value)) {
            s.add(temp->value);
        }
        temp = temp->next;
    }
    return s;
}

void SortedSet::add(int value) {
    if(this->in(value) == false) {
        this->IntList::insert_ordered(value);
    }
}

void SortedSet::push_front(int value) {
    this->add(value);
}

void SortedSet::push_back(int value) {
    this->add(value);
}

void SortedSet::insert_ordered(int value) {
    this->add(value);
}

SortedSet SortedSet::operator|=(const SortedSet &rhs) {
    *this = *this | rhs;
    return *this;
}

SortedSet SortedSet::operator&=(const SortedSet &rhs) {
    *this = *this & rhs; 
    return *this;
}