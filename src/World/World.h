//
// Created by Tomasz Piechocki on 28/03/19.
//

#ifndef PO_C_WORLD_H
#define PO_C_WORLD_H

#include <vector>

#include "Field.h"
#include "../Organisms/Organism.h"
#include "../Renderer/Renderer.h"



class Field;
class Organism;
class Renderer;
class Human;


class World {
private:
    int size_x, size_y;

    Field** board;

    std::vector<Organism *> entities;

    Human *player;

    void randomOrganisms();

    /**
     * Renderer wyświetlający świat oraz powiadomienia
     */
    Renderer* renderer;
protected:
    /**
     * Sprawdza czy pole na którym wylądował organizm jest pełny, jeśli tak to wykonuję odpowiednią kolizję
     * @return true - jeśli elementy w wektorze od co najmniej badanego organizmu się przesunęły w stronę początku
     */
    bool makeCollision(Organism *);
public:
    World(int x, int y);

    int getSizeX() const;

    int getSizeY() const;

    Renderer *getRenderer() const;

    Human *getPlayer() const;

    void newMessage(const std::string&);

    void newPriorityMessage(const std::string&);

    /**
     * Na potrzebę kolizji.
     * @return Wskaźnik do organizmu znajdującego się na polu (x,y)
     */
    Organism *getOrganismFromBoard(int x, int y);

    void setOrganismOnBoard(Organism *org);

    /**
     * @return znak reprezuntujący organizm na polu (x,y)
     */
    char getFieldChar(int x, int y);

    /**
     * Dodanie organismu do wektora wszystkich organizmów w odpowiednie miejsce
     */
    void addOrganism(Organism *);

    /**
     * Usunięcie organizmu z wektora wszystkich organizmów
     */
    void removeOrganism(Organism *);

    /**
     * Wykonanie tury
     */
    void makeTurn();

    ~World();
};

#endif //PO_C_WORLD_H