//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Organism.h"
#include "../Utils/OrgComp.h"

//protected
void Organism::randomDirection()  {
    int n = rand() % 4;
    switch (n) {
        case 0:
            direction  = KEY_UP;
            break;
        case 1:
            direction = KEY_DOWN;
            break;
        case 2:
            direction = KEY_LEFT;
            break;
        default:
            direction = KEY_RIGHT;
    }
}

// public
Organism::Organism(int x, int y, World *world){
    direction = KEY_RIGHT;
    x_coord = x;
    y_coord = y;
    this->world = world;
    age = 0;
}

bool Organism::operator<(const Organism &rhs) const {
    if (initiative < rhs.initiative)
        return true;
    if (rhs.initiative < initiative)
        return false;
    return age < rhs.age;
}

bool Organism::operator>(const Organism &rhs) const {
    return rhs < *this;
}

bool Organism::operator<=(const Organism &rhs) const {
    return !(rhs < *this);
}

bool Organism::operator>=(const Organism &rhs) const {
    return !(*this < rhs);
}

void Organism::setPreviousXY() {
    x_coord = previous_x;
    y_coord = previous_y;
}


void Organism::addOneAge() {
 age++;
}

void Organism::changeStrength(int i) {
    strength += i;
}


int Organism::getX() const {
    return x_coord;
}

int Organism::getY() const {
    return y_coord;
}

int Organism::getInitiative() const {
    return initiative;
}

int Organism::getAge() const {
    return age;
}

int Organism::getStrength() const {
    return strength;
}
Kind Organism::getKind() {
    return kind;
}

bool Organism::collision(Organism *attacker) {
    std::string msg;
    bool status = attacker >= this;

    if (attacker->strength < this->strength) {
        msg = "Broniacy sie " + this->getKindString() + " zabija " + attacker->getKindString();
        world->newMessage(msg);

        world->removeOrganism(attacker);
        world->setOrganismOnBoard(this);
        return true;
    } else {      // jeśli siła równa dla obu to wygrywa atakujący
        msg = "Atakujacy " + attacker->getKindString() + " zabija " + this->getKindString();
        world->newMessage(msg);

        world->removeOrganism(this);
        world->setOrganismOnBoard(attacker);
        return status;
    }
}

Organism *Organism::breed(Animal *) {
    return nullptr;
}

bool Organism::canBeKilled() {
    return true;
}

Organism::~Organism() = default;
