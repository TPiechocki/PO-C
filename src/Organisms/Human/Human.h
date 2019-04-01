//
// Created by Tomasz Piechocki on 30/03/2019.
//

#ifndef PO_C_HUMAN_H
#define PO_C_HUMAN_H

#include <src/Organisms/Animal.h>

class Human : public Animal {

public:
    Human(int x, int y, World* world);

    /**
     * Użytkownik może zmienić kierunek ruchu strzałkami.
     */
    void setDirection(int);

    void collision() override;

    char draw() override;

   ~Human() final;
};


#endif //PO_C_HUMAN_H
