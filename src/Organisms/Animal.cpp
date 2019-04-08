//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Animal.h"

Animal::Animal(int x, int y, World *world) : Organism(x, y, world) {
    previous_x = -1;
    previous_y = -1;  // TODO check for turtle (remember to check if positive)
}

void Animal::move() {
    previous_x = x_coord;
    previous_y = y_coord;

    randomDirection();

    switch (direction) {
        case KEY_UP:
            if (y_coord > 0)
                y_coord--;
            break;
        case KEY_DOWN:
            if (y_coord < world->getSizeY() - 1)
                y_coord++;
            break;
        case KEY_LEFT:
            if (x_coord > 0)
                x_coord--;
            break;
        case KEY_RIGHT:
            if (x_coord < world->getSizeX() - 1)
                x_coord++;
            break;
        default:
            if (x_coord < world->getSizeX() - 1)
                x_coord++;
    }
}

Animal::~Animal() = default;
