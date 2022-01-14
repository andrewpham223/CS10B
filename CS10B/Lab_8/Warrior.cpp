#include "Character.h"
#include "Warrior.h"

#include <iostream>
using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, const string &allegiance) : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance)
{ }

const string & Warrior::getAllegiance() const {
    return allegiance;
}

void Warrior::attack(Character &opponent) {
    if(opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.getAllegiance() == this->allegiance) {
            cout << "Warrior " << this->getName() << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << this->allegiance << "." << endl;
        }
        else {
            double damageAmount = this->health/MAX_HEALTH * attackStrength;
            opponent.damage(damageAmount);
            cout << "Warrior " << this->getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << damageAmount << " damage." << endl;
        }
    }
    else {
        double damageAmount = this->health/MAX_HEALTH * attackStrength;
        opponent.damage(damageAmount);
        cout << "Warrior " << this->getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << damageAmount << " damage." << endl;
    }
}

