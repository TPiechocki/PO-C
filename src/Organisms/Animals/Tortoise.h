//
// Created by Tomasz Piechocki on 14/04/19.
//

#ifndef PO_C_TORTOISE_H
#define PO_C_TORTOISE_H

#include "../Animal.h"

class Tortoise : public Animal {
protected:
    Organism *createNewInstance(int x, int y, World *world) override;

public:
    Tortoise(int x, int y, World *world);

    char draw() override;

    std::string getKindString() override;

    /**
     * Ruch tylko dla 1/4 przypadków.
     */
    void move() override;

    /**
     * Żółw odpiera ataki przeciwników o sile mniejszej niż 5.
     */
    bool collision(Organism *attacker) override;
};


#endif //PO_C_TORTOISE_H
