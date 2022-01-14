#ifndef Elf_h
#define Elf_h

#include "Character.h"
#include <iostream>
using namespace std;

class Elf : public Character {
    private:
        string family;
    public:
        Elf(const string &, double, double, const string &);
        const string & getFamily() const;
        void attack(Character &);
};


#endif
