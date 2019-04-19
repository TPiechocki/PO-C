//
// Created by Tomek on 17/04/2019.
//

#ifndef PO_C_HOGWEED_H
#define PO_C_HOGWEED_H

#include "../Plant.h"

class Hogweed : public Plant {
private:
    void killNeighbour(Organism *);

protected:
    Organism *createNewInstance(int x, int y, World *world) override;

public:
    Hogweed(int x, int y, World *world);

    char draw() override;

    std::string getKindString() override;

    void move() override;

    bool collision(Organism *attacker) override;

    ~Hogweed() override;
};


#endif //PO_C_HOGWEED_H
