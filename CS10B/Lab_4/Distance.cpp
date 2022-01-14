#include "Distance.h"
#include <iostream>
using namespace std;

Distance::Distance() {
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    feet = ft;
    inches = in;
    this->init();
}

Distance::Distance(double in) {
    feet = 0;
    inches = in;
    this->init();
}

unsigned Distance::getFeet() const {
    return feet;
}

double Distance::getInches() const {
    return inches;
}

double Distance::distanceInInches() const {
    return inches + feet * 12.0;
}

double Distance::distanceInFeet() const {
    return feet + inches / 12.0;
}

double Distance::distanceInMeters() const {
    double totalInches = this->distanceInInches();
    return totalInches * 0.0254;
}

Distance Distance::operator+(const Distance &rhs) const{
    Distance d = Distance(this->feet + rhs.feet, this->inches + rhs.inches);
    d.init();
    return d;
}

Distance Distance::operator-(const Distance &rhs) const {
    double left = this->distanceInInches();
    double right = rhs.distanceInInches();
    double difference;
    if(left >= right) {
        difference = left - right;
    } 
    else {
        difference = right - left; 
    }
    Distance d = Distance(difference);
    d.init();
    
    return d;
}

ostream & operator<<(ostream &out, const Distance &rhs) {
    out << rhs.feet << "' " << rhs.inches << "\"";
    return out;
}

void Distance::init() {
    int extraFeet = 0;
    if(inches < 0) {
        inches = inches * -1;
    }
    while(inches >= 12) {
        extraFeet = inches / 12;
        feet += extraFeet;
        inches -= extraFeet * 12.0;
    }
}



