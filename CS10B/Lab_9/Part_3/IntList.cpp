#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &o, const IntList &rhs) {
   if(rhs.head == nullptr) {
      return o;
   }
   operator<<(o, rhs.head);
   return o;
}

ostream & operator<<(ostream &o, IntNode *rhs) {
   if(rhs == nullptr) {
      return o;
   }
   o << rhs->value;
   if(rhs->next != nullptr) {
      o << " ";
   }
   operator<<(o, rhs->next);
   return o;
}

bool IntList::exists(int i) const {
   if(head == nullptr) {
      return false;
   }
   if(head->value == i) {
      return true;
   }
   return exists(head->next, i);
}

bool IntList::exists(IntNode *rhs, int i) const {
   if(rhs == nullptr) {
      return false;
   }
   if(rhs->value == i) {
      return true;
   }
   return exists(rhs->next, i);
}




