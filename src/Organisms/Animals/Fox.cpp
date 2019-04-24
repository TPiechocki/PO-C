//
// Created by Tomasz Piechocki on 08/04/19.
//

#include "Fox.h"

Fox::Fox(int x, int y, World *world) : Animal(x, y, world) {
    initiative = 7;
    strength = 3;
    kind = FOX;
}

char Fox::draw() {
    return 'L';
}

std::string Fox::getKindString() {
    return "Lis";
}

Organism *Fox::createNewInstance(int x, int y, World *world) {
    return new Fox(x, y, world);
}

void Fox::move() {
    Animal::move();

    for (int i = 0; i < 4; ++i) {
        if (world->getOrganismFromBoard(x_coord, y_coord) == nullptr || world->getOrganismFromBoard(x_coord, y_coord)->getStrength() < this->strength)
            break;
        else {
            x_coord = previous_x;
            y_coord = previous_y;
        }

        if (i == 3)
            break;
        else {
            switch (direction) {
                case KEY_UP:
                    direction = KEY_DOWN;
                    if (y_coord < world->getSizeY() - 1)
                        y_coord++;
                    break;
                case KEY_DOWN:
                    direction = KEY_LEFT;
                    if (x_coord > 0)
                        x_coord--;
                    break;
                case KEY_LEFT:
                    direction = KEY_RIGHT;
                    if (x_coord < world->getSizeX() - 1)
                        x_coord++;
                    break;
                case KEY_RIGHT:
                    direction = KEY_UP;
                    if (y_coord > 0)
                        y_coord--;
                    break;
                default:
                    break;
            }
        }
    }
}