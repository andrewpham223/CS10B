//
//  IntVector.cpp
//  Lab_6
//
//  Created by Andrew Pham on 11/2/21.
//

#include "IntVector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    _capacity = capacity;
    _size = capacity;
    if(_capacity > 0) {
        _data = new int[_capacity];
        for(unsigned i = 0; i < _size; ++i) {
            _data[i] = value;
        }
    }
    else {
        _data = nullptr;
    }
}

IntVector::~IntVector() {
    delete[] _data;
}

unsigned IntVector::size() const {
    return _size;
}

unsigned IntVector::capacity() const {
    return _capacity;
}

bool IntVector::empty() const {
    bool b = false;
    if(_size == 0) {
        b = true;
    }
    return b;
}

const int & IntVector::at(unsigned index) const {
    if(index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}

const int & IntVector::front() const {
    return _data[0];
}

const int & IntVector::back() const {
    return _data[_size-1];
}
