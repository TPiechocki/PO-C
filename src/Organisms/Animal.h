//
// Created by Tomasz Piechocki on 30/03/2019.
//

#ifndef PO_C_ANIMAL_H
#define PO_C_ANIMAL_H

#include "Organism.h"

class Animal : public Organism {
protected:
    int direction;
public:
    void move() override;

    ~Animal() override;
};


#endif //PO_C_ANIMAL_H
