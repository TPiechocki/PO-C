//
// Created by Tomasz Piechocki on 28/03/19.
//

#ifndef PO_C_WORLD_H
#define PO_C_WORLD_H

#include <vector>

#include "Field.h"
#include "src/Organisms/Organism.h"
#include "src/Renderer/Renderer.h"

class Field;
class Organism;
class Renderer;


class World {
private:
    int size_x, size_y;

    Field** board;

    std::vector<Organism*> entities;

    /**
     * Renderer wyświetlający świat oraz powiadomienia
     */
    Renderer* renderer;
public:
    World(int x, int y);

    int getSizeX() const;

    int getSizeY() const;

    Renderer *getRenderer() const;

    void newMessage(const std::string&);

    /**
     * Na potrzebę kolizji.
     * @return Wskaźnik do organizmu znajdującego się na polu (x,y)
     */
    Organism *getOrganism(int x, int y);

    /**
     * @return znak reprezuntujący organizm na polu (x,y)
     */
    char getFieldChar(int x, int y);

    /**
     * Dodanie organismu do wektora wszystkich organizmów w odpowiednie miejsce
     */
    void addOrganism(Organism *);

    void removeOrganism(Organism *);

    /**
     * Wykonanie tury
     */
    void makeTurn();

    ~World();
};

#endif //PO_C_WORLD_H