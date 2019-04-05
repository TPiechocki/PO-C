//
// Created by Tomasz Piechocki on 05/04/19.
//

#include "Wolf.h"

Wolf::Wolf(int x, int y, World* world) {
    strength = 9;
    initiative = 9;
    x_coord = x;
    y_coord = y;
    this->world = world;
    age = 0;
    kind = WOLF;
}

char Wolf::draw() {
    return 'W';
}

std::string Wolf::getGatunek() {
    return "Wilk";
}

Wolf::~Wolf() = default;