//
// Created by Tomasz Piechocki on 28/03/19.
//


#include <iostream>
#include <algorithm>

#include "World.h"
#include "../Utils/OrgComp.h"

#include "Organisms/Human/Human.h"
#include "Organisms/Animals/Sheep.h"
#include "Organisms/Animals/Wolf.h"
#include "Organisms/Animals/Fox.h"
#include "Organisms/Animals/Antelope.h"
#include "Organisms/Animals/Tortoise.h"
#include "Organisms/Plants/Grass.h"
#include "Organisms/Plants/Dandelion.h"
#include "Organisms/Plants/Guarana.h"
#include "Organisms/Plants/Belladonna.h"
#include "Organisms/Plants/Hogweed.h"

using namespace std;

// private
void World::randomOrganisms() {
    player = new Human(0, 0, this);
    addOrganism(player);
    addOrganism(new Sheep(0,10, this));
    addOrganism(new Sheep(0,11, this));
    addOrganism(new Wolf(0,5, this));
    addOrganism(new Fox(1,0, this));
    addOrganism(new Antelope(5, 5, this));
    addOrganism(new Antelope(8, 8, this));
    addOrganism(new Tortoise(1, 10, this));

    addOrganism(new Grass(19, 19, this));
    addOrganism(new Dandelion(0, 18, this));
    addOrganism(new Guarana(0, 1, this));
    addOrganism(new Belladonna(0,4, this));
    addOrganism(new Hogweed(10, 0, this));
}

// protected
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

    player = nullptr;
    randomOrganisms();
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

Human *World::getPlayer() const {
    return player;
}


void World::newMessage(const std::string &msg) {
    renderer->newMessage(msg);
}

void World::newPriorityMessage(const std::string &msg){
    renderer->newPriorityMessage(msg);
}

void World::addOrganism(Organism *org) {
    int i;
    for (i = 0; i < entities.size(); ++i) {
        if (entities[i]->getInitiative() < org->getInitiative())
            break;
    }

    entities.insert(entities.begin() + i, org);

    /*if (entities.size() > (size_x*size_y)+2) {
        throw std::runtime_error("Too many organisms in vector!!!");
    }*/

	if (org->getX() < 0 || org->getY() < 0) {
		cout << endl;
	}

    if (board[org->getX()][org->getY()].getOrganism() == nullptr) {
        board[org->getX()][org->getY()].setOrganism(org);
    }
}

void World::removeOrganism(Organism *org) {
    if (org->canBeKilled()) {
        // Usunięcie z planszy, jeśli organizm dalej tam jest
        if (board[org->getX()][org->getY()].getOrganism() == org) {
            board[org->getX()][org->getY()].setNull();
        }

        int i;
        for (i = 0; i < entities.size(); i++) {
            if (entities[i] == org) {
                break;
            }
        }

        if (i < entities.size())
            entities.erase(entities.begin() + i);

        free(org);
    } else {
        org->moveToSafe();
    }
}

void World::makeTurn() {
    std::sort(entities.begin(), entities.end(), OrgComp());

    Organism *temp = nullptr;

    renderer->clearMessages();

    for(auto i : entities) {
        i->addOneAge();
    }

    int i = -1;
    while (++i < entities.size()  && entities[i]->getAge() > 0) {
        board[entities[i]->getX()][entities[i]->getY()].setNull();

        temp = entities[i];
        temp->move();

        makeCollision(temp);

        // naprawa indeksu i, jeśli organizmy w wektorze się przesunęły, po czyjejś śmierci
		if (find(entities.begin(), entities.end(), temp) != entities.end()) {   // jeśli temp dalej żyje
			while (i > entities.size() || entities[i] < temp) {
				if (i == 0)
					break;
				i--;
			}
        } else {    // jeśli temp został zabity          
			--i;
        }

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
