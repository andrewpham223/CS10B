//
//  main.cpp
//  Programming Assignment 1 - Calculating Coefficient of Lift
//
//  Created by Andrew Pham on 10/4/21.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector <double> &);
double interpolation(double, const vector<double> &, const vector<double> &);

int main(int argc, char *argv[]) {
    string filename;
    vector<double> angles;
    vector<double> lifts;
    double userAngle;
    double userCoefficient = 0;
    string userWord = "";
    
    
    filename = argv[1];
    readData(filename, angles, lifts);
    reorder(angles, lifts);
    
    cout << "Input a flight-path angle: ";
    cin >> userAngle;
    cout << endl;
    
    while(userAngle < angles.at(0) || userAngle > angles.at(angles.size() - 1)) {
        cout << "Invalid angle for given data set. Input a new flight-path angle: ";
        cin >> userAngle;
        cout << endl;
    }
    
    userCoefficient = interpolation(userAngle, angles, lifts);
    
    cout << "The coefficient of lift for angle " << userAngle << " is " << userCoefficient;
    cout << endl;
    
    cout << "Do you want to enter another flight-path angle? ";
    cin >> userWord;
    cout << endl;
    if(userWord == "No") {
        return 0;
    }
    
    while(userWord == "Yes") {
        cout << "Input a flight-path angle: ";
        cin >> userAngle;
        cout << endl;
        
        while(userAngle < angles.at(0) || userAngle > angles.at(angles.size() - 1)) {
            cout << "Invalid angle for given data set. Input a new flight-path angle: ";
            cin >> userAngle;
            cout << endl;
        }
        
        userCoefficient = interpolation(userAngle, angles, lifts);
        
        cout << "The coefficient of lift for angle " << userAngle << " is " << userCoefficient;
        cout << endl;
        
        cout << "Do you want to enter another flight-path angle? ";
        cin >> userWord;
        cout << endl;
        if(userWord == "No") {
            return 0;
        }
    }
    
    return 0;
}

void readData(const string &filename, vector<double> &angles, vector <double> &lifts) {
    ifstream inFS;
    double angle, lift;
    inFS.open(filename);
    if(!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    while(inFS >> angle >> lift) {
        angles.push_back(angle);
        lifts.push_back(lift);
    }
    inFS.close();
}

bool isOrdered(const vector<double> &angles) {
    bool orderedOrNot = true;
    if(angles.size() > 1) {
        for(unsigned i = 0; i < angles.size()-1; ++i) {
            if(angles.at(i) > angles.at(i+1)) {
                orderedOrNot = false;
            }
        }
    }
    return orderedOrNot;
}

void reorder(vector<double> &angles, vector<double> &lifts) {
    double tempAngles;
    double tempLifts;
    while(!isOrdered(angles)) {
        for(unsigned i = 0; i < angles.size()-1; ++i) {
            if(angles.at(i) > angles.at(i+1)) {
                tempAngles = angles.at(i);
                angles.at(i) = angles.at(i+1);
                angles.at(i+1) = tempAngles;
                
                tempLifts = lifts.at(i);
                lifts.at(i) = lifts.at(i+1);
                lifts.at(i+1) = tempLifts;
            }
        }
    }
}

double interpolation(double userAngle, const vector<double> &angles, const vector<double> &lifts) {
    int upperIndex = -1;
    int lowerIndex = -1;
    int sameIndex = 0;
    double liftCoefficient;
    for(unsigned i = 0; i < angles.size(); ++i) {
        if(userAngle == angles.at(i)) {
            sameIndex = i;
            break;
        }
        if(userAngle < angles.at(i)) {
            upperIndex = i;
            lowerIndex = i-1;
            break;
        }
        
    }
    if(upperIndex == -1 && lowerIndex == -1) {
        liftCoefficient = lifts.at(sameIndex);
    }
    else {
        liftCoefficient = lifts.at(lowerIndex) + (((userAngle - angles.at(lowerIndex))/(angles.at(upperIndex) - angles.at(lowerIndex)))*(lifts.at(upperIndex)-lifts.at(lowerIndex)));
    }
    return liftCoefficient;
}
