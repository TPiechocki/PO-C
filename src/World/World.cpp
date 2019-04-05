//
// Created by Tomasz Piechocki on 28/03/19.
//


#include <iostream>
#include <algorithm>

#include "World.h"
#include "../Organisms/Animals/Sheep.h"
#include "src/Utils/OrgComp.h"

using namespace std;

// public
World::World(int x, int y)  : size_x(x),  size_y(y) {
    renderer = new Renderer(*this);
    board = new Field*[size_x];
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

Organism* World::getOrganism(int x, int y) {
    return board[x][y].getOrganism();
}

Renderer *World::getRenderer() const {
    return renderer;
}

void World::newMessage(const std::string& msg) {
    renderer->newMessage(msg);
}

void World::addOrganism(Organism *org) {
    int i;
    for (i = 0; i < entities.size(); ++i) {
        if (entities[i]->getInitiative() < org->getInitiative())
            break;
    }

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
    
    int i = -1;
    while (++i < entities.size()) {
        printf("%c", entities[i]->draw());
        entities[i]->addOneAge();
        board[entities[i]->getX()][entities[i]->getY()].setNull();
        entities[i]->move();

        other = board[entities[i]->getX()][entities[i]->getY()].getOrganism();
        if (other != nullptr) {
            other = other->collision(entities[i]);
            board[other->getX()][other->getY()].setOrganism(other);
        } else
            board[entities[i]->getX()][entities[i]->getY()].setOrganism(entities[i]);
    }
}

World::~World() {
    for (int i = 0; i < size_x; ++i) {
        delete[] board[i];
    }
    delete[] board;

    delete renderer;
}
