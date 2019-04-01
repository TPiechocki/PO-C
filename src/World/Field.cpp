//
// Created by Tomasz Piechocki on 28/03/19.
//

#include "Field.h"

Field::Field() {
    organism = nullptr;
}

char Field::draw() const {
    if (!organism)
        return 'X';
    else
        return organism->draw();
}

void Field::setOrganism(Organism *org) {
    Field::organism = org;
}

void Field::setNull() {
    organism = nullptr;
}

Field::~Field() = default;