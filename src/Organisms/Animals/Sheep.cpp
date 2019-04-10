//
// Created by Tomasz Piechocki on 04/04/19.
//

#include "Sheep.h"

Sheep::Sheep(int x, int y, World* world) : Animal(x, y, world) {
    strength = 4;
    initiative = 4;
    kind = SHEEP;
}

char Sheep::draw() {
    return 'O';
}

std::string Sheep::getKindString() {
    return "Owca";
}

Organism *Sheep::createNewInstance(int x, int y, World *world) {
    return new Sheep(x, y, world);
}

Sheep::~Sheep() = default;
