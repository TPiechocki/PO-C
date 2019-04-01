//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Human.h"

Human::Human(int x, int y, World* world) {
    strength = 5;
    initiative = 4;
    x_coord = x;
    y_coord = y;
    this->world = world;
    age = 0;
}

void Human::setDirection(int ch) {
    direction = ch;
}

void Human::collision() {

}

char Human::draw() {
    return '*';
}

Human::~Human() = default;
