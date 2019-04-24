//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Organism.h"
#include "../Utils/OrgComp.h"

using namespace std;

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

		world->setOrganismOnBoard(this);
        world->removeOrganism(attacker);

        return true;
    } else {      // jeśli siła równa dla obu to wygrywa atakujący
        msg = "Atakujacy " + attacker->getKindString() + " zabija " + this->getKindString();
        world->newMessage(msg);

		world->setOrganismOnBoard(attacker);
        world->removeOrganism(this);

        return status;
    }
}

Organism *Organism::breed(Animal *) {
    return nullptr;
}

bool Organism::canBeKilled() {
    return true;
}

void Organism::Serialise(fstream &file, bool write) {
    if (write) {
        file.write(reinterpret_cast<const char *>(&x_coord), sizeof(x_coord));
        file.write(reinterpret_cast<const char *>(&y_coord), sizeof(y_coord));
        file.write(reinterpret_cast<const char *>(&previous_x), sizeof(previous_x));
        file.write(reinterpret_cast<const char *>(&previous_y), sizeof(previous_y));
        file.write(reinterpret_cast<const char *>(&age), sizeof(age));
        file.write(reinterpret_cast<const char *>(&strength), sizeof(strength));
    } else {
        file.read(reinterpret_cast<char *>(&x_coord), sizeof(x_coord));
        file.read(reinterpret_cast<char *>(&y_coord), sizeof(y_coord));
        file.read(reinterpret_cast<char *>(&previous_x), sizeof(previous_x));
        file.read(reinterpret_cast<char *>(&previous_y), sizeof(previous_y));
        file.read(reinterpret_cast<char *>(&age), sizeof(age));
        file.read(reinterpret_cast<char *>(&strength), sizeof(strength));
    }
}

void Organism::setWorld(World *world) {
    Organism::world = world;
}

Organism::~Organism() = default;