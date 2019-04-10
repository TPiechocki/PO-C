//
// Created by Tomasz Piechocki on 08/04/19.
//

#include "Guarana.h"

Guarana::Guarana(int x, int y, World *world) : Plant(x, y, world) {
    strength = 0;
}

Organism *Guarana::createNewInstance(int x, int y, World *world) {
    return new Guarana(x, y, world);
}

char Guarana::draw() {
    return 'G';
}

std::string Guarana::getKindString() {
    return "Guarana";
}

bool Guarana::collision(Organism *attacker) {
    std::string msg;

    msg = "Atakujacy " + attacker->getKindString() + " zjada " + this->getKindString() + ". Sila atakujacego wzrosla o 3.";
    world->newMessage(msg);

    world->removeOrganism(this);
    world->setOrganismOnBoard(attacker);
    attacker->changeStrength(3);

    return false;
}


Guarana::~Guarana() = default;