//
// Created by Tomasz Piechocki on 05/04/19.
//

#include "Wolf.h"

Wolf::Wolf(int x, int y, World* world) : Animal(x, y, world) {
    strength = 9;
    initiative = 9;
    kind = WOLF;
}

char Wolf::draw() {
    return 'W';
}

std::string Wolf::getKind() {
    return "Wilk";
}

Organism *Wolf::createNewInstance(int x, int y, World *world) {
    return new Wolf(x, y, world);
}

Wolf::~Wolf() = default;