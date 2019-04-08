//
// Created by Tomasz Piechocki on 08/04/19.
//

#ifndef PO_C_DANDELION_H
#define PO_C_DANDELION_H

#include "../Plant.h"

/**
 * Mlecz
 */
class Dandelion : public Plant {
protected:
    Plant *createNewInstance(int x, int y, World *world) override;

public:
    Dandelion(int x, int y, World *world);

    char draw() override;

    std::string getKind() override;

    /**
     * Mlecz próbuje się rozprzestrzenić trzykrotnie
     */
    void move() override;

    ~Dandelion() override;
};


#endif //PO_C_DANDELION_H
