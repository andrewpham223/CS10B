//
//  IntVector.cpp
//  Prog_Ass_4
//
//  Created by Andrew Pham on 11/2/21.
//

#include "IntVector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    _size = capacity;
    _capacity = capacity;
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

unsigned IntVector::size() const {
    return _size;
}

unsigned IntVector::capacity() const {
    return _capacity;
}

bool IntVector::empty() const {
    return(_size == 0);
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

IntVector::~IntVector() {
    delete[] _data;
}

void IntVector::expand() {
    if(_capacity == 0) {
        _capacity = 1;
    }
    else {_capacity = _capacity * 2;}
    int *newData = new int[_capacity];
    for(unsigned i = 0; i < _size; ++i) {
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
}

void IntVector::expand(unsigned amount) {
    _capacity = _capacity + amount;
    int *newData = new int[_capacity];
    for(unsigned i = 0; i < _size; ++i) {
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
}

void IntVector::insert(unsigned index, int value) {
    if(index > _size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    if (_size == _capacity){
        this->expand();
    }
    _size = _size+1;
    int *tempVector = new int[_capacity];
    for(unsigned i = 0; i < _size; ++i) {
        if(i < index) {
            tempVector[i] = _data[i];
        }
        else if(i == index) {
            tempVector[i] = value;
        }
        else if(i > index) {
            tempVector[i] = _data[i-1];
        }
    }
    delete[] _data;
    _data = tempVector;
} 

void IntVector::erase(unsigned index) {
    if(index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }
    int *tempVector = new int[_capacity];
    for(unsigned i = 0; i < _size; ++i) {
        if(i < index) {
            tempVector[i] = _data[i];
        }
        if(i > index) {
            tempVector[i-1] = _data[i];
        }
    }
    _size = _size-1;
    delete[] _data;
    _data = tempVector;
}

void IntVector::push_back(int value) {
    if(_capacity == 0) {
        _capacity++;
    }
    else if (_size+1 > _capacity){
        this->expand();
    }
    _size = _size + 1;
    int *tempVector = new int[_capacity];
    for(unsigned i = 0; i < _size; ++i) {
        if(i == _size-1) {
            tempVector[i] = value;
        }
        else {
            tempVector[i] = _data[i];
        }
    }
    delete[] _data;
    _data = tempVector;
}

void IntVector::pop_back() {
    _size = _size-1;   
}

void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned size, int value) {
    if(size < _size) {
        _size = size;
        int *tempVector = new int[_capacity];
        for(unsigned i = 0; i < _size; ++i) {
            tempVector[i] = _data[i]; 
        }
        delete[] _data;
        _data = tempVector;
    }
    if(size > _size) {
        unsigned oldSize = _size;
        if(size > _capacity) {
            if((size - _capacity +_capacity) > (_capacity * 2)) {
                this->expand(size - _capacity);
            }
            else{
                this->expand();
            }
        }
        _size = size;
        int *tempVector = new int[_capacity];
        for(unsigned i = 0; i < _size; ++i) {
            if(i < oldSize) {
                tempVector[i] = _data[i];
            }
            if(i >= oldSize) {
                tempVector[i] = value;
            }
        }
        delete[] _data;
        _data = tempVector;
    }
}

void IntVector::reserve(unsigned n) {
    if(n >= _capacity) {
        _capacity = n;
        int* tempVector = new int[_capacity];
        for(unsigned i = 0; i < _size; ++i) {
            tempVector[i] = _data[i];
        }
        delete[] _data;
        _data = tempVector;
    }
}

void IntVector::assign(unsigned n, int value) {
    if(n > _capacity) {
        if((n - _capacity +_capacity) > (_capacity * 2)) {
            this->expand(n - _capacity);
        }
        else{
            this->expand();
        }
    
    }
    _size = n;
    int* tempVector = new int[_capacity];
    for(unsigned i = 0; i < _size; ++i) {
        tempVector[i] = value;
    }
    delete[] _data;
    _data = tempVector;
}
int & IntVector::at(unsigned index) {
    if(index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}

int & IntVector::front() {
    return _data[0];
}

int & IntVector::back() {
    return _data[_size-1];
}