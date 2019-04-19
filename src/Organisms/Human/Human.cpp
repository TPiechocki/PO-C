//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Human.h"

#include <string>

Human::Human(int x, int y, World* world) : Animal(x, y, world) {
    strength = 5;
    initiative = 4;
    immortalityEnd = -10;
    kind = HUMAN;
}

std::string Human::setDirection(int ch) {
    direction = ch;
    switch (ch) {
        case KEY_UP:
            return "Ustawiono kierunek w gore";
        case KEY_DOWN:
            return "Ustawiono kierunek w dol";
        case KEY_LEFT:
            return "Ustawiono kierunek w lewo";
        case KEY_RIGHT:
            return "Ustawiono kierunek w prawo";
        default:
            return "";
    }
}

void Human::activateImmortality() {
    if (immortalityEnd < age - 5) {
        immortalityEnd = age + 5;
        world->newPriorityMessage("Niesmiertelnosc aktywowana");
    } else if (immortalityEnd >= age) {
        world->newPriorityMessage("Niesmiertelnosc jeszcze aktywna przez " + std::to_string(immortalityEnd - age) + " tur.");
    } else {
        world->newPriorityMessage("Nie mozesz jeszcze aktywowac niesmiertelnosci. Mozliwe za " + std::to_string(immortalityEnd + 5 - age + 1) + " tur.");
    }
}

char Human::draw() {
    return '*';
}

void Human::randomDirection() {
    // empty
}

std::string Human::getKindString() {
    return "Czlowiek";
}

Organism *Human::createNewInstance(int x, int y, World *world) {
    return new Human(x, y, world);
}

bool Human::canBeKilled() {
    if (immortalityEnd >= age) {
        world->newMessage("Ale dzieki niesmiertelnosci czlowiek przezyl.");
        return false;
    }
    return true;
}

Human::~Human() = default;
