//
// Created by Tomasz Piechocki on 30/03/2019.
//

#ifndef PO_C_ANIMAL_H
#define PO_C_ANIMAL_H

#include "Organism.h"

class Animal : public Organism {
protected:
    // Poprzednie koordynaty mogą się przydać przy odbiciu żółwia.
    int direction{}, previous_x{}, previous_y{};

    /**
     * Wybiera losowy kierunek kolejnego ruchu.
     */
    virtual void randomDirection();
public:
    /**
     * Ruch w odpowiednim kierunku
     */
    void move() override;
};


#endif //PO_C_ANIMAL_H
