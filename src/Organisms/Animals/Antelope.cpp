//
// Created by Tomasz Piechocki on 14/04/19.
//

#include "Antelope.h"

Antelope::Antelope(int x, int y, World *world) : Animal(x, y, world) {
    strength = 4;
    initiative = 4;
    kind = ANTELOPE;
}

char Antelope::draw() {
    return 'A';
}

std::string Antelope::getKindString() {
    return "Antylopa";
}

Organism *Antelope::createNewInstance(int x, int y, World *world) {
    return new Antelope(x, y, world);
}

void Antelope::move() {
    previous_x = x_coord;
    previous_y = y_coord;

    randomDirection();

    for (int i = 0; i < 2; ++i) {
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
}

bool Antelope::collision(Organism *attacker) {
    if ((rand() % 100 + 1) <= 50) {
        return Organism::collision(attacker);
    } else {    // ucieczka
        world->setOrganismOnBoard(attacker);
        Animal::move();

        this->moveToSafe();

        std::string msg = this->getKindString() + " uciekla przed " + attacker->getKindString();
        world->newMessage(msg);

        return false;
    }
}