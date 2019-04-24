//
// Created by Tomek on 17/04/2019.
//

#include "Hogweed.h"

// pirvate
void Hogweed::killNeighbour(Organism *temp) {
    if (temp && temp->getKind() != this->getKind()) {
        std::string msg = temp->getKindString() + " zostal zatruty przez barszcz sosnowskiego.";
        world->newMessage(msg);

        world->removeOrganism(temp);
    }
}

// rest
Organism *Hogweed::createNewInstance(int x, int y, World *world) {
    return new Hogweed(x, y, world);
}

Hogweed::Hogweed(int x, int y, World *world) : Plant(x, y, world) {
    strength = 10;
    kind = HOGWEED;
}

char Hogweed::draw() {
    return 'B';
}

std::string Hogweed::getKindString() {
    return "Barszcz sosnowskiego";
}

void Hogweed::move() {
    if (x_coord > 0)
        killNeighbour(world->getOrganismFromBoard(x_coord - 1, y_coord));
    if (x_coord < world->getSizeX() - 1)
        killNeighbour(world->getOrganismFromBoard(x_coord + 1, y_coord));
    if (y_coord > 0)
        killNeighbour(world->getOrganismFromBoard(x_coord, y_coord - 1));
    if (y_coord < world->getSizeY() - 1)
        killNeighbour(world->getOrganismFromBoard(x_coord, y_coord + 1));

    Plant::move();
}

bool Hogweed::collision(Organism *attacker) {
    std::string msg;

    msg = attacker->getKindString() + " zostal zatruty przez barszcz sosnowskiego.";
    world->newMessage(msg);

    world->removeOrganism(attacker);
    world->setOrganismOnBoard(this);
    return true;
}