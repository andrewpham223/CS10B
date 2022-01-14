//
//  main.cpp
//  Prog_Ass_4
//
//  Created by Andrew Pham on 11/2/21.
//
#include "IntVector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    //Test constructor
    IntVector testDefault(0,0);

    //Test unsigned size() const for default constructor
    if(testDefault.size() == 0) {
        cout << "unsigned size() const passed for default constructor" << endl;
    }

    //Test unsigned capacity() const for default constructor
    if(testDefault.capacity() == 0) {
        cout << "unsigned capacity() const passed for default constructor" << endl;
    }

    //Test bool empty() const
    if(testDefault.empty()) {
        cout << "bool empty() const passed for default constructor" << endl;
    }

    //Test const int & at(unsigned index) with empty IntVector - should throw error
    //cout << testDefault.at(0);

    //Test const int & front() const with empty IntVector - should cause undefined behavior
    //cout << testDefault.front();

    //Test const int & front() const with empty IntVector - should cause undefined behavior
    //cout << testDefault.back();

    testDefault.insert(0,1);
    if(testDefault.at(0) == 1 && testDefault.size()==1 && testDefault.capacity() == 1) {
        cout << "void insert() passed test" << endl;
    }

    //Test void insert() for out of bounds 
    //testDefault.insert(1,1); 

    //Test void erase() for out of bounds
    //testDefault.erase(10);

    //Test void erase()
    testDefault.erase(0);
    if(testDefault.size() == 0 && testDefault.capacity() == 1) {
        cout << "void erase() passed test" << endl;
    }

    //Test void push_back()
    testDefault.push_back(1);
    testDefault.push_back(1);
    testDefault.push_back(1);
    if(testDefault.size() == 3 && testDefault.capacity() == 4) {
        cout << "void push_back() passed size and capacity test" << endl;
    }
    bool b = true;
    for(unsigned i = 0; i < testDefault.size(); ++i) {
        if(testDefault.at(i) != 1){
            b = false;
        }
    }
    if(b) {
        cout << "void push_back() passed value test" << endl;
    }

    //Test void pop_back()
    testDefault.pop_back();
    if(testDefault.size() == 2 && testDefault.capacity() == 4) {
        cout << "void pop_back() passed test" << endl;
    }

    //Test void resize() for reducing size
    testDefault.resize(1,0);
    if(testDefault.size() == 1 && testDefault.capacity() == 4) {
        cout << "void resize() passed test for reducing size" << endl;
    }

    //Test void resize() for increasing size correctly
    testDefault.resize(5, 1);
    if(testDefault.size() == 5 && testDefault.capacity() == 8) {
        cout << "void resize() passed test for increasing size" << endl;
    }

    //Test void resize() for adding correct values
    b = true;
    for(unsigned i = 0; i < testDefault.size(); ++i) {
        if(testDefault.at(i) != 1){
            b = false;
        }
    }
    if(b) {
        cout << "void resize() passed value test" << endl;
    }

    //Test void reserve() for attempting to lower capacity
    testDefault.reserve(1);
    if(testDefault.size() == 5 && testDefault.capacity() == 8) {
        cout << "void reserve() passed test for attempting to lower capacity" << endl;
    }
    
    //Test void reserve() for attempting to increase capacity
    testDefault.reserve(10);
    if(testDefault.size() == 5 && testDefault.capacity() == 10) {
        cout << "void reserve() passed test for attempting to increase capacity" << endl;
    }

    //Test assign() for size and capacity
    testDefault.assign(22, 1);
    if(testDefault.size() == 22 && testDefault.capacity() == 22) {
        cout << "void assign() passed test for size and capacity" << endl;
    }

    //Test assign for values
    b = true;
    for(unsigned i = 0; i < testDefault.size(); ++i) {
        if(testDefault.at(i) != 1){
            b = false;
        }
    }
    if(b) {
        cout << "void assign() passed value test" << endl;
    }

    //Test at() front() and back()
    if(testDefault.at(0) == 1 && testDefault.front() == 1 && testDefault.back() == 1) {
        cout << "at(), front() and back() passed tests" << endl;
    }

    //Finally, test clear()
    testDefault.clear();
    if(testDefault.size() == 0 && testDefault.capacity() == 22) {
        cout << "clear() passed tests" << endl;
    }

}

