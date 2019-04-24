//
// Created by Tomasz Piechocki on 05/04/19.
//

#ifndef PO_C_WOLF_H
#define PO_C_WOLF_H

#include "../Animal.h"

class Wolf final : public Animal {
protected:
    Organism *createNewInstance(int x, int y, World *world) override;

public:
    Wolf(int x, int y, World* world);

    char draw() override;

    std::string getKindString() override;
};


#endif //PO_C_WOLF_H
