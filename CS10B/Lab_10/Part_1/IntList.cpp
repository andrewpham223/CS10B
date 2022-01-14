#include "IntList.h"

void IntList::distanceFrom(int key) {
   if(head == nullptr) {
      return;
   }
   else {
      this->searchAndModify(head, key);
   }
}


int IntList::searchAndModify(IntNode *curr, int key) {
   if(curr->data != key) {
      curr->data = 1 + searchAndModify(curr->next, key);
      return curr->data;
   }
   if(curr == nullptr) {
      curr->data = 1;
   }
   return 0;
}

