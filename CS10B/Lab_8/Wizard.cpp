#include "Character.h"
#include "Wizard.h"

#include <iostream>
using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength), rank(rank)
{ }

const int Wizard::getRank() const {
    return rank;
}

void Wizard::attack(Character &opponent) {
    if(opponent.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        opponent.damage(this->attackStrength * this->getRank()/opp.getRank());
        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!\n";
        cout << opponent.getName() << " takes " << this->attackStrength * this->getRank()/opp.getRank() << " damage." << endl;
    }
    else {
        opponent.damage(this->attackStrength);
        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!\n";
        cout << opponent.getName() << " takes " << this->attackStrength << " damage." << endl;
    }
}
