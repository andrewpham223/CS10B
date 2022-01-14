#ifndef Wizard_h
#define Wizard_h

#include "Character.h"
#include <iostream>
using namespace std;

class Wizard : public Character {
    private:
        int rank;
        
    public:
        Wizard(const string &, double, double, int);
        const int getRank() const;
        void attack(Character &);
};

#endif /* Wizard_h */
