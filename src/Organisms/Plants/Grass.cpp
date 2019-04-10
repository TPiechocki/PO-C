//
// Created by Tomasz Piechocki on 07/04/19.
//

#include "Grass.h"

Grass::Grass(int x, int y, World *world) : Plant(x, y, world) {
    strength = 0;
    kind = GRASS;
}

char Grass::draw() {
    return 'T';
}

std::string Grass::getKindString() {
    return "Trawa";
}


Plant *Grass::createNewInstance(int x, int y, World *world) {
    return new Grass(x, y, world);
}

Grass::~Grass() = default;
