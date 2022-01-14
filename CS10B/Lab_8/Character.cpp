#include "Character.h"

#include <string>
#include <iostream>

Character::Character(HeroType _type, const string &_name, double _health, double _attackStrength) : type(_type), name(_name), health(_health), attackStrength(_attackStrength)
{ }

HeroType Character::getType() const {
    return type;
}

const string & Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return static_cast<int>(health);
}

void Character::damage(double d) {
    health -= d;
}

bool Character::isAlive() const {
    return(this->getHealth() > 0);
}
