//
// Created by Tomasz Piechocki on 08/04/19.
//

#ifndef PO_C_FOX_H
#define PO_C_FOX_H

#include "../Animal.h"

class Fox : public Animal {
protected:
    Organism *createNewInstance(int x, int y, World *world) override;

public:
    Fox(int x, int y, World *world);

    char draw() override;

    std::string getKind() override;

    void move() override;

    ~Fox() override;
};


#endif //PO_C_FOX_H
