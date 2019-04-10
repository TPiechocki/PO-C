//
// Created by Tomasz Piechocki on 28/03/19.
//


#include <iostream>
#include <algorithm>

#include "World.h"
#include "../Utils/OrgComp.h"

using namespace std;

//protectedt
bool World::makeCollision(Organism *organism) {
    bool status = false;
    Organism * new_org;

    Organism *other = board[organism->getX()][organism->getY()].getOrganism();
    if (other) {
        if (organism->getKindString() == other->getKindString()) {      // jeśli organizmy są takie same to się rozmnażają
            new_org = other->breed((Animal *)organism);
            if (new_org && new_org->getKind() != board[new_org->getX()][new_org->getY()].getOrganism()->getKind()) {
                board[new_org->getX()][new_org->getY()].getOrganism()->collision(new_org);
            }
        } else {     // dla zajętego pola przez organizm innego gatunku
            status = other->collision(organism);
        }
    } else {        // jeśli pole było puste
        board[organism->getX()][organism->getY()].setOrganism(organism);
    }

    // Jeśli poruszany obiekt przegrał lub poruszył się już wcześniej to elementy w wektorze przesuwają się o jeden
    return status;
}

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

    if (entities.size() > (size_x*size_y)+2) {
        throw std::runtime_error("Too many organisms in vector!!!");
    }

    /**
     *
     */
    if (board[org->getX()][org->getY()].getOrganism() == nullptr) {
        board[org->getX()][org->getY()].setOrganism(org);
    }
}

void World::removeOrganism(Organism *org) {
    int i;
    for (i = 0; i < entities.size(); i++) {
        if (entities[i] == org)
            break;
    }

    if (i < entities.size())
        entities.erase(entities.begin() + i);
}

void World::makeTurn() {
    std::sort(entities.begin(), entities.end(), OrgComp());

    renderer->clearMessages();
    clrscr();

    for(auto i : entities) {
        i->addOneAge();
    }

    int i = -1;
    while (++i < entities.size()  && entities[i]->getAge() > 0) {
        board[entities[i]->getX()][entities[i]->getY()].setNull();
        entities[i]->move();

        if (makeCollision(entities[i]))
            i--;
    }

    // clean lost organisms from vector
    /*
    for(auto i : entities) {
        if (i != board[i->getX()][i->getY()].getOrganism())
            removeOrganism(i);
    }*/
}

World::~World() {
    for (int i = 0; i < size_x; ++i) {
        delete[] board[i];
    }
    delete[] board;

    delete renderer;
}
