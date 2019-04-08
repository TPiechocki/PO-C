//
// Created by Tomasz Piechocki on 28/03/19.
//


#include <iostream>
#include <algorithm>

#include "World.h"
#include "../Utils/OrgComp.h"

using namespace std;

// public
World::World(int x, int y) : size_x(x), size_y(y) {
    renderer = new Renderer(*this);
    board = new Field *[size_x];
    for (int i = 0; i < size_x; ++i) {
        board[i] = new Field[size_y];
    }
}

int World::getSizeX() const {
    return size_x;
}

int World::getSizeY() const {
    return size_y;
}

char World::getFieldChar(int x, int y) {
    return board[x][y].draw();
}

Organism *World::getOrganismFromBoard(int x, int y) {
    return board[x][y].getOrganism();
}

void World::setOrganismOnBoard(Organism *org) {
    board[org->getX()][org->getY()].setOrganism(org);
}

Renderer *World::getRenderer() const {
    return renderer;
}

void World::newMessage(const std::string &msg) {
    renderer->newMessage(msg);
}

void World::addOrganism(Organism *org) {
    int i;
    for (i = 0; i < entities.size(); ++i) {
        if (entities[i]->getInitiative() < org->getInitiative())
            break;
    }
    if (i<0)
        i = 0;

    entities.insert(entities.begin() + i, org);
    board[org->getX()][org->getY()].setOrganism(org);
}

void World::removeOrganism(Organism *org) {
    int i;
    for (i = 0; i < entities.size(); i++) {
        if (entities[i] == org)
            break;
    }

    entities.erase(entities.begin() + i);
}

void World::makeTurn() {
    Organism *other;
    clrscr();

    for(auto i : entities) {
        i->addOneAge();
    }

    int i = -1;
    while (++i < entities.size()  && entities[i]->getAge() > 0) {
        board[entities[i]->getX()][entities[i]->getY()].setNull();
        entities[i]->move();

        other = board[entities[i]->getX()][entities[i]->getY()].getOrganism();
        if (other) {
            bool status = other->collision(entities[i]);

            // Jeśli poruszany obiekt przegrał lub poruszył się już wcześniej to elementy w wektorze przesuwają się o jeden
            if (status)
                i--;
            if (other == entities[i])
                printf("%c %d\n", other->draw(), i);
        } else {
            board[entities[i]->getX()][entities[i]->getY()].setOrganism(entities[i]);
            printf("%c %d\n", entities[i]->draw(), i);
        }
    }
}

World::~World() {
    for (int i = 0; i < size_x; ++i) {
        delete[] board[i];
    }
    delete[] board;

    delete renderer;
}
