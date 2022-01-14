#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
	int value;
	IntNode *next;
	IntNode(int value) : value(value), next(nullptr) { }
};

class IntList {
	protected:
		IntNode *head;
		IntNode *tail;
	public:
		IntList();
		~IntList();
		void push_front(int);
		void pop_front();
		bool empty() const;
		const int & front() const;
		const int & back() const;
		friend ostream & operator<<(ostream &, const IntList &);
	public:
		IntList(const IntList &);
		IntList & operator=(const IntList &);
		void push_back(int);
		void clear();
		void selection_sort();
		void insert_ordered(int);
		void remove_duplicates();
	
	private:
		// Used by selection_sort function.
		// Just have this function return nullptr if you don't use this function. 
		IntNode * min(IntNode *);
		
		// Used by copy constructor and/or copy assignment operator.
		// Just implement an empty function if you don't use this function.
		void copy(const IntList &);

};

#endif
