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

#include "../World/World.h"

class World;
class Animal;

enum Kind {
    HUMAN, SHEEP, WOLF, GRASS, DANDELION
};

class Organism {
protected:
    int strength{}, initiative{}, x_coord, y_coord, age, direction;

    Kind kind{};

    World *world;

    virtual Organism * createNewInstance(int x, int y, World *world) = 0;

    virtual void randomDirection();

public:
    Organism(int x, int y, World *world);

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

    int getInitiative() const;

    int getAge() const;

    int getStrength() const;

    Kind getKind() {
        return kind;
    };

    /**
     * Zmiana wieku o 1 w góre, wywołane dla każdego w każdej turze.
     */
    void addOneAge();

    /**
    * Change organism strange by int value.
    */
    void changeStrength(int);

    /**
     * Kolizja z innym organizmem
     * @param attacker - atakujący
     * @return - prawda jeśli zabity został poruszający się organizm lub zabity organizm był wcześniej już ruszony
     *      Wtedy wszystkie eleementy wektora się przesuwają, więc trzbea zmniejszyć inedks pętli tury.
     */
    virtual bool collision(Organism *attacker);

    virtual Organism *breed(Animal *);

    /**
     * @return Zwraca znak charakterystyczny dla gatunku
     */
    virtual char draw() = 0;

    virtual std::string getKindString() = 0;

    bool operator<(const Organism &rhs) const;

    bool operator>(const Organism &rhs) const;

    bool operator<=(const Organism &rhs) const;

    bool operator>=(const Organism &rhs) const;

    virtual ~Organism();
};


#endif //PO_C_ORGANISM_H
