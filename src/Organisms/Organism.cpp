//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Organism.h"

Organism::Organism() {
    strength = 0, initiative = 0, x_coord = 0, y_coord = 0, age = 0;
    world = nullptr;
}

char Organism::draw() {
    return 0;
}

int Organism::getX() const {
    return x_coord;
}

int Organism::getY() const {
    return y_coord;
}

Organism::~Organism() = default;
