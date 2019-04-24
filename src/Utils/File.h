//
// Created by Tomek on 23/04/2019.
//

#ifndef PO_C_FILE_H
#define PO_C_FILE_H

#include <map>

#include "../Organisms/Organism.h"

class World;

class File {
private:
    // Zbiór przykładowych obiektów wszystkich gatunków.
    // Dzięki niemu możliwe jest tworzenie obiektów różnych gatunków..
    std::map < Kind, Organism * > types;
public:
    File();

    void save(World *world);

    World *read();

    ~File();
};


#endif //PO_C_FILE_H
