//
// Created by Tomek on 23/04/2019.
//

#include "File.h"

#include "../World/World.h"

#include <iostream>
#include <fstream>

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

File::File() {
    types[HUMAN] = new Human(0, 0, nullptr);
    types[SHEEP] = new Sheep(0, 0, nullptr);
    types[WOLF] = new Wolf(0, 0, nullptr);
    types[FOX] = new Fox(0, 0, nullptr);
    types[ANTELOPE] = new Antelope(0, 0, nullptr);
    types[TORTOISE] = new Tortoise(0, 0, nullptr);
    types[GRASS] = new Grass(0, 0, nullptr);;
    types[DANDELION] = new Dandelion(0, 0, nullptr);
    types[GUARANA] = new Guarana(0, 0, nullptr);;
    types[BELLADONNA] = new Belladonna(0, 0, nullptr);;
    types[HOGWEED] = new Hogweed(0, 0, nullptr);;
}

void File::save(World *world) {
    string file_name;
    cout << endl << "Podaj nazwe zapisu: " << endl;
    cin >> file_name;

    fstream file(file_name, ios::binary | ios::out | ios::trunc);

    world->Serialise(file, true);
}

World *File::read() {
    World *world = nullptr;

    string file_name;
    cout << endl << "Podaj nazwe zapisu: " << endl;
    cin >> file_name;

    fstream file(file_name, ios::in | ios::binary);

    if (!(file.fail())) {
        // Wielkość świata
        int size_x, size_y;
        file.read(reinterpret_cast<char *>(&size_x), sizeof(size_x));
        file.read(reinterpret_cast<char *>(&size_y), sizeof(size_y));
        world = new World(size_x, size_y, false);

        int n;  // ilość organizmów
        Organism *temp;
        Kind type;      // gatunek organizmu
        file.read(reinterpret_cast<char *>(&n), sizeof(n));
        for (int i = 0; i < n; ++i) {
            file.read(reinterpret_cast<char *>(&type), sizeof(type));
            // wywołanie konstruktora odpowiedniego gatunku
            temp = types.find(type)->second;
			temp = temp->createNewInstance(0, 0, world);

            // odczytanie właściwości obiektu i ich przypisanie
            temp->Serialise(file, false);
            
            // dodanie organizmu do świata
            world->addOrganism(temp);
        }
    } else {
        cout << "Niepoprawny plik! Sprobuj ponownie." << endl;
    }

    return world;
}

File::~File() {
    Organism *temp;
    while (!(types.empty())) {
        temp = types.begin()->second;
        types.erase(types.begin());
        delete temp;
    }
};
