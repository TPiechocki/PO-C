//
// Created by Tomasz Piechocki on 30/03/2019.
//

#ifndef PO_C_ORGANISM_H
#define PO_C_ORGANISM_H

#ifdef __linux__
    #include <caca_conio.h>
    #define KEY_UP CACA_KEY_UP
    #define KEY_DOWN CACA_KEY_DOWN
    #define KEY_LEFT CACA_KEY_LEFT
    #define KEY_RIGHT CACA_KEY_RIGHT
#else
    #include <conio.h>
    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_LEFT 75
    #define KEY_RIGHT 77
#endif

#include "src/World/World.h"

class World;

enum Kind {SHEEP, WOLF, HUMAN};

class Organism {
protected:
    int strength{}, initiative{}, x_coord{}, y_coord{}, age{}, vector_pos{};

    Kind kind{};

    World* world{};

public:
    /**
     * Wykonanie ruchu
     */
    virtual void move() = 0;

    /**
     * @return aktualna pozycja x
     */
    int getX() const;

    /**
     * @return aktualna pozycja y
     */
    int getY() const;

    int getVectorPos() const;

    int getInitiative() const;

    int getAge() const;

    /**
     * Zmiana wieku o 1 w góre, wywołane dla każdego w każdej turze.
     */
    void addOneAge();

    /**
     * Kolizja z innym organizmem
     * @param other - atakujący
     * @return - zwyciężca
     */
    virtual Organism *collision(Organism* other);

    /**
     * @return Zwraca znak charakterystyczny dla gatunku
     */
    virtual char draw() = 0;

    virtual std::string getGatunek() = 0;
};


#endif //PO_C_ORGANISM_H
