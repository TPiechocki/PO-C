//
// Created by Tomasz Piechocki on 28/03/19.
//


#include <iostream>

#include "World.h"

using namespace std;

// public
World::World(int x, int y)  : size_x(x),  size_y(y) {
    renderer = new Renderer(*this);
    board = new Field*[size_x];
    for (int i = 0; i < size_x; ++i) {
        board[i] = new Field[size_y];
    }
}

void World::addOrganism(Organism *org) {
    entities.push_back(org);
    board[org->getX()][org->getY()].setOrganism(org);
}

void World::makeTurn() {
    for (Organism* i : entities) {
        board[i->getX()][i->getY()].setNull();
        i->move();
        board[i->getX()][i->getY()].setOrganism(i);
    }
}

World::~World() {
    for (int i = 0; i < size_x; ++i) {
        delete[] board[i];
    }
    delete[] board;

    delete renderer;
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
