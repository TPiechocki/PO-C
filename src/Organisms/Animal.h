//
// Created by Tomasz Piechocki on 30/03/2019.
//

#ifndef PO_C_ANIMAL_H
#define PO_C_ANIMAL_H

#include "Organism.h"

class Animal : public Organism {
public:
    Animal(int x, int y, World *world);

    /**
     * Ruch w odpowiednim kierunku
     */
    void move() override;

    void moveToSafe() override;

    /**
     * Rozmnażanie się organizów tego samego gatunku
     * @return wskaźnik na nowy organizm
     */
    Organism * breed(Animal *) override;

    virtual ~Animal();
};


#endif //PO_C_ANIMAL_H
