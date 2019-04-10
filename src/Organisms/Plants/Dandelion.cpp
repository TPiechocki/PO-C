//
// Created by Tomasz Piechocki on 08/04/19.
//

#include "Dandelion.h"

Dandelion::Dandelion(int x, int y, World *world) : Plant(x, y, world) {
    strength = 0;
    kind = DANDELION;
}

char Dandelion::draw() {
    return 'M';
}

std::string Dandelion::getKindString() {
    return "Mlecz";
}

Plant *Dandelion::createNewInstance(int x, int y, World *world) {
    return new Dandelion(x, y, world);
}

void Dandelion::move() {
    for (int i = 0; i < 3; ++i)
        Plant::move();
}

Dandelion::~Dandelion() = default;


