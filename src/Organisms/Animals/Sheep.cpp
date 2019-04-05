//
// Created by Tomasz Piechocki on 04/04/19.
//

#include "Sheep.h"

Sheep::Sheep(int x, int y, World* world) {
    strength = 4;
    initiative = 4;
    x_coord = x;
    y_coord = y;
    this->world = world;
    age = 0;
    kind = SHEEP;
}

char Sheep::draw() {
    return 'O';
}

std::string Sheep::getGatunek() {
    return "Owca";
}

Sheep::~Sheep() = default;
