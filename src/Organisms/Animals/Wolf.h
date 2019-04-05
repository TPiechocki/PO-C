//
// Created by Tomasz Piechocki on 05/04/19.
//

#ifndef PO_C_WOLF_H
#define PO_C_WOLF_H

#include <src/Organisms/Animal.h>

class Wolf final : public Animal {
public:
    Wolf(int x, int y, World* world);

    char draw() override;

    std::string getGatunek() override;

    ~Wolf();
};


#endif //PO_C_WOLF_H
