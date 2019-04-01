//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Animal.h"

void Animal::move() {
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