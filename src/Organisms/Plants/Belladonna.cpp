//
// Created by Tomasz Piechocki on 16/04/19.
//

#include "Belladonna.h"

Belladonna::Belladonna(int x, int y, World *world) : Plant(x, y, world) {
    strength = 99;
    kind = BELLADONNA;
}

Organism *Belladonna::createNewInstance(int x, int y, World *world) {
    return new Belladonna(x, y, world);
}

char Belladonna::draw() {
    return 'J';
}

std::string Belladonna::getKindString() {
    return "Wilcza jagoda";
}

bool Belladonna::collision(Organism *attacker) {
    std::string msg;

    msg = attacker->getKindString() + " zostal zatruty przez wilcza jagoda.";
    world->newMessage(msg);

    world->removeOrganism(attacker);
    world->setOrganismOnBoard(this);
    return true;
}