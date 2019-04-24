//
// Created by Tomasz Piechocki on 08/04/19.
//

#ifndef PO_C_GUARANA_H
#define PO_C_GUARANA_H


#include "../Plant.h"

class Guarana : public Plant {
protected:
    Organism *createNewInstance(int x, int y, World *world) override;

public:
    Guarana(int x, int y, World *world);

    char draw() override;

    std::string getKindString() override;

    bool collision(Organism *attacker) override;
};


#endif //PO_C_GUARANA_H
