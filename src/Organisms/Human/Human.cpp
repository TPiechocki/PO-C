//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Human.h"

Human::Human(int x, int y, World* world) : Animal(x, y, world) {
    strength = 5;
    initiative = 4;
    kind = HUMAN;
}

void Human::setDirection(int ch) {
    direction = ch;
}

char Human::draw() {
    return '*';
}

void Human::randomDirection() {
    // empty
}

std::string Human::getKindString() {
    return "Czlowiek";
}

Organism *Human::createNewInstance(int x, int y, World *world) {
    return new Human(x, y, world);
}

Human::~Human() = default;
