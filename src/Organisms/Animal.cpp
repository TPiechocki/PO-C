//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Animal.h"

#include "../World/World.h"

Animal::Animal(int x, int y, World *world) : Organism(x, y, world) {
    previous_x = x;
    previous_y = y;
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


Organism *Animal::breed(Animal *other) {
    Organism *new_org = nullptr;

    std::string msg;
    other->x_coord = other->previous_x;
    other->y_coord = other->previous_y;

    world->setOrganismOnBoard(other);

    if (this->age <= 0)
        return nullptr;

    int x_new = this->x_coord, y_new = this->y_coord, status = 0;
    this->randomDirection();
    do {
        switch (this->direction) {
            case KEY_UP:
                if (y_new > 0)
                    y_new--;
                else {
                    y_new = this->y_coord;
                    this->direction = KEY_DOWN;
                    status++;
                }
                break;
            case KEY_DOWN:
                if (y_new < world->getSizeY() - 1)
                    y_new++;
                else {
                    y_new = this->y_coord;
                    this->direction = KEY_LEFT;
                    status++;
                }
                break;
            case KEY_LEFT:
                if (x_new > 0)
                    x_new--;
                else {
                    x_new = this->x_coord;
                    this->direction = KEY_RIGHT;
                    status++;
                }
                break;
            case KEY_RIGHT:
                if (x_new < world->getSizeX() - 1)
                    x_new++;
                else {
                    x_new = this->x_coord;
                    this->direction = KEY_UP;
                    status++;
                }
                break;
            default:
                break;
        }
    } while (world->getOrganismFromBoard(x_new, y_new) &&
            world->getOrganismFromBoard(x_new, y_new)->getKind() == this->getKind() && status <= 4);

    if (status <=4) {
        msg = "Zwierze " + this->getKindString() + " sie rozmnozylo.";
        world->newMessage(msg);

        new_org = createNewInstance(x_new, y_new, world);
        world->addOrganism(new_org);
    }
    return new_org;

}

void Animal::moveToSafe() {
    previous_x  = x_coord;
    previous_y = y_coord;

    this->Animal::randomDirection();
    for (int i = 0; i < 4; ++i) {
        if (world->getOrganismFromBoard(x_coord, y_coord) == nullptr) {
            world->setOrganismOnBoard(this);
            break;
        } else {
            x_coord = previous_x;
            y_coord = previous_y;
        }

        {
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
    if (world->getOrganismFromBoard(x_coord, y_coord) == nullptr)
        world->setOrganismOnBoard(this);
}

Animal::~Animal() = default;