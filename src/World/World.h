//
// Created by Tomasz Piechocki on 28/03/19.
//

#ifndef PO_C_WORLD_H
#define PO_C_WORLD_H

#include "Field.h"
#include "../Organisms/Organism.h"

#include <vector>
#include <src/Renderer/Renderer.h>

class Field;
class Organism;
class Renderer;

class World {
private:
    int size_x, size_y;

    Field** board;

    std::vector<Organism*> entities;
public:
    /**
     * Renderer for displaying notifications
     */
    Renderer* renderer;

    World(int x, int y);

    int getSizeX() const;

    int getSizeY() const;

    /**
     * @return char for the field of (x,y) coordinates
     */
    char getFieldChar(int x, int y);

    /**
     * Add organism to vector entities
     */
    void addOrganism(Organism *);

    /**
     * Move all organisms
     */
    void makeTurn();

    ~World();
};

#endif //PO_C_WORLD_H