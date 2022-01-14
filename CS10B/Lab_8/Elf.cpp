#include "Character.h"
#include "Elf.h"

#include <iostream>
using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &family) : Character(ELF, name, health, attackStrength), family(family)
{ }

const string & Elf::getFamily() const {
    return family;
}

void Elf::attack(Character &opponent)  {
    if(opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(opp.getFamily() == this->family) {
            cout << "Elf " << this->getName() << " does not attack Elf " << opponent.getName() << "." << endl;
            cout << "They are both members of the " << this->family << " family." << endl;
        }
        else {
            double damageAmount = this->health/MAX_HEALTH * attackStrength;
            opponent.damage(damageAmount);
            cout << "Elf " << this->getName() << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
            cout << opp.getName() << " takes " << damageAmount << " damage.\n";
        }
    }
    else {
        double damageAmount = this->health/MAX_HEALTH * attackStrength;
        opponent.damage(damageAmount);
        cout << "Elf " << this->getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << damageAmount << " damage.\n";
    }
}
