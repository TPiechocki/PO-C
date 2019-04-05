//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Animal.h"

// private
void Animal::randomDirection()  {
    int n = rand() % 4;
    switch (n) {
        case 0:
            direction  = KEY_UP;
            break;
        case 1:
            direction = KEY_DOWN;
            break;
        case 2:
            direction = KEY_LEFT;
            break;
        default:
            direction = KEY_RIGHT;
    }
}

// public
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
            break;case KEY_LEFT:
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