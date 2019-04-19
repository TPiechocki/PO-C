//
// Created by Tomasz Piechocki on 14/04/19.
//

#include "Tortoise.h"

Organism *Tortoise::createNewInstance(int x, int y, World *world) {
    return new Tortoise(x, y, world);
}

Tortoise::Tortoise(int x, int y, World *world) : Animal(x, y, world) {
    strength = 2;
    initiative = 1;
    kind = TORTOISE;
}

char Tortoise::draw() {
    return 'Z';
}

std::string Tortoise::getKindString() {
    return "Zolw";
}

void Tortoise::move() {
    if (rand() % 100 + 1 <= 25)
        Animal::move();
}

bool Tortoise::collision(Organism *attacker) {
    // Jeśli atakujący ma siłę mniejszą niż 5
    if (attacker->getStrength() < 5) {
        attacker->setPreviousXY();
        world->setOrganismOnBoard(attacker);

        std::string msg = this->getKindString() + " odparl atak " + attacker->getKindString();
        world->newMessage(msg);
        return false;
    } else      // dla pozostałych normalna kolizja
        return Organism::collision(attacker);
}

Tortoise::~Tortoise() = default;