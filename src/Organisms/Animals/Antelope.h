//
// Created by Tomasz Piechocki on 14/04/19.
//

#ifndef PO_C_ANTELOPE_H
#define PO_C_ANTELOPE_H


#include "../Animal.h"

class Antelope : public Animal {
protected:
    Organism *createNewInstance(int x, int y, World *world) override;

public:
    Antelope(int x, int y, World *world);

    char draw() override;

    std::string getKindString() override;

    /**
     * Zasięg ruchu jest równy 2 zamiast 1.
     */
    void move() override;

    /**
     * Antylopa ma 50% szans na ucieczkę
     */
    bool collision(Organism *attacker) override;
};


#endif //PO_C_ANTELOPE_H
