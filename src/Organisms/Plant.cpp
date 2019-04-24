//
// Created by Tomasz Piechocki on 07/04/19.
//

#include "Plant.h"

Plant::Plant(int x, int y, World *world) : Organism(x, y, world) {
    initiative = 0;
    scatter_possibility = 10;
}

void Plant::move() {
    if (rand() % 101 < scatter_possibility) {
        randomDirection();
        int x_temp = 0, y_temp = 0;
        switch (direction) {
            case KEY_UP:
                if (y_coord > 0)
                    y_temp--;
                break;
            case KEY_DOWN:
                if (y_coord < world->getSizeY() - 1)
                    y_temp++;
                break;case KEY_LEFT:
                if (x_coord > 0)
                    x_temp--;
                break;
            case KEY_RIGHT:
                if (x_coord < world->getSizeX() - 1)
                    x_temp++;
                break;
            default:
                if (x_coord < world->getSizeX() - 1)
                    x_temp++;
        }

        if (!(world->getOrganismFromBoard(x_coord+x_temp, y_coord+y_temp)) && (x_temp || y_temp)) {
            world->addOrganism(createNewInstance(x_coord+x_temp, y_coord+y_temp, world));

            std::string msg = this->getKindString() + ": Roslina sie rozprzestrzenila.";
            world->newMessage(msg);

        }
    }
}

Plant::~Plant() = default;