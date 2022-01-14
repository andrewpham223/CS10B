//
//  main.cpp
//  Lab_6
//
//  Created by Andrew Pham on 11/2/21.
//
#include "IntVector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    IntVector testDefault;
    //Testing default constructor, capacity, size
    if(testDefault.capacity() != 0 || testDefault.size() != 0) {
        cout << "FAILED default constructor, capacity and size" << endl;
    }
    else{
        cout << "PASSED default constructor, capacity and size test" << endl;
    }
    //Testing .empty()
    if(testDefault.empty()) {
        cout << "PASSED .empty()" << endl;
    }
    else {
        cout << "FAILED .empty() test" << endl;
    }
    //Testing parameterized constructor
    IntVector testParam(3,5);
    if(testParam.capacity() != 3 || testParam.size() != 3) {
        cout << "FAILED parameterized constructor, capacity, or size" << endl;
    }
    else {
        cout << "PASSED parameterized constructor, capacity and size test" << endl;
    }
    //Testing .at() and parameterized constructor
    for(unsigned i = 0; i < testParam.size(); ++i) {
        if(testParam.at(i) != 5) {
            cout << "FAILED parameterized constructor and .at()" << endl;
        }
        else {
            cout << "PASSED parameterized constructor and .at()" << endl;
        }
    }
    
    //Testing invalid .at()
    //cout << testParam.at(5);
    
    //Testing front and back accessors
    if(testParam.front() != 5 && testParam.back() != 5) {
        cout << "FAILED .front() and .back()" << endl;
    }
    else {
        cout << "PASSED .front() and .back() test" << endl;
    }
    //Testing .empty() with parameters
    if(!testParam.empty()) {
        cout << "PASSED .empty()" << endl;
    }
    else {
        cout << "FAILED .empty()" << endl;
    }
    
    //Testing invalid .at()
    //cout << testParam.at(5);
}
