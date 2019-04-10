//
// Created by Tomasz Piechocki on 30/03/2019.
//

#ifndef PO_C_HUMAN_H
#define PO_C_HUMAN_H

#include "../Animal.h"

class Human final : public Animal {
protected:
    void randomDirection() override;

    Organism *createNewInstance(int x, int y, World *world) override;

public:
    Human(int x, int y, World* world);

    /**
     * Użytkownik może zmienić kierunek ruchu strzałkami.
     */
    void setDirection(int);

    char draw() override;

    std::string getKindString() override;

    ~Human() override;
};


#endif //PO_C_HUMAN_H
