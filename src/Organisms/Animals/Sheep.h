//
// Created by Tomasz Piechocki on 04/04/19.
//

#ifndef PO_C_SHEEP_H
#define PO_C_SHEEP_H

#include <src/Organisms/Animal.h>

class Sheep final : public Animal {
public:
    Sheep(int x, int y, World* world);

    char draw() override;

    std::string getGatunek() override;

    ~Sheep();
};


#endif //PO_C_SHEEP_H
