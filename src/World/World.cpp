//
// Created by Tomasz Piechocki on 28/03/19.
//


#include <iostream>
#include <algorithm>

#include "World.h"
#include "../Utils/OrgComp.h"

#include "../Organisms/Human/Human.h"
#include "../Organisms/Animals/Sheep.h"
#include "../Organisms/Animals/Wolf.h"
#include "../Organisms/Animals/Fox.h"
#include "../Organisms/Animals/Antelope.h"
#include "../Organisms/Animals/Tortoise.h"
#include "../Organisms/Plants/Grass.h"
#include "../Organisms/Plants/Dandelion.h"
#include "../Organisms/Plants/Guarana.h"
#include "../Organisms/Plants/Belladonna.h"
#include "../Organisms/Plants/Hogweed.h"

using namespace std;

// private
int World::randomX() {
    return rand() % size_x;
}

int World::randomY() {
    return rand() % size_y;
}

void World::randomOrganisms() {
    int rate, limit, x, y;

    player = new Human(randomX(), randomY(), this);
    addOrganism(player);

    // Owce z prawdopobieństwem 2-4 sztuk na 200 pól (dla 0-199 pól 2-4 sztuki, dla 200-399 pól 4-8 sztuk itd.)
    rate = 1 + (size_x * size_y)/200;
    limit = rand() % 3*rate + 2*rate;
    for (int i = 0; i < limit; ++i) {
        do {
            x = randomX();
            y = randomY();
        } while (getOrganismFromBoard(x, y) != nullptr);
        addOrganism(new Sheep(x, y, this));
    }

    // Wilk - 2-3 na 400 pól (0-399 - 2-3; 400-799 - 4-6 itd.)
    rate = 1 + (size_x * size_y)/400;
    limit = rand() % 2*rate + 2*rate;
    for (int i = 0; i < limit; ++i) {
        do {
            x = randomX();
            y = randomY();
        } while (getOrganismFromBoard(x, y) != nullptr);
        addOrganism(new Wolf(x, y, this));
    }

    // Lis - 2-4 na 300 pól (0-299 - 2-4; 300-599 - 4-8 itd.)
    rate = 1 + (size_x * size_y)/300;
    limit = rand() % 3*rate + 2*rate;
    for (int i = 0; i < limit; ++i) {
        do {
            x = randomX();
            y = randomY();
        } while (getOrganismFromBoard(x, y) != nullptr);
        addOrganism(new Fox(x, y, this));
    }

    // Zolw - 2-3 na 500 pól (0-499 - 2-3; 500-999 - 4-6 itd.)
    rate = 1 + (size_x * size_y)/500;
    limit = rand() % 2*rate + 2*rate;
    for (int i = 0; i < limit; ++i) {
        do {
            x = randomX();
            y = randomY();
        } while (getOrganismFromBoard(x, y) != nullptr);
        addOrganism(new Tortoise(x, y, this));
    }

    // Antylopa - 2-4 na 300 pól (0-299 - 2-3; 300-599 - 4-8 itd.)
    rate = 1 + (size_x * size_y)/300;
    limit = rand() % 3*rate + 2*rate;
    for (int i = 0; i < limit; ++i) {
        do {
            x = randomX();
            y = randomY();
        } while (getOrganismFromBoard(x, y) != nullptr);
        addOrganism(new Antelope(x, y, this));
    }

    // Trawa - 2-4 na 100 pól (100-199 - 2-4, 200-299 - 4-8 itd.)
    rate = (size_x * size_y)/100;
    limit = rand() % 3*rate + 2*rate;
    for (int i = 0; i < limit; ++i) {
        do {
            x = randomX();
            y = randomY();
        } while (getOrganismFromBoard(x, y) != nullptr);
        addOrganism(new Grass(x, y, this));
    }

    // Mlecz - 1-2 na 100 pól (100-199 - 1-2, 200-299 - 2-4 itd.)
    rate = (size_x * size_y)/100;
    limit = rand() % 1*rate + 1*rate;
    for (int i = 0; i < limit; ++i) {
        do {
            x = randomX();
            y = randomY();
        } while (getOrganismFromBoard(x, y) != nullptr);
        addOrganism(new Dandelion(x, y, this));
    }

    // Guarana - 1-3 na 500 pól (0-499 - 1-3, 500-999 - 2-6 itd.)
    rate = 1 + (size_x * size_y)/500;
    limit = rand() % 3*rate + 1*rate;
    for (int i = 0; i < limit; ++i) {
        do {
            x = randomX();
            y = randomY();
        } while (getOrganismFromBoard(x, y) != nullptr);
        addOrganism(new Guarana(x, y, this));
    }

    // Wilcza jagoda - 1-2 na 500 pól (0-499 - 1-2, 500-999 - 2-4 itd.)
    rate = 1 + (size_x * size_y)/500;
    limit = rand() % 2*rate + 1*rate;
    for (int i = 0; i < limit; ++i) {
        do {
            x = randomX();
            y = randomY();
        } while (getOrganismFromBoard(x, y) != nullptr);
        addOrganism(new Belladonna(x, y, this));
    }

    // Barszcz Sosnowskiego - 1 na 1000 pól (0-999 - 1, 1000-1999 - 2 itd.)
    rate = 1 + (size_x * size_y)/1000;
    limit = rate;
    for (int i = 0; i < limit; ++i) {
        do {
            x = randomX();
            y = randomY();
        } while (getOrganismFromBoard(x, y) != nullptr);
        addOrganism(new Hogweed(x, y, this));
    }

    /*addOrganism(new Sheep(0,10, this));
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
    addOrganism(new Hogweed(10, 0, this));*/
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
World::World(int x, int y, bool new_board) : size_x(x), size_y(y) {
    renderer = new Renderer(*this);
    board = new Field *[size_x];
    for (int i = 0; i < size_x; ++i) {
        board[i] = new Field[size_y];
    }

    player = nullptr;

    if (new_board) {
        randomOrganisms();
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

Human *World::getPlayer() {
	if (player == nullptr) {
		for (auto & entity : entities) {
			if (entity->getKind() == HUMAN)
				player = dynamic_cast<Human *>(entity);
		}
	}
	return player;
}

int World::getEntititesSize() const {
    return entities.size();
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

        if (i < entities.size()) {
            entities.erase(entities.begin() + i);
        }
        delete org;
    } else {
        org->moveToSafe();
    }
}

void World::makeTurn() {
    // Niepotrzebne odkąd organizmy są dodawane we właściwym  miejscu
    // std::sort(entities.begin(), entities.end(), OrgComp());

    Organism *temp = nullptr;

    renderer->clearMessages();

    for(auto i : entities) {
        i->addOneAge();
        printf("%c ", i->draw());
    }


    int i = -1;
    while (++i < entities.size()) {
        if (entities[i]->getAge() > 0) {
            board[entities[i]->getX()][entities[i]->getY()].setNull();

            temp = entities[i];
            temp->move();

            makeCollision(temp);

            // naprawa indeksu i, jeśli organizmy w wektorze się przesunęły, po czyjejś śmierci
            if (find(entities.begin(), entities.end(), temp) != entities.end()) {   // jeśli temp dalej żyje
                while (i >= entities.size() || entities[i] < temp) {
                    if (i == 0)
                        break;
                    i--;
                }
            } else {    // jeśli temp został zabity
                --i;
            }
        }

    }
}

void World::Serialise(std::fstream &file, bool write) {
    if (write) {
        file.write(reinterpret_cast<const char *>(&size_x), sizeof(size_x));
        file.write(reinterpret_cast<const char *>(&size_y), sizeof(size_y));

        int n = getEntititesSize();
        file.write(reinterpret_cast<const char *>(&n), sizeof(n));

        Kind kind;
        for (int i = 0; i < n; ++i) {
            kind = entities[i]->getKind();
            file.write(reinterpret_cast<const char *>(&kind), sizeof(kind));
            entities[i]->Serialise(file, true);
        }
    }
}

World::~World() {
    for (int i = 0; i < entities.size(); i++) {
        delete entities[i];
    }
    entities.clear();

    for (int i = 0; i < size_x; ++i) {
        delete[] board[i];
    }
    delete[] board;

    delete renderer;
}
