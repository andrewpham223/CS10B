#ifndef Warrior_h
#define Warrior_h

#include "Character.h"
#include <iostream>
using namespace std;

class Warrior : public Character {
    private:
        string allegiance;
        
    public:
        Warrior(const string &, double, double, const string &);
        const string & getAllegiance() const;
        void attack(Character &);
};

#endif
