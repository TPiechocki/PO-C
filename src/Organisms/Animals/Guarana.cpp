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

std::string Guarana::getKind() {
    return "Guarana";
}

bool Guarana::collision(Organism *attacker) {
    return Organism::collision(attacker);
}


Guarana::~Guarana() = default;