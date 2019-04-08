//
// Created by Tomasz Piechocki on 30/03/2019.
//

#ifndef PO_C_ANIMAL_H
#define PO_C_ANIMAL_H

#include "Organism.h"

class Animal : public Organism {
protected:
    // Poprzednie koordynaty mogą się przydać przy odbiciu żółwia.
    int previous_x{}, previous_y{};

public:
    Animal(int x, int y, World *world);

    /**
     * Ruch w odpowiednim kierunku
     */
    void move() override;\


    ~Animal() override;
};


#endif //PO_C_ANIMAL_H
