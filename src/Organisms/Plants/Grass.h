//
// Created by Tomasz Piechocki on 07/04/19.
//

#ifndef PO_C_GRASS_H
#define PO_C_GRASS_H


#include "../Plant.h"

class Grass : public Plant {
protected:
    Plant *createNewInstance(int x, int y, World *world) override;

public:
    Grass(int x, int y, World *world);

    char draw() override;

    std::string getKindString() override;
};

#endif //PO_C_GRASS_H
