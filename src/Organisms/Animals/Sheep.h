//
// Created by Tomasz Piechocki on 04/04/19.
//

#ifndef PO_C_SHEEP_H
#define PO_C_SHEEP_H

#include "../Animal.h"

class Sheep final : public Animal {
protected:
    Organism *createNewInstance(int x, int y, World *world) override;

public:
    Sheep(int x, int y, World* world);

    char draw() override;

    std::string getKindString() override;
};


#endif //PO_C_SHEEP_H
